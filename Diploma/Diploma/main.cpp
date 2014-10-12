#include <iostream>
#include "PluginManager.h"
using namespace std;

int main()
{
	PluginManager manager("..\\Debug\\");
	Categories::const_iterator it;
	for (it = manager.categories().begin(); it != manager.categories().end(); ++it)
	{
		Category* category = *it;
		cout<<"Name: "<<category->name()<<endl;
	}
	return 0;
}