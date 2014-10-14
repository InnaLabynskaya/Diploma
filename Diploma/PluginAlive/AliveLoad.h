#ifndef __ALIVELOAD__
#define __ALIVELOAD__
#include "baseload.h"
#include "AliveProduct.h"

class AliveLoad :
	public BaseLoad
{
public:
	AliveLoad(void);
	virtual ~AliveLoad(void);
};

#endif