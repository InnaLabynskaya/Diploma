#ifndef __ALIVELOAD__
#define __ALIVELOAD__
#include "baseload.h"
#include "AliveProduct.h"

class AliveLoad :
	public BaseLoad
{
public:
	AliveLoad(BackUp* backup);
	virtual void load(std::vector<Product*> &products);
	virtual ~AliveLoad(void);
};

#endif