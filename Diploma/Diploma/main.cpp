#include "PluginManager.h"
#include "Role.h"
#include "Client.h"
#include "Manager.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

int main()
{
	PluginManager manager("..\\Debug\\");
	bool loop = true;
	while(loop)
	{
		Utilities::clearScreen();
		cout<<"Choose role\n"
			<<"1: Client\n"
			<<"2: Manager\n"
			<<"0: Exit\n";
		switch(Utilities::intputInteger())
		{
		case 0: 
			{
				loop = false;
				break;
			}
		case 1:
			{
				Role *role = new Client(manager.categories());
				role->run();
				delete role;
				break;
			}
		case 2:
			{
				Role *role = new Manager(manager.categories());
				role->run();
				delete role;
				break;
			}
		default:
			{
				cout<<"Choose another role\n";
				Utilities::waitForInput();
				break;
			}
		}
	}
	return 0;
}
