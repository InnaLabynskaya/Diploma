#include "Manager.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Manager::Manager(const Categories& categories):Role(categories)
{
}

void Manager::options(Shop* shop)
{
	bool loop = true;
	while(loop)
	{
		Utilities::clearScreen();
		cout<<"Choose option\n"
			<<"1: Show products\n"
			<<"2: Add product\n"
			<<"3: Modify product\n"
			<<"4: Remove product\n"
			<<"5: Remove all products\n"
			<<"6: Save changes\n"
			<<"0: Back\n";
		switch(Utilities::intputInteger())
		{
		case 0:
			loop = false;
			break;
		case 1:
			Utilities::clearScreen();
			shop->showProducts();
			Utilities::waitForInput();
			break;
		case 2:
			Utilities::clearScreen();
			shop->addProduct();
			break;
		case 3:
			Utilities::clearScreen();
			cout<<"Enter product index\n";
			shop->modifyProduct(Utilities::intputInteger());
			break;
		case 4:
			cout<<"Enter product index\n";
			shop->removeProduct(Utilities::intputInteger());
			break;
		case 5:
			shop->removeProducts();
			break;
		case 6:
			shop->save();
			break;
		default:
			cout<<"Enter another option\n";
			Utilities::waitForInput();
			break;
		}
	}
}

Manager::~Manager(void)
{
}
