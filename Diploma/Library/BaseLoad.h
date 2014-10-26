#ifndef __BASE_LOAD__
#define __BASE_LOAD__
#include <string>
#include <vector>
#include "Product.h"
#include "Backup.h"

class BaseLoad
{
public:
	BaseLoad(BackUp* backup);
	virtual void load(std::vector<Product*> &products) = 0;
	virtual ~BaseLoad(void);
protected:
	BackUp* m_backup;
};

#endif