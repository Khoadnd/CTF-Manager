#pragma once
class Date
{
private:
	int iNgay;
	int iThang;
	int iNam;

public:
	Date(int = 0, int = 0, int = 0);
	~Date();

	void nhap();
	void xuat();

	bool setNgay(int);
	bool setThang(int);
	bool setNam(int);
	bool setDate(Date = {0, 0, 0});

	bool isLeap(int);
	bool isLegit(Date);
};

