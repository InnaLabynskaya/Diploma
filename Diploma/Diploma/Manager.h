#ifndef __MANAGER__
#define __MANAGER__
#include "role.h"

class Manager :
	public Role
{
public:
	Manager(const Categories& categories);
	virtual ~Manager(void);
protected:
	virtual void options(Shop* shop);
};

#endif
