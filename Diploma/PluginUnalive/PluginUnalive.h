// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PLUGINUNALIVE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PLUGINUNALIVE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PLUGINUNALIVE_EXPORTS
#define PLUGINUNALIVE_API __declspec(dllexport)
#else
#define PLUGINUNALIVE_API __declspec(dllimport)
#endif

// This class is exported from the PluginUnalive.dll
class PLUGINUNALIVE_API CPluginUnalive {
public:
	CPluginUnalive(void);
	// TODO: add your methods here.
};

extern PLUGINUNALIVE_API int nPluginUnalive;

PLUGINUNALIVE_API int fnPluginUnalive(void);
