#ifndef __PRODUCT__
#define __PRODUCT__
#include <string>

class Product
{
public:
	Product(const std::string &name);
	virtual const std::string &name();
	virtual float getPrice();
	virtual void setPrice(float price);
	virtual unsigned int getQuantity();
	virtual void setQuantity(unsigned int quantity);
	virtual unsigned int addQuantity(unsigned int quantity);
	virtual unsigned int subQuantity(unsigned int quantity);
	virtual ~Product(void);
protected:
	std::string m_name;
	float m_price;
	unsigned int m_quantity;
};

#endif