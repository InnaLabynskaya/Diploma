#ifndef __UNALIVEFACTORY__
#define __UNALIVEFACTORY__
#include "basefactory.h"
#include "BaseOutput.h"

class UnaliveFactory :
	public BaseFactory
{
public:
	UnaliveFactory(void);
	virtual ~UnaliveFactory(void);
	virtual BaseInput* createInput();
	virtual BaseOutput* createOutput();
	virtual BaseSave* createSave(BackUp* backup);
	virtual BaseLoad* createLoad(BackUp* backup);
};

#endif