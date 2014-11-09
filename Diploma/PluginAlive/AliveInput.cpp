#include "AliveInput.h"
#include "Utilities.h"
#include <iostream>
#include <string>
using namespace std;

AliveInput::AliveInput(void)
{
}

Product* AliveInput::createProduct()
{
	cout<<"Enter product name: ";
	AliveProduct* product = new AliveProduct(Utilities::inputString());
	modifyProduct(product);
	return product;
}

void AliveInput::modifyProduct(Product* pProduct)
{
	AliveProduct* product = (AliveProduct*)pProduct;
	cout<<"Enter price: ";
	product->setPrice(Utilities::inputFloat());
	cout<<"Enter quantity: ";
	product->setQuantity(Utilities::intputInteger());
	cout<<"Does '"<< product->name() <<"' like light?(y/n): ";
	product->setLight(Utilities::inputBool());
	cout<<"Enter age of '"<< product->name() <<"': ";
	product->setAge(Utilities::intputInteger());
}

AliveInput::~AliveInput(void)
{
}
