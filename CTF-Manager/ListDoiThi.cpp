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
		do
		{
			cout << "Nhap ten thanh vien thu " << i << " (0 de ket thuc): ";
			cin.getline(initThanhVien, 100);
		} while (strcmp(initThanhVien, "") == 0);

		if (strcmp(initThanhVien, "0") == 0)
			break;

		NodeThanhVien* p = this->createNodeThanhVien(initThanhVien);
		this->addTailThanhVien(p);

		i++;
	}
}

NodeDoiThi* ListDoiThi::createNodeDoiThi(char* initTenDoiThi, char* initTenDoiTruong, char *initPassword, ListThanhVien initListThanhVien)
{
	NodeDoiThi* p = new NodeDoiThi;
	strcpy_s(p->cTenDoiThi, initTenDoiThi);
	strcpy_s(p->cTenDoiTruong, initTenDoiTruong);
	strcpy_s(p->cPassDoiTruong, initPassword);
	p->ltvThanhVien = initListThanhVien;
	p->diem = 0;
	p->pNext = NULL;
	return p;
}

void ListDoiThi::nhapDoiThi()
{
	char initTenDoiThi[100], initTenDoiTruong[100], initPassword[100];
	ListThanhVien initListThanhVien;

	do
	{
		cout << "Nhap ten doi thi: ";
		cin.getline(initTenDoiThi, 100);
	} while (strcmp(initTenDoiThi, "") == 0);

	do
	{
		cout << "Nhap ten doi truong: ";
		cin.getline(initTenDoiTruong, 100);
	} while (strcmp(initTenDoiTruong, "") == 0);

	do
	{
		cout << "Nhap password: ";
		cin.getline(initPassword, 100);
	} while (strcmp(initPassword, "") == 0);

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

void ListDoiThi::xuatDoiThi(int d)
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
		cout << "Diem: " << p->diem << endl;
		cout << "Cac thanh vien trong nhom:\n";
		p->ltvThanhVien.xuatThanhVien();

		p = p->pNext;
		if (i == d)
			break;
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
	NodeDoiThi* p = this->getDoiThi(tenDoi);

	if (p == NULL)
		return 0;

	return 1;
}

bool ListDoiThi::isEmpty()
{
	if (this->listDoi.pHead == NULL)
		return 1;

	return 0;
}

void ListDoiThi::swap(NodeDoiThi*& p, NodeDoiThi*& q)
{
	NodeDoiThi* t = this->createNodeDoiThi(p->cTenDoiThi, p->cTenDoiTruong, p->cPassDoiTruong, p->ltvThanhVien);
	t->diem = p->diem;
	strcpy_s(p->cTenDoiThi, q->cTenDoiThi);
	strcpy_s(p->cTenDoiTruong, q->cTenDoiTruong);
	strcpy_s(p->cPassDoiTruong, q->cPassDoiTruong);
	p->diem = q->diem;
	p->ltvThanhVien = q->ltvThanhVien;

	strcpy_s(q->cTenDoiThi, t->cTenDoiThi);
	strcpy_s(q->cTenDoiTruong, t->cTenDoiTruong);
	strcpy_s(q->cPassDoiTruong, t->cPassDoiTruong);
	q->diem = t->diem;
	q->ltvThanhVien = t->ltvThanhVien;	
}

void ListDoiThi::sortDiem()
{
	for (NodeDoiThi* p = this->listDoi.pHead; p != this->listDoi.pTail; p = p->pNext)
	{
		NodeDoiThi* max = p;
		for (NodeDoiThi* q = p->pNext; q != NULL; q = q->pNext)
			if (q->diem > max->diem)
				max = q;
		this->swap(max, p);
	}
}

NodeDoiThi* ListDoiThi::getDoiThi(char* tenDoi)
{
	NodeDoiThi* p = this->listDoi.pHead;

	while (p != NULL)
	{
		if (strcmp(p->cTenDoiThi, tenDoi) == 0)
			return p;
		p = p->pNext;
	}
	return NULL;
}

void ListDoiThi::setDiem(char* tenDoi, unsigned int diem)
{
	NodeDoiThi* p = this->getDoiThi(tenDoi);

	p->diem = diem;
}

char* ListDoiThi::getPassword(char* tenDoi)
{
	NodeDoiThi* p = this->getDoiThi(tenDoi);

	return p->cPassDoiTruong;
}

bool ListThanhVien::isMemberExist(char* tenThanhVien)
{
	NodeThanhVien* p = this->ltvListThanhVien.pHead;

	while (p != NULL)
	{
		if (strcmp(p->cTenThanhVien, tenThanhVien) == 0)
			return 1;
		p = p->pNext;
	}

	return 0;
}

bool isMemberExistInNode(NodeDoiThi* doiThi, char* tenThanhVien)
{
	return doiThi->ltvThanhVien.isMemberExist(tenThanhVien);
}

void ListThanhVien::removeThanhVien(char* tenThanhVien)
{
	NodeThanhVien* p = this->ltvListThanhVien.pHead;
	NodeThanhVien* bp = NULL;

	while (p != NULL)
	{
		if (strcmp(p->cTenThanhVien, tenThanhVien) == 0)
		{
			if (this->ltvListThanhVien.pHead == p)
			{
				this->ltvListThanhVien.pHead = p->pNext;
				delete p;
				break;
			}

			bp->pNext = p->pNext;
			if (this->ltvListThanhVien.pTail == p)
				this->ltvListThanhVien.pTail = bp;
			delete p;
			break;
		}

		bp = p;
		p = p->pNext;
	}
}

void ListDoiThi::xuatTenDoi()
{
	NodeDoiThi* p = this->listDoi.pHead;

	while (p != NULL)
	{
		cout << p->cTenDoiThi << '\t';
		p = p->pNext;
	}
}

void ListDoiThi::removeDoi(char* tenDoi)
{
	NodeDoiThi* p = this->listDoi.pHead;
	NodeDoiThi* bp = NULL;

	while (p != NULL)
	{
		if (strcmp(p->cTenDoiThi, tenDoi) == 0)
		{
			if (this->listDoi.pHead == p)
			{
				this->listDoi.pHead = p->pNext;
				delete p;
				break;
			}

			bp->pNext = p->pNext;
			if (this->listDoi.pTail = p)
				this->listDoi.pTail = bp;
			delete p;
			break;
		}

		bp = p;
		p = p->pNext;
	}
}

void ListDoiThi::randomDiem()
{
	NodeDoiThi* p = this->listDoi.pHead;

	while (p != NULL)
	{
		p->diem = rand() % (10001);
		p = p->pNext;
	}
}