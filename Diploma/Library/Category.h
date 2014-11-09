#ifndef __CATEGORY__
#define __CATEGORY__
#include <string>
#include <vector>
#include "BaseFactory.h"

class Category;

typedef std::vector<Category*> Categories;

class Category
{
public:
	Category(const std::string &name, BaseFactory &factory);
	const std::string& name() const {return m_name;}
	BaseInput* input() {return m_input;}
	BaseOutput* output() {return m_output;}
	BaseSave* save() {return m_save;}
	BaseLoad* load() {return m_load;}
	~Category(void);
protected:
	BackUp* backup() {return m_backup;}
private:
	std::string m_name;
	BaseInput* m_input;
	BaseOutput* m_output;
	BaseSave* m_save;
	BaseLoad* m_load;
	BackUp* m_backup;
};

#endif
