#include "UnaliveProduct.h"


UnaliveProduct::UnaliveProduct(const std::string &name):Product(name)
{
	m_expirationDate = 0;
}

int UnaliveProduct::getExpirationDate()
{
	return m_expirationDate;
}

void UnaliveProduct::setExpirationDate(int expirationDate)
{
	m_expirationDate = expirationDate;
}

UnaliveProduct::~UnaliveProduct(void)
{
}
