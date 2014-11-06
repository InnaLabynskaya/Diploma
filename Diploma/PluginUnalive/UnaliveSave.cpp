#include "UnaliveSave.h"
using namespace std;

UnaliveSave::UnaliveSave(BackUp* backup):BaseSave(backup)
{
}

size_t unaliveProductBinnarySize(UnaliveProduct* product)
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

char* writeToBuf(UnaliveProduct* product, char* buf)
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
	unsigned __int32 expirationDate = product->getExpirationDate();
	memcpy(buf, &expirationDate, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

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

void UnaliveSave::save(const std::vector<Product*> &products)
{
	static char header[] = "Unalive";
	size_t binnarySize = sizeof(header);
	vector<Product*>::const_iterator it;
	for(it = products.begin(); it != products.end(); it++)
	{
		binnarySize += unaliveProductBinnarySize((UnaliveProduct*)*it);
	}
	char* data = new char [binnarySize];
	strncpy(data, header, sizeof(header));
	char* buf = data + sizeof(header);
	for(it = products.begin(); it != products.end(); it++)
	{
		buf = writeToBuf((UnaliveProduct*)*it, buf);
	}
	m_backup->write(data, binnarySize);
	delete[] data;
}

UnaliveSave::~UnaliveSave(void)
{
}
