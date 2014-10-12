#include "PluginManager.h"
#include "PluginAPI.h"
using namespace std;

PluginManager::PluginManager(const string& libraryPath)
{
	WIN32_FIND_DATA fileData;
	HANDLE fileHandler = FindFirstFile((libraryPath+"*.dll").c_str(), &fileData);
	if (fileHandler != (void*)ERROR_INVALID_HANDLE &&
		fileHandler != (void*)ERROR_FILE_NOT_FOUND)
	{
		do
		{
			HINSTANCE plugin = LoadLibrary(fileData.cFileName);
			if (plugin)
			{
				typedef Category* (__cdecl *CategoryProc)(void);
				CategoryProc categoryFunc = (CategoryProc) GetProcAddress(plugin, "?getCategory@@YAPAVCategory@@XZ"); 
				if(categoryFunc)
				{
					Category *cat = categoryFunc();
					m_categories.push_back(cat);
					m_plugins.push_back(plugin);
				}
				else
				{
					FreeLibrary(plugin);
				}
			}
		}
		while (FindNextFile(fileHandler, &fileData));
		FindClose(fileHandler);
	}
}


PluginManager::~PluginManager(void)
{
	vector<HINSTANCE>::iterator it;
	for (it = m_plugins.begin(); it != m_plugins.end(); ++it)
	{
		FreeLibrary(*it);
	}
}
