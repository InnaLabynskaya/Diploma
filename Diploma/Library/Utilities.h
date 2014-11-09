#ifndef __UTILITIES__
#define __UTILITIES__

#include <string>

class Utilities
{
public:
	static char inputChar();
	static int intputInteger();
	static float inputFloat();
	static bool inputBool();
	static std::string inputString();
	static void waitForInput();
	static void clearScreen();
};

#endif