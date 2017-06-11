#ifndef ERRORFUN_H
#define ERRORFUN_H

#include <iostream>
#include "Game.h"

/// <summary> Print Error Message then Press Any Key To Continue then Stops Game, You MUST return whatever you're in after calling this function </summary>
/// <param name="message"> Message to be Printed </param>
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

/// <summary> Prints Warning Message </summary>
/// <param name="message> Message to be Printed </param>
void Warning(const char* message)
{
	std::cerr << message << std::endl;
}

#endif // !ERRORFUN_H
