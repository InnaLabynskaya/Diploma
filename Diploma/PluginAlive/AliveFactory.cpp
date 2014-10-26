#include "AliveFactory.h"
#include "AliveInput.h"
#include "AliveOutput.h"
#include "AliveSave.h"
#include "AliveLoad.h"
using namespace std;

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

BaseSave* AliveFactory::createSave(BackUp* backup)
{
	return new AliveSave(backup);
}

BaseLoad* AliveFactory::createLoad(BackUp* backup)
{
	return new AliveLoad(backup);
}