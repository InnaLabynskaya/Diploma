#include <windows.h>
#include "PluginAPI.h"
#include "AliveFactory.h"
#include <iostream>
using namespace std;

static Category* p_category;

extern "C" DLLAPI BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {  
        case DLL_PROCESS_ATTACH:
			p_category = new Category("Alive", AliveFactory());
            break;

        case DLL_PROCESS_DETACH:
			delete p_category;
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}

Category* getCategory(void)
{
	return p_category;
}
