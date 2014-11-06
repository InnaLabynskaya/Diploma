#include "UnaliveLoad.h"
#include "UnaliveProduct.h"
using namespace std;

UnaliveLoad::UnaliveLoad(BackUp* backup):BaseLoad(backup)
{
}

UnaliveProduct* readFromBuf(char* &buf)
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
	unsigned __int32 expirationDate = 0;
	memcpy(&expirationDate, buf, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	float price = 0;
	memcpy(&price, buf, sizeof(float));
	buf += sizeof(float);

	unsigned __int32 quantity = 0;
	memcpy(&quantity, buf, sizeof(unsigned __int32));
	buf += sizeof(unsigned __int32);

	UnaliveProduct *product = new UnaliveProduct(buf);
	buf += product->name().length()+1;

	product->setExpirationDate(expirationDate);
	product->setPrice(price);
	product->setQuantity(quantity);

	return product;
}

void UnaliveLoad::load(std::vector<Product*> &products)
{
	static char header[] = "Unalive";
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

UnaliveLoad::~UnaliveLoad(void)
{
}
