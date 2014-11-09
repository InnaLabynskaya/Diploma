#ifndef __ROLE__
#define __ROLE__
#include "Category.h"
#include "Shop.h"

class Role
{
public:
	Role(const Categories& categories);
	virtual void run();
	virtual ~Role(void);
protected:
	virtual void options(Shop* shop) = 0;
	const Categories& m_categories;
};

#endif
