#pragma once


struct NodeThanhVien
{
	char cTenThanhVien[100];
	NodeThanhVien* pNext;
};

struct ListTV
{
	NodeThanhVien* pHead;
	NodeThanhVien* pTail;
};

class ListThanhVien
{
private:
	ListTV ltvListThanhVien;

public:
	ListThanhVien();
	~ListThanhVien();

	void nhapListThanhVien();
	void addTailThanhVien(NodeThanhVien*);
	NodeThanhVien* createNodeThanhVien(char*);

	bool isMemberExist(char*);

	void removeThanhVien(char*);

	void xuatThanhVien();
};

struct NodeDoiThi
{
	char cTenDoiThi[100];
	char cTenDoiTruong[100];
	char cPassDoiTruong[100];
	unsigned int diem;
	ListThanhVien ltvThanhVien;
	NodeDoiThi* pNext;
};

struct ListDoi
{
	NodeDoiThi* pHead;
	NodeDoiThi* pTail;
};

bool isMemberExistInNode(NodeDoiThi*, char*);

class ListDoiThi
{
private:
	ListDoi listDoi;

public:
	ListDoiThi();
	~ListDoiThi();

	void nhapListDoiThi();
	void nhapDoiThi(); //nhap and return Node
	void addTailDoiThi(NodeDoiThi*);
	NodeDoiThi* createNodeDoiThi(char*, char*, char*, ListThanhVien);
	NodeDoiThi* getDoiThi(char*);

	void xuatDoiThi(int = 0);

	void setDiem(char*, unsigned int);

	void sortDiem();

	int getSoLuongDoiThi();
	char* getPassword(char*);

	bool isDoiExist(char*);
	bool isEmpty();
	void swap(NodeDoiThi*&, NodeDoiThi*&);
};

