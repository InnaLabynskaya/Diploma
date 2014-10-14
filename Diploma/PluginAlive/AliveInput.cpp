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
	cout<<"Enter price: ";
	float price;
	cin>>price;
	product->setPrice(price);
	cout<<"Enter quantity: ";
	int quantity;
	cin>>quantity;
	product->setQuantity(quantity);
	cout<<"Does '"<< name <<"' like light?(y/n): ";
	char light;
	cin>>light;
	product->setLight(light == 'y');
	cout<<"Enter age of '"<< name <<"': ";
	int age;
	cin>>age;
	product->setAge(age);
	return product;
}

AliveInput::~AliveInput(void)
{
}
