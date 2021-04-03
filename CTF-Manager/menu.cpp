#include "menu.h"

#include <iostream>

using namespace std;

Menu::Menu(CTFEvent event)
{
	this->event = event;
	this->iChoice = 0;
}

Menu::~Menu()
{

}

void Menu::enterToContinue()
{
	system("pause");
	system("cls");
}

void Menu::adminPanel()
{

}

void Menu::leaderPanel()
{

}

void Menu::displayAdminPanel()
{

}

void Menu::eventEditor()
{

}

void Menu::displayLeaderPanel()
{

}

void Menu::displayMainMenu()
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

void Menu::setEvent(CTFEvent& event)
{
	this->event = event;
}

void Menu::menu()
{
	enterToContinue();
	int iChoice;
	while (1)
	{
		displayMainMenu();
		cin >> iChoice;
		cin.ignore();\

		switch (iChoice)
		{
		case 1:
			this->event.display();
			break;

		case 2:
			this->event.xuatDoiThi();
			break;

		case 3:
			this->event.xuatTop3();
			break;

		case 4:
			this->event.addDoiThi();
			break;

		case 5:
			char cTenDoi[100];
			cout << "Nhap ten doi can kiem tra: ";
			cin.getline(cTenDoi, 100);
			if (this->event.isXRegistered(cTenDoi))
				cout << "Da dang ky!\n";
			else
				cout << "Chua dang ky!\n";
			break;

		case 6:
			break;

		case 42069:
			this->adminPanel();
			break;

		case 0:
			exit(0);
			break;

		default:
			cout << "Lua chon khong hop le!.\n";
			break;
		}

		enterToContinue();
	}
}