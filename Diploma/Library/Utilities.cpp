#include "Utilities.h"
#include <iostream>
#include <string>
using namespace std;

static const unsigned int size = 64;
static char buffer[size];


char Utilities::inputChar()
{
	cin.getline(buffer, size);
	return buffer[0];
}

int Utilities::intputInteger()
{
	cin.getline(buffer, size);
	return atoi(buffer);
}

float Utilities::inputFloat()
{
	cin.getline(buffer, size);
	return (float)atof(buffer);
}

bool Utilities::inputBool()
{
	cin.getline(buffer, size);
	return buffer[0] == 'y';
}

string Utilities::inputString()
{
	cin.getline(buffer, size);
	return buffer;
}

void Utilities::waitForInput()
{
	system("pause");
}

void Utilities::clearScreen()
{
	system("cls");
}
