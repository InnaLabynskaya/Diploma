#ifndef __BASE_INPUT__
#define __BASE_INPUT__
#include "Product.h"

class BaseInput
{
public:
	BaseInput(void);
	virtual Product* createProduct() = 0;
	virtual ~BaseInput(void);
};

#endif
