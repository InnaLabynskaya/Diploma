#ifndef __UNALIVEPRODUCT__
#define __UNALIVEPRODUCT__
#include "product.h"

class UnaliveProduct :
	public Product
{
public:
	UnaliveProduct(const std::string &name);
	~UnaliveProduct(void);
	int getExpirationDate();
	void setExpirationDate(int expirationDate);
private:
	int m_expirationDate;
};

#endif