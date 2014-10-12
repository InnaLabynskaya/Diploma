#ifndef __PLUGINMANAGER__
#define __PLUGINMANAGER__

#include <windows.h>
#include "Category.h"
#include <vector>
#include <string>

typedef std::vector<Category*> Categories;

class PluginManager
{
public:
	PluginManager(const std::string& libraryPath);
	~PluginManager(void);
	const Categories& categories() {return m_categories;}
private:
	std::vector<HINSTANCE> m_plugins;
	Categories m_categories;
};

#endif
