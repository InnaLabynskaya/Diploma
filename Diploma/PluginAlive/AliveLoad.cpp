#include "AliveLoad.h"
using namespace std;

AliveLoad::AliveLoad(BackUp* backup):BaseLoad(backup)
{
}

AliveProduct* readFromBuf(char* &buf)
{
	//product->m_age int32
	//product->m_light bool
	//product->m_name string
	//product->m_price float
	//product->m_quantity uint32

	//  sizeof(unsigned __int32) + 
	//	sizeof(bool) + 
	//	product->name().length()+1 +
	//	sizeof(float) +
	//	sizeof(unsigned __int32);
	unsigned __int32 age = 0;
	memcpy(&age, buf, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	bool light = 0;
	memcpy(&light, buf, sizeof(bool));
	buf += sizeof(bool);

	float price = 0;
	memcpy(&price, buf, sizeof(float));
	buf += sizeof(float);

	unsigned __int32 quantity = 0;
	memcpy(&quantity, buf, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	AliveProduct *product = new AliveProduct(buf);
	buf += product->name().length()+1;

	product->setAge(age);
	product->setLight(light);
	product->setPrice(price);
	product->setQuantity(quantity);

	return product;
}

void AliveLoad::load(std::vector<Product*> &products)
{
	static char header[] = "Alive";
	int binnarySize = 0;
	char* data = (char*)m_backup->read(&binnarySize);
	char* buf = data;
	bool valid = strncmp(header, buf, sizeof(header)) == 0;
	if (valid) 
	{
		buf += sizeof(header);
		while (buf - data < binnarySize) 
		{
			products.push_back(readFromBuf(buf));
		}
	}
	delete[] data;
}

AliveLoad::~AliveLoad(void)
{
}
