#pragma once
#include "Date.h"
#include "ListDoiThi.h"

class CTFEvent
{
private:
	char cTenCuocThi[100];
	char cTenNhaToChuc[100];
	Date dNgayToChuc;
	unsigned long ulTriGiaGiaiThuong;
	char cFormat[100];
	ListDoiThi ldtListDoiThi;

public:
	CTFEvent();
	~CTFEvent();

	void display();
	void initEvent();
	void setEvent(char*, char*, Date, unsigned long, char*); //ten, nhatochuc, ngaytochuc, tri gia, format

	bool setTenCuocThi(char*);
	bool setTenNhaToChuc(char*);
	bool setNgayToChuc(Date);
	bool setTriGiaGiaiThuong(unsigned long);
	void setFormat(char*);
	void setDiemChoDoi(char*, unsigned int);
	
	void addDoiThi();
	
	void xuatDoiThi();
	void xuatTop3();

	int getSoLuongDoiThamGia();
	char* getPassword(char*);

	bool isXRegistered(char *);
	bool isListDoiThiEmpty();
	bool isFormat(char*);
	bool isMemberRegistered(NodeDoiThi*, char*);

	NodeDoiThi* getDoiThiTrongList(char*);
};

