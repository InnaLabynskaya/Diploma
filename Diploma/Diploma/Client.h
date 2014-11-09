#ifndef __CLIENT__
#define __CLIENT__
#include "role.h"

class Client :
	public Role
{
public:
	Client(const Categories& categories);
	virtual ~Client(void);
protected:
	virtual void options(Shop* shop);
};

#endif
