#include "menu.h"

#include <iostream>

using namespace std;

void enterToContinue()
{
	system("pause");
	system("cls");
}

void displayMainMenu()
{
	cout << "-----------------\n";
	cout << "----Main menu----\n";
	cout << "-----------------\n";
	cout << "1) Xem thong tin cuoc thi.\n";
	cout << "2) Xem thong tin cac doi thi.\n";
	cout << "3) Xem top 3 doi thi.\n";
	cout << "4) Dang ky tham gia.\n";
	cout << "5) Kiem tra nhom X da tham gia chua.\n";
	cout << "6) Quan ly nhom.\n";
	cout << "0) Thoat.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void menu()
{
	int iChoice;
	while (1)
	{
		displayMainMenu();
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			break;

		default:
			cout << "Lua chon khong hop le!.\n";
			enterToContinue();
			break;
		}
	}
}