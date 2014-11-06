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
	//Category* category = manager.categories()[0];
	//vector<Product*> products;
	//for (int i=0;i<2;++i) {
	//	Product* product = category->input()->createProduct();
	//	products.push_back(product);
	//}
	//category->output()->show(products);
	//category->save()->save(products);
	//vector<Product*>::iterator pit = products.begin();
	//for (; pit != products.end(); ++pit) {
	//	delete *pit;
	//}
	//products.clear();
	//category->load()->load(products);
	//category->output()->show(products);
	return 0;
}
