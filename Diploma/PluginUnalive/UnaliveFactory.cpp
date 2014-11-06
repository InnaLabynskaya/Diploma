#include "UnaliveOutput.h"
#include "UnaliveInput.h"
#include "UnaliveFactory.h"
#include "UnaliveSave.h"
#include "UnaliveLoad.h"

using namespace std;

UnaliveFactory::UnaliveFactory(void)
{
}


UnaliveFactory::~UnaliveFactory(void)
{
}

BaseInput* UnaliveFactory::createInput()
{
	return new UnaliveInput();
}

BaseOutput* UnaliveFactory::createOutput()
{
	return new UnaliveOutput();
}

BaseSave* UnaliveFactory::createSave(BackUp* backup)
{
	return new UnaliveSave(backup);
}

BaseLoad* UnaliveFactory::createLoad(BackUp* backup)
{
	return new UnaliveLoad(backup);
}