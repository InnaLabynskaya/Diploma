#ifndef __UNALIVEINPUT__
#define __UNALIVEINPUT__
#include "baseinput.h"
#include "UnaliveProduct.h"

class UnaliveInput :
	public BaseInput
{
public:
	UnaliveInput(void);
	virtual Product* createProduct();
	virtual void modifyProduct(Product* product);
	virtual ~UnaliveInput(void);
};

#endif