#ifndef __UNALIVEOUTPUT__
#define __UNALIVEOUTPUT__
#include "baseoutput.h"
#include "UnaliveProduct.h"

class UnaliveOutput :
	public BaseOutput
{
public:
	UnaliveOutput();
	virtual void show(Product* product);
	virtual void show(const std::vector<Product*>& products);
	virtual ~UnaliveOutput(void);
protected:
	virtual void showHeader();
	virtual void showData(UnaliveProduct* product);
};

#endif