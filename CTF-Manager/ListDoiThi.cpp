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
	delete this->listDoi.pHead;
	delete this->listDoi.pTail;
}

ListThanhVien::ListThanhVien()
{
	this->ltvListThanhVien.pHead = NULL;
	this->ltvListThanhVien.pTail = NULL;
}

ListThanhVien::~ListThanhVien()
{
	delete this->ltvListThanhVien.pHead;
	delete this->ltvListThanhVien.pTail;
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

	while (1)
	{
		cout << "Nhap ten thanh vien thu " << i << " (0 de ket thuc): ";
		cin.getline(initThanhVien, 100);

		if (strcmp(initThanhVien, "0") == 0)
			break;

		NodeThanhVien* p = this->createNodeThanhVien(initThanhVien);
		this->addTailThanhVien(p);
	}
}

NodeDoiThi* ListDoiThi::createNodeDoiThi(char* initTenDoiThi, char* initTenDoiTruong, ListThanhVien* initListThanhVien)
{
	NodeDoiThi* p = new NodeDoiThi;
	strcpy_s(p->cTenDoiThi, initTenDoiThi);
	strcpy_s(p->cTenDoiTruong, initTenDoiTruong);
	p->ltvThanhVien = initListThanhVien;
	p->pNext = NULL;
	return p;
}

void ListDoiThi::nhapDoiThi()
{
	char initTenDoiThi[100], initTenDoiTruong[100];
	ListThanhVien* initListThanhVien;

	cout << "Nhap ten doi thi: ";
	cin.getline(initTenDoiThi, 100);
	cout << "Nhap ten doi truong: ";
	cin.getline(initTenDoiTruong, 100);
	initListThanhVien->nhapListThanhVien();

	this->addTailDoiThi(this->createNodeDoiThi(initTenDoiThi, initTenDoiTruong, initListThanhVien));
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