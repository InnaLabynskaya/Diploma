// PluginUnalive.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PluginUnalive.h"


// This is an example of an exported variable
PLUGINUNALIVE_API int nPluginUnalive=0;

// This is an example of an exported function.
PLUGINUNALIVE_API int fnPluginUnalive(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see PluginUnalive.h for the class definition
CPluginUnalive::CPluginUnalive()
{
	return;
}
