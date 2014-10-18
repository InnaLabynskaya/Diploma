#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__
#include "BaseInput.h"
#include "BaseOutput.h"
#include "BaseSave.h"
#include "BaseLoad.h"

class BaseFactory
{
public:
	BaseFactory(void);
	virtual BaseInput* createInput() = 0;
	virtual BaseOutput* createOutput() = 0;
	virtual BaseSave* createSave() = 0;
	virtual BaseLoad* createLoad() = 0;
	virtual ~BaseFactory(void);
};

#endif