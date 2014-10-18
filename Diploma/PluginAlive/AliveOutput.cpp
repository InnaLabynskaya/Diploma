#include "AliveOutput.h"
#include <iostream>
#include <iomanip>
using namespace std;

AliveOutput::AliveOutput(void)
{
}

void AliveOutput::show(Product* product)
{
	cout<<"Name"<<setw(10)
		<<"Price"<<setw(10)
		<<"Quantity"<<setw(10)
		<<"Light"<<setw(10)
		<<"Age"<<endl;
	AliveProduct* aliveProduct = (AliveProduct*)(product);
	cout<<aliveProduct->name()<<setw(10)
		<<aliveProduct->getPrice()<<setw(10)
		<<aliveProduct->getQuantity()<<setw(10)
		<<(aliveProduct->getLight()?"yes":"no")<<setw(10)
		<<aliveProduct->getAge()<<endl;
}

void AliveOutput::show(const std::vector<Product*>& products)
{
	cout<<"Name"<<setw(10)
		<<"Price"<<setw(5)
		<<"Quantity"<<setw(5)
		<<"Light"<<setw(5)
		<<"Age"<<endl;
	std::vector<Product*>::const_iterator it;
	for (it = products.begin() ; it != products.end(); ++it)
	{
		show(*it);
	}
}

AliveOutput::~AliveOutput(void)
{
}
