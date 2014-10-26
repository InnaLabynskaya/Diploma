#include "Category.h"
using namespace std;
#define SAVE_DELETE(_obj_) if(_obj_)delete(_obj_)

const string dataBasePath = "alive.database";

Category::Category(const string &name, BaseFactory &factory):m_name(name)
{
	m_input = factory.createInput();
	m_output = factory.createOutput();
	m_backup = factory.createBackUp(dataBasePath);
	m_save = factory.createSave(m_backup);
	m_load = factory.createLoad(m_backup);
}

Category::~Category(void)
{
	SAVE_DELETE(m_input);
	SAVE_DELETE(m_output);
	SAVE_DELETE(m_save);
	SAVE_DELETE(m_load);
	SAVE_DELETE(m_backup);
}
