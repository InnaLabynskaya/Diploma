#include "AliveProduct.h"


AliveProduct::AliveProduct(const std::string &name):Product(name)
{
	m_light = false;
	m_age = 0;
}


bool AliveProduct::getLight()
{
	return m_light;
}

void AliveProduct::setLight(bool light)
{
	m_light = light;
}

int AliveProduct::getAge()
{
	return m_age;
}

void AliveProduct::setAge(int age)
{
	m_age = age;
}


AliveProduct::~AliveProduct(void)
{
}
