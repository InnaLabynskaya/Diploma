#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__
#include "BaseInput.h"
#include "BaseOutput.h"
#include "BaseSail.h"
#include "BaseLoad.h"

class BaseFactory
{
public:
	BaseFactory(void);
	virtual BaseInput* createInput() = 0;
	virtual BaseOutput* createOutput() = 0;
	virtual BaseSail* createSail() = 0;
	virtual BaseLoad* createLoad() = 0;
	virtual ~BaseFactory(void);
};

#endif