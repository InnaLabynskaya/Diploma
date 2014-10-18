#include "AliveFactory.h"
#include "AliveInput.h"
#include "AliveOutput.h"

AliveFactory::AliveFactory(void)
{
}


AliveFactory::~AliveFactory(void)
{
}

BaseInput* AliveFactory::createInput()
{
	return new AliveInput();
}

BaseOutput* AliveFactory::createOutput()
{
	return new AliveOutput();
}

BaseSave* AliveFactory::createSave()
{
	return 0;
}

BaseLoad* AliveFactory::createLoad()
{
	return 0;
}