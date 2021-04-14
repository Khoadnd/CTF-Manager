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
	bool started;
	ListDoiThi ldtListDoiThi;
	static unsigned int uiSoluongCuocThi;
	unsigned int soLuongThamGia;

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
	void setStarted(bool);
	
	void addDoiThi();
	
	void xuatDoiThi();
	void xuatTenDoiThi();
	void xuatTop3();

	void removeDoi(char*);

	int getSoLuongDoiThamGia();
	char* getPassword(char*);
	char* getTenCuocThi();

	bool isXRegistered(char *);
	bool isListDoiThiEmpty();
	bool isFormat(char*);
	bool isMemberRegistered(NodeDoiThi*, char*);
	bool isStarted();

	void start();
	void stop();

	NodeDoiThi* getDoiThiTrongList(char*);

	unsigned int getSoLuongCuocThi();
	void setSoLuongCuocThi(unsigned int);
};

