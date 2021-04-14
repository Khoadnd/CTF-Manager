#include <iostream>
#include <vector>
#include "CTFEvent.h"
#include "menu.h"

using namespace std;

int main()
{
	CTFEvent* event = new CTFEvent[100];

	//CTFEvent event;

	//event.initEvent();
	//event.display();

	cout << "Please initialize atleast 1 event!" << endl;
	event[0].initEvent();

	system("pause");

	Menu* menu = new Menu(event);

	menu->_menu();

	//Menu* menu = new Menu(&event[0]);

	//menu->menu();

	return 0;
}