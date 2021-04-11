#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int initNgay, int initThang, int initNam)
{
	this->iNgay = initNgay;
	this->iThang = initThang;
	this->iNam = initNam;
}

Date::~Date()
{

}

bool Date::setNgay(int initDay)
{
	if (initDay > 31 || initDay < 0)
		return 0;

	this->iNgay = initDay;

	return 1;
}

bool Date::setThang(int initThang)
{
	if (initThang > 12 || initThang < 0)
		return 0;

	this->iThang = initThang;

	return 1;
}

bool Date::setNam(int initNam)
{
	if (initNam < 0)
		return 0;

	this->iNam = initNam;

	return 1;
}



bool Date::setDate(Date initDate)
{
	bool bSuccess = 1;

	if (!this->setNgay(initDate.iNgay))
		bSuccess = 0;

	if (!this->setThang(initDate.iThang))
		bSuccess = 0;

	if (!this->setNam(initDate.iNam))
		bSuccess = 0;

	return bSuccess;
}

void Date::xuat()
{
	cout << this->iNgay << '/' << this->iThang << '/' << this->iNam << endl;
}

bool Date::isLeap(int year)
{
	if (year % 400 == 0)
		return 1;

	if ((year % 4 == 0) && (year % 100 != 0))
		return 1;

	return 0;
}

bool Date::isLegit(Date date)
{
	int iDayLookUp[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap(date.iNam))
	{
		iDayLookUp[1] = 29;
	}

	if (date.iNgay > iDayLookUp[date.iThang - 1])
		return 0;

	return 1;
}

void Date::nhap()
{
	int initNgay, initThang, initNam;

	do
	{
		do
		{
			cout << "Nhap ngay: ";
			cin >> initNgay;
		} while (!this->setNgay(initNgay));

		do
		{
			cout << "Nhap thang: ";
			cin >> initThang;
		} while (!this->setThang(initThang));

		do
		{
			cout << "Nhap nam: ";
			cin >> initNam;
		} while (!this->setNam(initNam));
	} while (!isLegit(*this));
	
}
