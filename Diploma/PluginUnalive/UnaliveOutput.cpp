#include "UnaliveOutput.h"
#include <iostream>
#include "UnaliveProduct.h"
#include <iomanip>
using namespace std;

UnaliveOutput::UnaliveOutput()
{
}

void UnaliveOutput::show(Product* product)
{
	UnaliveProduct* unaliveProduct = (UnaliveProduct*)(product);
	cout<<unaliveProduct->name()<<setw(10)
		<<unaliveProduct->getPrice()<<setw(10)
		<<unaliveProduct->getQuantity()<<setw(10)
		<<unaliveProduct->getExpirationDate()<<endl;
}

void UnaliveOutput::show(const std::vector<Product*>& products)
{
	cout<<"Name"<<setw(10)
		<<"Price"<<setw(5)
		<<"Quantity"<<setw(5)
		<<"Exp date"<<endl;
	std::vector<Product*>::const_iterator it;
	for (it = products.begin() ; it != products.end(); ++it)
	{
		show(*it);
	}
}

UnaliveOutput::~UnaliveOutput(void)
{
}
