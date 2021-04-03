#include <iostream>
#include "CTFEvent.h"
#include "menu.h"

using namespace std;

int main()
{
	CTFEvent event;

	event.initEvent();
	event.display();

	Menu* menu = new Menu;
	menu->setEvent(event);

	menu->menu();

	return 0;
}