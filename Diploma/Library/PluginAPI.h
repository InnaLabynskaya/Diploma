#ifndef __PLUGIN_API__
#define __PLUGIN_API__

#ifdef BUILD_PLUGIN_DLL
	#define DLLAPI __declspec(dllexport)
#else
	#define DLLAPI
#endif

#include "ShopLibrary.h"

DLLAPI Category* getCategory();

#endif
