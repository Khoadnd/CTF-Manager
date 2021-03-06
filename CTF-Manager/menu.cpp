#include "menu.h"

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

unsigned int Menu::uiCurrentEventID = 0;

Menu::Menu(CTFEvent* initListEvent)
{
	this->listEvent = initListEvent;
	this->event = {};
	this->iChoice = 0;
	this->numberOfEvent = 1;
}

unsigned int Menu::getCurrentEventID()
{
	return this->uiCurrentEventID;
}

void Menu::setCurrentEventID(unsigned int ID)
{
	this->uiCurrentEventID = ID;
}

Menu::Menu()
{
	this->numberOfEvent = 0;
	this->listEvent = nullptr;
	this->event = {};
	this->iChoice = 0;
}

Menu::~Menu()
{
	
}

void Menu::displayAdminPanel() //Done
{
	cout << "1) Chinh sua cuoc thi.\n";
	cout << "2) Set diem cho doi X.\n"; 
	cout << "3) Xoa doi thi X.\n";
	cout << "4) Xem thong tin cuoc thi.\n"; 
	cout << "5) Xuat danh sach doi thi.\n";
	cout << "6) Quan ly doi thi.\n";
	cout << "0) De quay lai main menu.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::displayLeaderPanel() //Done
{
	cout << "1) Doi ten nhom.\n"; 
	cout << "2) Xem thanh vien trong doi.\n";
	cout << "3) Xoa thanh vien.\n"; 
	cout << "4) Them thanh vien.\n";
	cout << "5) Doi mat khau.\n";
	cout << "0) De quay lai main menu.\n\n"; 
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

void Menu::displayMainMenu() //Done
{
	cout << "-----------------\n";
	cout << "----Main menu----\n";
	cout << "-----------------\n";
	cout << "Ten cuoc thi: ";
	puts(this->event.getTenCuocThi());
	cout << "Status: ";
	if (this->event.isStarted())
		cout << "Cuoc thi dang dien ra\n";
	else
		cout << "Cuoc thi chua bat dau\n";
	cout << "1) Xem thong tin cuoc thi.\n";
	cout << "2) Xem thong tin cac doi thi.\n";
	cout << "3) Xem top 3 doi thi.\n";
	cout << "4) Dang ky tham gia.\n"; 
	cout << "5) Kiem tra nhom X da tham gia chua.\n"; 
	cout << "6) Quan ly nhom.\n";
	cout << "0) Thoat.\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::enterToContinue()
{
	system("pause");
	system("cls");
}

void Menu::adminPanel() // Done
{
	char password[100], password_[] = "admin";
	cout << "Nhap password: ";
	cin.getline(password, 100);
	if (strcmp(password, password_) != 0)
		return;
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
		{
			char tenDoi[100];
			unsigned int diem;

			if (this->event.isListDoiThiEmpty())
			{
				cout << "Danh sach rong!\n";
				return;
			}

			this->event.xuatTenDoiThi();
			cout << endl;
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

			this->event.setDiemChoDoi(tenDoi, diem);
			break;
		}

		case 3: //Xoa doi X
		{
			this->event.xuatTenDoiThi();
			cout << endl;
			char tenDoiToRemove[100];

			cin.ignore();

			do
			{
				cout << "Nhap ten doi can xoa (0 to exit): ";
				cin.getline(tenDoiToRemove, 100);

				if (strcmp(tenDoiToRemove, "0") == 0)
					return;
			} while (!event.isXRegistered(tenDoiToRemove));

			this->event.removeDoi(tenDoiToRemove);

			break;
		}

		case 4:
			this->event.display();
			break;

		case 5:
			this->event.xuatDoiThi();
			break;

		case 6:
		{
			this->event.xuatTenDoiThi();
			cout << endl;
			cin.ignore();

			char tenDoiToEdit[100];

			do
			{
				cout << "Nhap ten doi can edit (0 to exit): ";
				cin.getline(tenDoiToEdit, 100);

				if (strcmp(tenDoiToEdit, "0") == 0)
					return;
			} while (!event.isXRegistered(tenDoiToEdit));

			NodeDoiThi* doiThi = this->event.getDoiThiTrongList(tenDoiToEdit);

			this->leaderPanel_(doiThi);

			break;
		}

		default:
			exit = 1;
			break;
		}

		system("pause");
		system("cls");
	} while (!exit);
}

void Menu::leaderPanel_(NodeDoiThi*& doiThi)
{
	bool exit = 0;
	int iChoice;

	do
	{

		displayLeaderPanel();
		cin >> iChoice;
		cin.ignore();
		switch (iChoice)
		{
		case 1: //Doi ten nhom
		{
			char initTenDoi[100], initTenDoi2[100];
			cout << "Nhap ten doi moi: ";
			cin.getline(initTenDoi, 100);
			cout << "Nhap lai ten doi moi: ";
			cin.getline(initTenDoi2, 100);
			if (strcmp(initTenDoi, initTenDoi2) != 0)
				cout << "Ten doi khong trung khop!" << endl;
			else
				strcpy_s(doiThi->cTenDoiThi, initTenDoi);
			break;
		}

		case 2:
			doiThi->ltvThanhVien.xuatThanhVien();
			break;

		case 3: //Xoa thanh vien
		{
			char memberToRemove[100];
			cout << "Nhap ten thanh vien can xoa: ";
			cin.getline(memberToRemove, 100);
			if (!this->event.isMemberRegistered(doiThi, memberToRemove))
				cout << "Ten thanh vien khong hop le!";
			doiThi->ltvThanhVien.removeThanhVien(memberToRemove);
			break;
		}

		case 4: //Them thanh vien
		{
			char memberToAdd[100];
			cout << "Nhap ten thanh vien can them: ";
			cin.getline(memberToAdd, 100);
			if (this->event.isMemberRegistered(doiThi, memberToAdd))
			{
				cout << "Thanh vien da dang ky!" << endl;
				break;
			}
			doiThi->ltvThanhVien.addTailThanhVien(doiThi->ltvThanhVien.createNodeThanhVien(memberToAdd));
			break;
		}

		case 5: //Doi mat khau
		{
			char newPassword[100], newPasswordConfirm[100], oldPassword[100];
			cout << "Nhap password hien tai: ";
			cin.getline(oldPassword, 100);
			if (strcmp(doiThi->cPassDoiTruong, oldPassword) != 0)
			{
				cout << "Sai" << endl;
				break;
			}

			cout << "Nhap password moi: ";
			cin.getline(newPassword, 100);
			cout << "Nhap lai password moi: ";
			cin.getline(newPasswordConfirm, 100);
			if (strcmp(newPassword, newPasswordConfirm) != 0)
				cout << "Password khong trung khop!" << endl;
			else
				strcpy_s(doiThi->cPassDoiTruong, newPassword);
			break;
		}

		default:
			exit = 1;
			break;
		}
		enterToContinue();
	} while (exit == 0);
}

void Menu::leaderPanel() //Done
{
	if (this->event.isListDoiThiEmpty())
	{
		cout << "Chua co doi tham gia!\n";
		return;
	}
	char tenDoi[100];
	cout << "Nhap ten doi: ";
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

	system("cls");

	NodeDoiThi* doiThi = this->event.getDoiThiTrongList(tenDoi);

	leaderPanel_(doiThi);
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
	{
		char tenCuocThi[100];

		cout << "Nhap ten cuoc thi: ";
		cin.ignore();
		cin.getline(tenCuocThi, 100);

		this->event.setTenCuocThi(tenCuocThi);
		cout << "Set thanh cong!\n";

		break;
	}

	case 2:
	{
		char nhaToChuc[100];

		cout << "Nhap ten nha to chuc: ";
		cin.ignore();
		cin.getline(nhaToChuc, 100);

		this->event.setTenNhaToChuc(nhaToChuc);
		cout << "Set thanh cong!\n";
		break;
	}

	case 3:
	{
		cout << "Nhap ngay to chuc:\n";
		date.nhap();

		this->event.setNgayToChuc(date);
		cout << "Set thanh cong!\n";
		break;
	}

	case 4:
	{
		unsigned long triGia;

		cout << "Nhap tri gia: ";
		cin >> triGia;

		this->event.setTriGiaGiaiThuong(triGia);
		cout << "Set thanh cong!\n";
		break;
	}

	case 5:
	{
		char Format[15];

		cout << "Nhap format moi: ";
		cin.ignore();
		cin.getline(Format, 15);

		this->event.setFormat(Format);
		cout << "Set thanh cong!\n";
		break;
	}

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
	thread *start = NULL;
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
		{
			char cTenDoi[100];
			cout << "Nhap ten doi can kiem tra: ";
			cin.getline(cTenDoi, 100);
			if (this->event.isXRegistered(cTenDoi))
				cout << "Da dang ky!\n";
			else
				cout << "Chua dang ky!\n";
			break;
		}

		case 6:
			this->leaderPanel();
			break;

		case 42069:
			this->adminPanel();
			break;

		case 420:
		{
			char password[100], password_[] = "admin";
			cout << "Nhap password: ";
			cin.getline(password, 100);
			if (strcmp(password, password_) != 0)
				break;

			if (this->event.isStarted())
			{
				cout << "Cuoc thi da duoc dien ra roi!" << endl;
				break;
			}

			this->event.setStarted(1);
			start = new thread(&CTFEvent::start, &this->event);
			
			break;
		}

		case 69:
		{
			char password[100], password_[] = "admin";
			cout << "Nhap password: ";
			cin.getline(password, 100);
			if (strcmp(password, password_) != 0)
				break;

			if (!this->event.isStarted())
			{
				cout << "Khong co cuoc thi nao dang dien ra" << endl;
				break;
			}
			this->event.setStarted(0);
			start->join();
			delete start;
			start = NULL;
			break;
		}

		case 0:
			return;
			break;

		default:
			continue;
		}

		enterToContinue();
	}
}

