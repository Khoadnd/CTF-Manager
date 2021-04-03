#pragma once
#include "CTFEvent.h"

class Menu
{
private:
	CTFEvent event;
	int iChoice;

public:
	Menu(CTFEvent = {});
	~Menu();

	void setEvent(CTFEvent&);
	void menu();

	void leaderPanel();
	void adminPanel();

	void displayLeaderPanel();
	void displayAdminPanel();

	void displayMainMenu();

	void enterToContinue();

	void eventEditor();
};

