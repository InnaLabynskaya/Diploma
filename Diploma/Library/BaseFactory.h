#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__
#include "BaseInput.h"
#include "BaseOutput.h"
#include "BaseSave.h"
#include "BaseLoad.h"
#include "Backup.h"

class BaseFactory
{
public:
	BaseFactory(void);
	virtual BaseInput* createInput() = 0;
	virtual BaseOutput* createOutput() = 0;
	virtual BaseSave* createSave(BackUp* backup) = 0;
	virtual BaseLoad* createLoad(BackUp* backup) = 0;
	virtual BackUp* createBackUp(const std::string &path);
	virtual ~BaseFactory(void);
};

#endif