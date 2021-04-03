#include "ListDoiThi.h"
#include <iostream>
#include <string.h>

using namespace std;

ListDoiThi::ListDoiThi()
{
	this->listDoi.pHead = NULL;
	this->listDoi.pTail = NULL;
}

ListDoiThi::~ListDoiThi()
{
	
}

ListThanhVien::ListThanhVien()
{
	this->ltvListThanhVien.pHead = NULL;
	this->ltvListThanhVien.pTail = NULL;
}

ListThanhVien::~ListThanhVien()
{

}

void ListDoiThi::nhapListDoiThi()
{
	//????? what to do wtf? Is this really neccessary? WTF
}

void ListThanhVien::addTailThanhVien(NodeThanhVien* p)
{
	if (this->ltvListThanhVien.pHead == NULL)
	{
		this->ltvListThanhVien.pHead = p;
		this->ltvListThanhVien.pTail = p;
	}
	else
	{
		this->ltvListThanhVien.pTail->pNext = p;
		this->ltvListThanhVien.pTail = p;
	}
}

void ListThanhVien::nhapListThanhVien()
{
	char initThanhVien[100];

	int i = 1;

	while (1)
	{
		cout << "Nhap ten thanh vien thu " << i++ << " (0 de ket thuc): ";
		cin.getline(initThanhVien, 100);

		if (strcmp(initThanhVien, "0") == 0)
			break;

		NodeThanhVien* p = this->createNodeThanhVien(initThanhVien);
		this->addTailThanhVien(p);
	}
}

NodeDoiThi* ListDoiThi::createNodeDoiThi(char* initTenDoiThi, char* initTenDoiTruong, char *initPassword, ListThanhVien initListThanhVien)
{
	NodeDoiThi* p = new NodeDoiThi;
	strcpy_s(p->cTenDoiThi, initTenDoiThi);
	strcpy_s(p->cTenDoiTruong, initTenDoiTruong);
	strcpy_s(p->cPassDoiTruong, initPassword);
	p->ltvThanhVien = initListThanhVien;
	p->pNext = NULL;
	return p;
}

void ListDoiThi::nhapDoiThi()
{
	char initTenDoiThi[100], initTenDoiTruong[100], initPassword[100];
	ListThanhVien initListThanhVien;

	cout << "Nhap ten doi thi: ";
	cin.getline(initTenDoiThi, 100);
	cout << "Nhap ten doi truong: ";
	cin.getline(initTenDoiTruong, 100);
	cout << "Nhap password: ";
	cin.getline(initPassword, 100);
	initListThanhVien.nhapListThanhVien();

	this->addTailDoiThi(this->createNodeDoiThi(initTenDoiThi, initTenDoiTruong, initPassword, initListThanhVien));
}

NodeThanhVien* ListThanhVien::createNodeThanhVien(char* tenThanhVien)
{
	NodeThanhVien* p = new NodeThanhVien;

	strcpy_s(p->cTenThanhVien, tenThanhVien);
	p->pNext = NULL;

	return p;
}

void ListDoiThi::addTailDoiThi(NodeDoiThi* p)
{
	if (this->listDoi.pHead == NULL)
	{
		this->listDoi.pHead = p;
		this->listDoi.pTail = p;
	}
	else
	{
		this->listDoi.pTail->pNext = p;
		this->listDoi.pTail = p;
	}
}

void ListThanhVien::xuatThanhVien()
{
	NodeThanhVien* p = this->ltvListThanhVien.pHead;

	int i = 1;

	while (p != NULL)
	{
		cout << "Thanh vien thu " << i++ << ": ";
		puts(p->cTenThanhVien);
		p = p->pNext;
	}
}

void ListDoiThi::xuatDoiThi()
{
	NodeDoiThi* p = this->listDoi.pHead;

	int i = 1;

	while (p != NULL)
	{
		cout << "Doi thu " << i++ << ":\n";
		cout << "Ten doi: ";
		puts(p->cTenDoiThi);
		cout << "Doi truong: ";
		puts(p->cTenDoiTruong);
		cout << "Cac thanh vien trong nhom:\n";
		p->ltvThanhVien.xuatThanhVien();

		p = p->pNext;
	}
}

int ListDoiThi::getSoLuongDoiThi()
{
	NodeDoiThi* p = this->listDoi.pHead;

	int soLuong = 0;

	while (p != NULL)
	{
		soLuong++;
		p = p->pNext;
	}

	return soLuong;
}

bool ListDoiThi::isDoiExist(char* tenDoi)
{
	NodeDoiThi* p = this->listDoi.pHead;

	while (p != NULL)
	{
		if (strcmp(p->cTenDoiThi, tenDoi) == 0)
			return 1;

		p = p->pNext;
	}

	return 0;
}

bool ListDoiThi::isEmpty()
{
	if (this->listDoi.pHead == NULL)
		return 1;

	return 0;
}