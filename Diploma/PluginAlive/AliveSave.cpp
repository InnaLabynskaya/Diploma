#include "AliveSave.h"
using namespace std;

AliveSave::AliveSave(BackUp* backup):BaseSave(backup)
{
}

size_t aliveProductBinnarySize(AliveProduct* product)
{
	//product->m_age int32
	//product->m_light bool
	//product->m_name string
	//product->m_price float
	//product->m_quantity uint32
	return sizeof(unsigned __int32) + 
		sizeof(bool) + 
		product->name().length()+1 +
		sizeof(float) +
		sizeof(unsigned __int32);
}

char* writeToBuf(AliveProduct* product, char* buf)
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
	unsigned __int32 age = product->getAge();
	memcpy(buf, &age, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	bool light = product->getLight();
	memcpy(buf, &light, sizeof(bool));
	buf += sizeof(bool);

	float price = product->getPrice();
	memcpy(buf, &price, sizeof(float));
	buf += sizeof(float);

	unsigned __int32 quantity = product->getQuantity();
	memcpy(buf, &quantity, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	size_t length = product->name().length() + 1;
	strncpy(buf, product->name().c_str(), length);
	buf += length;

	return buf;
}

void AliveSave::save(const std::vector<Product*> &products)
{
	static char header[] = "Alive";
	size_t binnarySize = sizeof(header);
	vector<Product*>::const_iterator it;
	for(it = products.begin(); it != products.end(); it++)
	{
		binnarySize += aliveProductBinnarySize((AliveProduct*)*it);
	}
	char* data = new char [binnarySize];
	strncpy(data, header, sizeof(header));
	char* buf = data + sizeof(header);
	for(it = products.begin(); it != products.end(); it++)
	{
		buf = writeToBuf((AliveProduct*)*it, buf);
	}
	m_backup->write(data, binnarySize);
	delete[] data;
}

AliveSave::~AliveSave(void)
{
}
