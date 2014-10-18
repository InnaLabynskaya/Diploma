#ifndef __ALIVEFACTORY__
#define __ALIVEFACTORY__
#include "basefactory.h"

class AliveFactory :
	public BaseFactory
{
public:
	AliveFactory(void);
	virtual ~AliveFactory(void);
	virtual BaseInput* createInput();
	virtual BaseOutput* createOutput();
	virtual BaseSave* createSave();
	virtual BaseLoad* createLoad();
};

#endif