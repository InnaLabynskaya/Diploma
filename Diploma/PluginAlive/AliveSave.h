#ifndef __ALIVE_SAVE__
#define __ALIVE_SAVE__
#include "baseSave.h"
#include "AliveProduct.h"

class AliveSave :
	public BaseSave
{
public:
	AliveSave(BackUp* backup);
	virtual void save(const std::vector<Product*> &products);
	virtual ~AliveSave(void);
};

#endif