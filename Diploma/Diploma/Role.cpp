#include "Role.h"
#include <iostream>
#include "Utilities.h"
using namespace std;

Role::Role(const Categories& categories):m_categories(categories)
{
}

void Role::run()
{
	while(true)
	{
		Utilities::clearScreen();
		cout<<"Choose category\n";
		for(unsigned int i = 0; i < m_categories.size(); i++)
			cout<<(i+1)<<": "<<m_categories[i]->name()<<endl;
		cout<<"0: Back\n";
		unsigned int choose = Utilities::intputInteger();
		if(choose == 0)
			break;
		if(choose > m_categories.size())
		{
			cout<<"Enter another category number\n";
			Utilities::waitForInput();
		}
		else
		{
			Shop* shop = new Shop(m_categories[choose - 1]);
			options(shop);
			delete shop;
		}
	}
}

Role::~Role(void)
{
}
