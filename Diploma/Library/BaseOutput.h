#ifndef __BASE_OUTPUT__
#define __BASE_OUTPUT__
#include "Product.h"
#include <vector>

class BaseOutput
{
public:
	BaseOutput(void);
	virtual void show(Product* product) = 0;
	virtual void show(const std::vector<Product*>& products) = 0;
	virtual ~BaseOutput(void);
};

#endif
