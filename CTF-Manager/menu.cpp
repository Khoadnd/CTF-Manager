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

void Menu::displayAdminPanel()
{
	cout << "1) Chinh sua cuoc thi.\n"; //Done
	cout << "2) Set diem cho doi X.\n"; //Done
	cout << "3) Xoa doi thi X.\n";// Not yet
	cout << "4) Xem thong tin cuoc thi.\n"; //Done
	cout << "5) Xuat danh sach doi thi.\n"; //Done
	cout << "6) Quan ly doi thi.\n"; //Not yet
	cout << "0) De quay lai main menu.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::displayLeaderPanel()
{
	cout << "1) Doi ten nhom.\n"; //Completed
	cout << "2) Xoa thanh vien.\n"; //Not yet
	cout << "3) Them thanh vien.\n"; //Completed
	cout << "4) Doi mat khau.\n"; //Not yet
	cout << "0) De quay lai main menu.\n\n"; //Completed
	cout << "Nhap lua chon cua ban: ";
}

void Menu::displayEventEditor() //Done
{
	cout << "1) Doi ten cuoc thi.\n";
	cout << "2) Doi ten nha to chuc.\n";
	cout << "3) Doi ngay to chuc.\n";
	cout << "4) Thay doi tri gia giai thuong.\n";
	cout << "5) Thay doi format.\n";
	cout << "0) De quay lai main menu.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::displayMainMenu() //Not yet
{
	cout << "-----------------\n";
	cout << "----Main menu----\n";
	cout << "-----------------\n";
	cout << "1) Xem thong tin cuoc thi.\n"; //Done
	cout << "2) Xem thong tin cac doi thi.\n"; //Done
	cout << "3) Xem top 3 doi thi.\n"; //Done
	cout << "4) Dang ky tham gia.\n"; //Done
	cout << "5) Kiem tra nhom X da tham gia chua.\n"; //Done
	cout << "6) Quan ly nhom.\n";//Not yet
	cout << "0) Thoat.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::enterToContinue()
{
	system("pause");
	system("cls");
}

void Menu::adminPanel()
{
	bool exit = 0;
	int iChoice;

	do
	{
		displayAdminPanel();

		cin >> iChoice;
		switch (iChoice)
		{
		case 1:
			this->eventEditor(exit);
			break;

		case 2:
			char tenDoi[100];
			unsigned int diem;

			if (this->event.isListDoiThiEmpty())
			{
				cout << "Danh sach rong!\n";
				return;
			}

			cin.ignore();
			do
			{
				cout << "Nhap ten doi can set diem (0 to exit): ";
				cin.getline(tenDoi, 100);

				if (strcmp(tenDoi, "0") == 0)
					return;
			} while (!event.isXRegistered(tenDoi));

			cout << "Nhap so diem: ";
			cin >> diem;

			event.setDiemChoDoi(tenDoi, diem);
			break;

		case 3: //Xoa doi X
			break;

		case 4:
			this->event.display();
			break;

		case 5:
			this->event.xuatDoiThi();
			break;

		case 6:
			//Quan Ly Doi Thi
			break;

		default:
			exit = 1;
			break;
		}

		system("pause");
		system("cls");
	} while (!exit);
}

void Menu::leaderPanel()
{
	if (this->event.isListDoiThiEmpty())
	{
		cout << "Chua co doi tham gia!\n";
		return;
	}
	char tenDoi[100];
	cout << "Nhap ten doi: ";
	cin.ignore();
	cin.getline(tenDoi, 100);

	if (!event.isXRegistered(tenDoi))
	{
		cout << "Doi khong ton tai!\n";
		return;
	}


	//Auth
	char Password[100];

	cout << "Nhap password: ";
	cin.getline(Password, 100);

	char* pass = this->event.getPassword(tenDoi);

	if (strcmp(Password, pass) != 0)
	{
		cout << "Sai mat khau!\n";
		return;
	}
	//EndAuth

	bool exit = 0;
	int iChoice;

	do
	{
		displayLeaderPanel();
		cin >> iChoice;

		switch (iChoice)
		{
		case 1: //Doi ten nhom
			event.leaderChangeTeamName(tenDoi);
			break;

		case 2: //Xoa thanh vien
			cin.ignore();
			event.removeMemberFrom(tenDoi);
			break;

		case 3: //Them thanh vien
			cin.ignore();
			event.addMemberTo(tenDoi);
			break;

		case 4: //Doi mat khau
			event.leaderChangePassword(tenDoi);
			break;

		default:
			exit = 1;
			break;
		}

	} while (exit == 0);
}

void Menu::eventEditor(bool& exit)
{
	int iChoice;
	displayEventEditor();
	cin >> iChoice;

	Date date;

	switch (iChoice)
	{
	case 1:
		char tenCuocThi[100];

		cout << "Nhap ten cuoc thi: ";
		cin.ignore();
		cin.getline(tenCuocThi, 100);

		this->event.setTenCuocThi(tenCuocThi);
		cout << "Set thanh cong!\n";

		break;

	case 2:
		char nhaToChuc[100];

		cout << "Nhap ten nha to chuc: ";
		cin.ignore();
		cin.getline(nhaToChuc, 100);

		this->event.setTenNhaToChuc(nhaToChuc);
		cout << "Set thanh cong!\n";
		break;

	case 3:
		cout << "Nhap ngay to chuc:\n";
		date.nhap();

		this->event.setNgayToChuc(date);
		cout << "Set thanh cong!\n";
		break;

	case 4:
		unsigned long triGia;

		cout << "Nhap tri gia: ";
		cin >> triGia;

		this->event.setTriGiaGiaiThuong(triGia);
		cout << "Set thanh cong!\n";
		break;

	case 5:
		char Format[15];

		cout << "Nhap format moi: ";
		cin.ignore();
		cin.getline(Format, 15);

		this->event.setFormat(Format);
		cout << "Set thanh cong!\n";
		break;

	default:
		exit = 1;
		break;
	}
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