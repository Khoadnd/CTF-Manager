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
	ListDoiThi ldtListDoiThi;

public:
	CTFEvent();
	~CTFEvent();

	void display();
	void initEvent();
	void setEvent(char*, char*, Date, unsigned long);

	bool setTenCuocThi(char*);
	bool setTenNhaToChuc(char*);
	bool setNgayToChuc(Date);
	bool setTriGiaGiaiThuong(unsigned long);
	

};

