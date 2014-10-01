#include "Category.h"
using namespace std;

Category::Category(const string &name, BaseFactory &factory):m_name(name)
{
	m_input = factory.createInput();
	m_output = factory.createOutput();
	m_sail = factory.createSail();
	m_load = factory.createLoad();
}

Category::~Category(void)
{
	delete m_input;
	delete m_output;
	delete m_sail;
	delete m_load;
}
