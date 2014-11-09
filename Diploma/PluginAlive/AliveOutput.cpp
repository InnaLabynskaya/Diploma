#include "AliveOutput.h"
#include <iostream>
#include <iomanip>
using namespace std;

AliveOutput::AliveOutput(void)
{
}

void AliveOutput::show(Product* product)
{
	showHeader();
	showData((AliveProduct*)product);
}

void AliveOutput::show(const std::vector<Product*>& products)
{
	showHeader();
	std::vector<Product*>::const_iterator it;
	for (it = products.begin() ; it != products.end(); ++it)
	{
		showData((AliveProduct*)*it);
	}
}

void AliveOutput::showHeader()
{
	cout<<"Name"<<setw(10)
		<<"Price"<<setw(10)
		<<"Quantity"<<setw(10)
		<<"Light"<<setw(10)
		<<"Age"<<endl;
}

void AliveOutput::showData(AliveProduct* product)
{
	cout<<product->name()<<setw(10)
		<<product->getPrice()<<setw(10)
		<<product->getQuantity()<<setw(10)
		<<(product->getLight()?"yes":"no")<<setw(10)
		<<product->getAge()<<endl;
}

AliveOutput::~AliveOutput(void)
{
}
