#include "Category.h"
using namespace std;
#define SAVE_DELETE(_obj_) if(_obj_)delete(_obj_)

Category::Category(const string &name, BaseFactory &factory):m_name(name)
{
	m_input = factory.createInput();
	m_output = factory.createOutput();
	m_sail = factory.createSail();
	m_load = factory.createLoad();
}

Category::~Category(void)
{
	SAVE_DELETE(m_input);
	SAVE_DELETE(m_output);
	SAVE_DELETE(m_sail);
	SAVE_DELETE(m_load);
}
