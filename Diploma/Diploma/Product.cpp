#include "Product.h"
using namespace std;

Product::Product(const string &name):m_name(name), m_price(0), m_quantity(0)
{
}

float Product::getPrice()
{
	return m_price;
}

void Product::setPrice(float price)
{
	if(price > 0)
		m_price = price;
}

unsigned int Product::getQuantity()
{
	return m_quantity;
}

void Product::setQuantity(unsigned int quantity)
{
	m_quantity = quantity;
}

unsigned int Product::addQuantity(unsigned int quantity)
{
	return m_quantity += quantity;
}

unsigned int Product::subQuantity(unsigned int quantity)
{
	if(quantity <= m_quantity)
		return m_quantity -= quantity;
}

Product::~Product(void)
{
}
