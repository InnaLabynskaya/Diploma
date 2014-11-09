#include "UnaliveInput.h"
#include "Utilities.h"
#include <iostream>
#include <string>
using namespace std;

UnaliveInput::UnaliveInput(void)
{
}

Product* UnaliveInput::createProduct()
{
	cout<<"Enter product name: ";
	UnaliveProduct* product = new UnaliveProduct(Utilities::inputString());
	modifyProduct(product);
	return product;
}

void UnaliveInput::modifyProduct(Product* pProduct)
{
	UnaliveProduct* product = (UnaliveProduct*) pProduct;
	cout<<"Enter price: ";
	product->setPrice(Utilities::inputFloat());
	cout<<"Enter quantity: ";
	product->setQuantity(Utilities::intputInteger());
	cout<<"Enter expiration date of '"<< product->name() <<"': ";
	product->setExpirationDate(Utilities::intputInteger());
}

UnaliveInput::~UnaliveInput(void)
{
}