void Menu::display_menu()
{
	cout << "-----------------------\n";
	cout << "----Welcome to CTF!----\n";
	cout << "-----------------------\n";
	cout << "1) Dang ky them cuoc thi\n";
	cout << "2) Huy cuoc thi\n";
	cout << "3) Xem cac cuoc thi dang dien ra\n";
	cout << "4) Xem top 3 cuoc thi co so luong tham gia dong nhat!\n";
	cout << "5) Xem cuoc thi, dang ky tham gia, tham gia\n";
	cout << "0) Thoat khoi chuong trinh\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::displayEvent()
{
	for (int i = 0; i < this->numberOfEvent; i++)
	{
		cout << "(ID: " << i << ")" << endl;
		puts(this->listEvent[i].getTenCuocThi());
		cout << "----------------" << endl;
	}
}

void Menu::_menu()
{
	system("cls");
	int iChoice = 0;
	bool exit = 0;
	do
	{
		this->display_menu();
		cin >> iChoice;
		cin.ignore();

		switch (iChoice)
		{

		case 1:
		{
			// AUTH
			char _Password[] = "init", password[10];
			cout << "Nhap mat khau da duoc cung cap: ";
			cin.getline(password, 10);
			if (strcmp(_Password, password) != 0)
				break;
			// ENDAUTH

			this->listEvent[this->numberOfEvent].initEvent();

			cout << "Da them event: " << endl;
			this->listEvent[this->numberOfEvent++].display();
			break;
		}

		case 2:
		{
			// AUTH
			char _Password[] = "admin", password[10];
			cout << "Nhap mat khau da duoc cung cap: ";
			cin.getline(password, 10);
			if (strcmp(_Password, password) != 0)
				break;
			// ENDAUTH

			this->displayEvent();
			int ID;
			cout << "Nhap ID event can huy: ";
			cin >> ID;
			if (ID > this->listEvent->getSoLuongCuocThi() - 1)
			{
				cout << "Khong hop le!" << endl;
				break;
			}

			this->listEvent[ID] = this->listEvent[this->listEvent->getSoLuongCuocThi() + 1];
			this->numberOfEvent--;
			break;
		}

		case 3:
			this->displayEvent();

			break;

		case 4:
			for (int i = 0; i < this->numberOfEvent - 1; i++)
			{
				CTFEvent max = this->listEvent[i];
				for (int j = i + 1; j < this->numberOfEvent; j++)
					if (this->listEvent[j].getSoLuongDoiThamGia() > max.getSoLuongDoiThamGia())
						max = this->listEvent[j];
				swap(max, this->listEvent[i]);
			}

			cout << "--------------------\n";
			this->listEvent[0].display();
			cout << "--------------------\n";
			this->listEvent[1].display();
			cout << "--------------------\n";
			this->listEvent[2].display();
			cout << "--------------------\n";
			break;

		case 5:
		{
			this->displayEvent();

			int ID;
			cout << "Nhap ID cuoc thi: ";
			cin >> ID;
			if (ID > this->listEvent->getSoLuongCuocThi() - 1)
			{
				cout << "Khong hop le!" << endl;
				break;
			}
			this->event = this->listEvent[ID];
			this->menu();

			break;
		}

		case 0:
			exit = 1;
			break;

		default:
			break;
		}

		enterToContinue();
	} while (!exit);
}