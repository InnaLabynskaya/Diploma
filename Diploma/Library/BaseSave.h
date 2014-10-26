#ifndef __BASE_SAVE__
#define __BASE_SAVE__
#include <string>
#include <vector>
#include "Product.h"
#include "Backup.h"

class BaseSave
{
public:
	BaseSave(BackUp* backup);
	virtual void save(const std::vector<Product*> &products) = 0;
	virtual ~BaseSave(void);
protected:
	BackUp* m_backup;
};

#endif