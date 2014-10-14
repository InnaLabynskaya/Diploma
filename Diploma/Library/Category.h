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
	BaseSail* sail() {return m_sail;}
	BaseLoad* load() {return m_load;}
	~Category(void);
private:
	std::string m_name;
	BaseInput* m_input;
	BaseOutput* m_output;
	BaseSail* m_sail;
	BaseLoad* m_load;
};

#endif
