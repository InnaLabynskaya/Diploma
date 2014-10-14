#ifndef __ALIVEINPUT__
#define __ALIVEINPUT__
#include "baseinput.h"
#include "AliveProduct.h"

class AliveInput :
	public BaseInput
{
public:
	AliveInput(void);
	virtual Product* createProduct();
	virtual ~AliveInput(void);
};

#endif