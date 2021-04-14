#pragma once
#include "CTFEvent.h"
#include <vector>

class Menu
{
private:
	CTFEvent event;
	CTFEvent* listEvent;
	int iChoice;
	static unsigned int uiCurrentEventID;
	unsigned int numberOfEvent;

public:
	Menu(CTFEvent*);
	Menu();
	~Menu();

	void setEvent(CTFEvent &);
	void menu();
	void _menu();

	void leaderPanel();
	void leaderPanel_(NodeDoiThi*&);
	void adminPanel();

	void displayLeaderPanel();
	void displayAdminPanel();
	void displayEventEditor();
	void displayMainMenu();
	void display_menu();

	void enterToContinue();

	void eventEditor(bool&);

	void setCurrentEventID(unsigned int = 0);
	unsigned int getCurrentEventID();

	void displayEvent();
};

