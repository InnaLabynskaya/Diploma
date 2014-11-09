#include "Client.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Client::Client(const Categories& categories):Role(categories)
{
}

void Client::options(Shop* shop)
{
	bool loop = true;
	while(loop)
	{
		Utilities::clearScreen();
		cout<<"Choose option\n"
			<<"1: Show products\n"
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
		default:
			cout<<"Enter another option\n";
			Utilities::waitForInput();
			break;
		}
	}
}

Client::~Client(void)
{
}
