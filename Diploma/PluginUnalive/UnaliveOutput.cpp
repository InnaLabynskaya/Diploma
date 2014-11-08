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
	showHeader();
	showData((UnaliveProduct*)product);
}

void UnaliveOutput::show(const std::vector<Product*>& products)
{
	showHeader();
	std::vector<Product*>::const_iterator it;
	for (it = products.begin() ; it != products.end(); ++it)
	{
		showData((UnaliveProduct*)*it);
	}
}

void UnaliveOutput::showHeader()
{
	cout<<"Name"<<setw(10)
		<<"Price"<<setw(5)
		<<"Quantity"<<setw(5)
		<<"Exp date"<<endl;
}

void UnaliveOutput::showData(UnaliveProduct* product)
{
	cout<<product->name()<<setw(10)
		<<product->getPrice()<<setw(10)
		<<product->getQuantity()<<setw(10)
		<<product->getExpirationDate()<<endl;
}


UnaliveOutput::~UnaliveOutput(void)
{
}
