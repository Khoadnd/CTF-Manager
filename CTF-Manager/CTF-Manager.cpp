#include <iostream>
#include "CTFEvent.h"
#include "menu.h"

using namespace std;

int main()
{
	CTFEvent event;

	event.initEvent();

	event.display();

	return 0;
}