#ifndef __ALIVEPRODUCT__
#define __ALIVEPRODUCT__
#include "product.h"

class AliveProduct :
	public Product
{
public:
	AliveProduct(const std::string &name);
	~AliveProduct(void);
	bool getLight();
	void setLight(bool light);
	int getAge();
	void setAge(int age);
private:
	bool m_light;
	int m_age;
};

#endif
