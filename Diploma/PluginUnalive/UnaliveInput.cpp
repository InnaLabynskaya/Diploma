#include "UnaliveInput.h"
#include <iostream>
#include <string>
using namespace std;

UnaliveInput::UnaliveInput(void)
{
}

Product* UnaliveInput::createProduct()
{
	cout<<"Enter product name: ";
	char name[255];
	cin.getline(name, 255);
	UnaliveProduct* product = new UnaliveProduct(name);
	cout<<"Enter price: ";
	float price;
	cin>>price;
	product->setPrice(price);
	cout<<"Enter quantity: ";
	int quantity;
	cin>>quantity;
	product->setQuantity(quantity);
	cout<<"Enter expiration date of '"<< name <<"': ";
	int expirationDate;
	cin>>expirationDate;
	product->setExpirationDate(expirationDate);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return product;
}

void UnaliveInput::modifyProduct(Product* pProduct)
{
	UnaliveProduct* product = (UnaliveProduct*) pProduct;
	cout<<"Enter price: ";
	float price;
	cin>>price;
	product->setPrice(price);
	cout<<"Enter quantity: ";
	int quantity;
	cin>>quantity;
	product->setQuantity(quantity);
	cout<<"Enter expiration date of '"<< product->name() <<"': ";
	int expirationDate;
	cin>>expirationDate;
	product->setExpirationDate(expirationDate);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

UnaliveInput::~UnaliveInput(void)
{
}
