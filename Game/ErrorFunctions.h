#ifndef ERRORFUN_H
#define ERRORFUN_H

/// <summary> Print Error Message then Press Any Key To Continue then Stops Game, You MUST return whatever you're in after calling this function </summary>
/// <param name="message"> Message to be Printed </param>
void Error(const char* message);

/// <summary> Prints Warning Message </summary>
/// <param name="message> Message to be Printed </param>
void Warning(const char* message);

#endif // !ERRORFUN_H
