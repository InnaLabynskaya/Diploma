#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop(Category* category):m_category(category)
{
	load();
}

void Shop::showProducts()
{
	m_category->output()->show(m_products);
}

void Shop::showProduct(unsigned int index)
{
	if(index < m_products.size())
		m_category->output()->show(m_products[index]);
	else
		cout<<"There is no product with this index\n";
}

void Shop::removeProducts()
{
	vector<Product*>::iterator it;
	for(it = m_products.begin(); it != m_products.end(); it++)
	{
		delete *it;
	}
	m_products.clear();
}

void Shop::removeProduct(unsigned int index)
{
	if(index < m_products.size())
	{
		delete m_products[index];
		m_products.erase(m_products.begin() + index);
	}
	else
		cout<<"There is no product with this index\n";
}

void Shop::addProduct()
{
	m_products.push_back(m_category->input()->createProduct());
}

void Shop::load()
{
	m_category->load()->load(m_products);
}

void Shop::save()
{
	m_category->save()->save(m_products);
}

Shop::~Shop()
{
	removeProducts();
}
