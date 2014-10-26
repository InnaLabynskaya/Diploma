#include "BaseFactory.h"

BaseFactory::BaseFactory(void)
{
}

BackUp* BaseFactory::createBackUp(const std::string &path)
{
	return new BackUp(path.c_str());
}

BaseFactory::~BaseFactory(void)
{
}
