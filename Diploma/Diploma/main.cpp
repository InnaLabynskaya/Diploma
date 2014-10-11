#include <iostream>
#include "PluginAPI.h"
#include <windows.h>
using namespace std;

int main()
{
	WIN32_FIND_DATA fileData;
	HANDLE fileHandler = FindFirstFile("C:\\Users\\Inna\\Documents\\GitHub\\Diploma\\Diploma\\Debug\\*.dll", &fileData);
	if (fileHandler == (void*)ERROR_INVALID_HANDLE ||
		fileHandler == (void*)ERROR_FILE_NOT_FOUND)
	{
		cout<<"No plugins found!\n";
	}
	else
	{
		cout<<fileData.cFileName<<"\n";
		HINSTANCE plugin = LoadLibrary(fileData.cFileName);
		if (!plugin)
		{
			cout<<"Can't open dll: "<< fileData.cFileName <<"\n";
		}
		else
		{
			typedef Category* (__cdecl *CategoryProc)(void);
			CategoryProc categoryFunc = (CategoryProc) GetProcAddress(plugin, "?getCategory@@YAPAVCategory@@XZ"); 
			if(!categoryFunc)
				cout<<"Function GetCategory not found in dll: "<< fileData.cFileName <<"\n";
			else
				cout<<"Library "<< fileData.cFileName <<" was loaded\n"; 
			Category *cat = categoryFunc();
			cout << cat->name() << endl;
			FreeLibrary(plugin);
		}
		FindClose(fileHandler);
	}
	return 0;
}