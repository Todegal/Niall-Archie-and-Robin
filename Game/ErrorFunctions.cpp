#include "ErrorFunctions.h"

#include <iostream>
#include "Game.h"

void Error(const char* message)
{
	std::cerr << message << std::endl;

#ifdef _WIN32
	system("pause");
#else
	int a;
	std::cin >> a;
#endif

	Game::Stop();
}

void Warning(const char* message)
{
	std::cerr << message << std::endl;
}