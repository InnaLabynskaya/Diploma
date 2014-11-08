#include "AliveInput.h"
#include <iostream>
#include <string>
using namespace std;

AliveInput::AliveInput(void)
{
}

Product* AliveInput::createProduct()
{
	cout<<"Enter product name: ";
	char name[255];
	cin.getline(name, 255);
	AliveProduct* product = new AliveProduct(name);
	modifyProduct(product);
	return product;
}

void AliveInput::modifyProduct(Product* pProduct)
{
	AliveProduct* product = (AliveProduct*)pProduct;
	cout<<"Enter price: ";
	float price;
	cin>>price;
	product->setPrice(price);
	cout<<"Enter quantity: ";
	int quantity;
	cin>>quantity;
	product->setQuantity(quantity);
	cout<<"Does '"<< product->name() <<"' like light?(y/n): ";
	char light;
	cin>>light;
	product->setLight(light == 'y');
	cout<<"Enter age of '"<< product->name() <<"': ";
	int age;
	cin>>age;
	product->setAge(age);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

AliveInput::~AliveInput(void)
{
}
