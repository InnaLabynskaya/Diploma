#ifndef __ALIVEOUTPUT__
#define __ALIVEOUTPUT__
#include "baseoutput.h"
#include "AliveProduct.h"

class AliveOutput :
	public BaseOutput
{
public:
	AliveOutput(void);
	virtual void show(Product* product);
	virtual void show(const std::vector<Product*>& products);
	virtual ~AliveOutput(void);
protected:
	virtual void showHeader();
	virtual void showData(AliveProduct* product);
};

#endif