#include "Point.h"
#define BUF_SIZE sizeof(Values)
using namespace std;

Point::Point()
{
	val = new Values;
	val->x = 0.0;
	val->y = 0.0;
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		szName);
	hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,
		FALSE,
		szName);
}

Point::Point(double x, double y)
{
	val = new Values;
	val->x = x;
	val->y = y;
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		szName);
	hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,
		FALSE,
		szName);
}

void Point::setX(double x) {
	val->x = x;
}

void Point::setY(double y) {
	val->y = y;
}

void Point::sendStruct()
{
	pBuf = (LPTSTR)MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		BUF_SIZE);
	CopyMemory((PVOID)pBuf, val, sizeof(Values));
	UnmapViewOfFile(pBuf);

}

void Point::getStruct()
{
	pBuf = (LPTSTR)MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		BUF_SIZE);
	CopyMemory(val, (PVOID)pBuf, sizeof(Values));
	UnmapViewOfFile(pBuf);

}

double Point::getX() {
	return val->x;
}

double Point::getY() {
	return val->y;
}

Point::~Point()
{
	CloseHandle(hMapFile);
	delete val;
}
