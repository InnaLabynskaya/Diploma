#ifndef __CATEGORY__
#define __CATEGORY__
#include <string>
#include "BaseFactory.h"

class Category
{
public:
	Category(const std::string &name, BaseFactory &factory);
	const std::string& name() const {return m_name;}
	BaseInput* input() {return m_input;}
	BaseOutput* output() {return m_output;}
	BaseSave* Save() {return m_Save;}
	BaseLoad* load() {return m_load;}
	~Category(void);
private:
	std::string m_name;
	BaseInput* m_input;
	BaseOutput* m_output;
	BaseSave* m_Save;
	BaseLoad* m_load;
};

#endif
