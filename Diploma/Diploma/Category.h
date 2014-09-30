#ifndef __CATEGORY__
#define __CATEGORY__
#include <string>

class Category
{
public:
	Category(const std::string &name);
	~Category(void);
	const std::string& name() const {return m_name;}
private:
	std::string m_name;
};

#endif
