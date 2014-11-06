#ifndef __UNALIVELOAD__
#define __UNALIVELOAD__
#include "baseload.h"

class UnaliveLoad :
	public BaseLoad
{
public:
	UnaliveLoad(BackUp* backup);
	virtual void load(std::vector<Product*> &products);
	virtual ~UnaliveLoad(void);
};

#endif