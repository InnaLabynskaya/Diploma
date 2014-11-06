#ifndef __UNALIVESAVE__
#define __UNALIVESAVE__
#include "basesave.h"
#include "UnaliveProduct.h"

class UnaliveSave :
	public BaseSave
{
public:
	UnaliveSave(BackUp* backup);
	virtual void save(const std::vector<Product*> &products);
	virtual ~UnaliveSave(void);
};

#endif