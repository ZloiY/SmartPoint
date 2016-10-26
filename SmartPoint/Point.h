#pragma once
#include <windows.h> 
class Point
{
public:
	struct Values
	{
		double x, y;
	};
	typedef Values* pValues;
	Point();
	Point(double x, double y);
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	void sendStruct();
	void getStruct();
	~Point();
private:
	HANDLE hMapFile;
	TCHAR szName[26] = TEXT("Global\MyFileMappingObject");
	LPCTSTR pBuf;
	pValues val;
	CRITICAL_SECTION cs;
};

