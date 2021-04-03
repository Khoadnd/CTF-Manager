#include "CTFEvent.h"
#include <iostream>
#include <string.h>

using namespace std;

CTFEvent::CTFEvent()
{
	strcpy_s(cTenCuocThi, "");
	strcpy_s(cTenNhaToChuc, "");
	dNgayToChuc.setDate();
	ulTriGiaGiaiThuong = 0;
}

CTFEvent::~CTFEvent()
{
	
}

void CTFEvent::display()
{
	cout << "Ten cuoc thi: ";
	puts(this->cTenCuocThi);
	cout << "Nha to chuc: ";
	puts(this->cTenNhaToChuc);
	cout << "Ngay dien ra: ";
	this->dNgayToChuc.xuat();
	cout << "Giai thuong: " << this->ulTriGiaGiaiThuong << endl;
}

void CTFEvent::setEvent(char* initTenCuocThi, char* initTenNhaToChuc, Date initDate, unsigned long initTriGiaGiaiThuong)
{
	this->setTenCuocThi(initTenCuocThi);
	this->setTenNhaToChuc(initTenNhaToChuc);
	this->setNgayToChuc(initDate);
	this->setTriGiaGiaiThuong(initTriGiaGiaiThuong);
}

void CTFEvent::initEvent()
{
	char initTenCuocThi[100], initTenNhaToChuc[100];
	Date initNgayToChuc;
	unsigned long initTriGia;
	cout << "Nhap ten cuoc thi: ";
	cin.getline(initTenCuocThi, 100);
	cout << "Nhap ten nha to chuc: ";
	cin.getline(initTenNhaToChuc, 100);
	cout << "Nhap ngay to chuc:\n";
	initNgayToChuc.nhap();
	
	do
	{
		cout << "Nhap tri gia giai thuong: ";
		cin >> initTriGia;
	} while (!this->setTriGiaGiaiThuong(initTriGia));
	this->setEvent(initTenCuocThi, initTenNhaToChuc, initNgayToChuc, initTriGia);
}

bool CTFEvent::setTenCuocThi(char* initTenCuocThi)
{
	if (strcmp(initTenCuocThi, "") == 0)
		return 0;

	strcpy_s(this->cTenCuocThi, initTenCuocThi);
	return 1;
}

bool CTFEvent::setTenNhaToChuc(char* initTenNhaToChuc)
{
	if (strcmp(initTenNhaToChuc, "") == 0)
		return 0;

	strcpy_s(this->cTenNhaToChuc, initTenNhaToChuc);
	return 1;
}

bool CTFEvent::setNgayToChuc(Date initDate)
{
	if (!this->dNgayToChuc.setDate(initDate))
		return 0;
	return 1;
}

bool CTFEvent::setTriGiaGiaiThuong(unsigned long initTriGiaGiaiThuong)
{
	if (initTriGiaGiaiThuong < 0)
		return 0;

	this->ulTriGiaGiaiThuong = initTriGiaGiaiThuong;
	return 1;
}