#include "CTFEvent.h"
#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

CTFEvent::CTFEvent()
{
	strcpy_s(cTenCuocThi, "");
	strcpy_s(cTenNhaToChuc, "");
	strcpy_s(cFormat, "");
	dNgayToChuc.setDate();
	ulTriGiaGiaiThuong = 0;
	started = 0;
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
	cout << "Format: ";
	puts(this->cFormat);
}

void CTFEvent::setEvent(char* initTenCuocThi, char* initTenNhaToChuc, Date initDate, unsigned long initTriGiaGiaiThuong, char* initFormat)
{
	this->setTenCuocThi(initTenCuocThi);
	this->setTenNhaToChuc(initTenNhaToChuc);
	this->setNgayToChuc(initDate);
	this->setTriGiaGiaiThuong(initTriGiaGiaiThuong);
	this->setFormat(initFormat);
}

bool CTFEvent::isFormat(char* Format)
{
	char t1[] = "Jeopardy";
	char t2[] = "Attack-Defense";
	if (strcmp(Format, t1) == 0 || strcmp(Format, t2) == 0)
		return 1;
	return 0;
}

void CTFEvent::initEvent()
{
	char initTenCuocThi[100], initTenNhaToChuc[100], initFormat[15];
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

	cin.ignore();

	do
	{
		cout << "Nhap format: ";
		cin.getline(initFormat, 15);
	} while (!this->isFormat(initFormat));

	this->setEvent(initTenCuocThi, initTenNhaToChuc, initNgayToChuc, initTriGia, initFormat);
}

bool CTFEvent::setTenCuocThi(char* initTenCuocThi)
{
	if (strcmp(initTenCuocThi, "") == 0)
		return 0;

	strcpy_s(this->cTenCuocThi, initTenCuocThi);
	return 1;
}

void CTFEvent::setFormat(char* initFormat)
{
	while (!this->isFormat(initFormat))
	{
		cout << "Format khong hop le, vui long nhap lai." << endl;
		cout << "Format: ";
		cin.getline(initFormat, 15);
	}

	strcpy_s(this->cFormat, initFormat);
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

void CTFEvent::addDoiThi()
{
	this->ldtListDoiThi.nhapDoiThi();
}

void CTFEvent::xuatDoiThi()
{
	this->ldtListDoiThi.xuatDoiThi();
}

bool CTFEvent::isXRegistered(char* tenDoi)
{
	return this->ldtListDoiThi.isDoiExist(tenDoi);
}

void CTFEvent::xuatTop3()
{
	if (this->isListDoiThiEmpty())
	{
		cout << "Chua co doi tham gia!\n";
		return;
	}

	int soLuong = this->ldtListDoiThi.getSoLuongDoiThi();

	if (soLuong < 3)
	{
		if (soLuong == 1)
		{
			cout << "Top 1:\n";
			this->xuatDoiThi();

			return;
		}

		if (soLuong == 2)
		{
			this->ldtListDoiThi.sortDiem();

			this->xuatDoiThi();
			return;
		}
	}

	this->ldtListDoiThi.sortDiem();
	this->ldtListDoiThi.xuatDoiThi(4);
}

int CTFEvent::getSoLuongDoiThamGia()
{
	return this->ldtListDoiThi.getSoLuongDoiThi();
}

bool CTFEvent::isListDoiThiEmpty()
{
	if (this->ldtListDoiThi.isEmpty())
		return 1;
	return 0;
}

void CTFEvent::setDiemChoDoi(char* tenDoi, unsigned int diem)
{
	if (this->isXRegistered(tenDoi))
		this->ldtListDoiThi.setDiem(tenDoi, diem);
	else
		cout << "Doi chua dang ky!";
}

char* CTFEvent::getPassword(char* tenDoi)
{
	if (this->isXRegistered(tenDoi))
		return this->ldtListDoiThi.getPassword(tenDoi);
	else
		return NULL;
}

bool CTFEvent::isMemberRegistered(NodeDoiThi* doiThi, char* tenThanhVien)
{
	return isMemberExistInNode(doiThi, tenThanhVien);
}

NodeDoiThi* CTFEvent::getDoiThiTrongList(char* tenDoi)
{
	return this->ldtListDoiThi.getDoiThi(tenDoi);
}

void CTFEvent::xuatTenDoiThi()
{
	this->ldtListDoiThi.xuatTenDoi();
}

void CTFEvent::removeDoi(char* tenDoi)
{
	this->ldtListDoiThi.removeDoi(tenDoi);
}

bool CTFEvent::isStarted()
{
	return this->started;
}

void CTFEvent::start()
{
	if (this->isListDoiThiEmpty())
	{
		cout << "Chua co doi tham gia!";
		return;
	}

	while (this->started == 1)
	{
		this->ldtListDoiThi.randomDiem();
		Sleep(2000);
	}
}

void CTFEvent::stop()
{
	this->started = 0;
}

void CTFEvent::setStarted(bool state)
{
	this->started = state;
}