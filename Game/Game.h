#ifndef GAME_H
#define GAME_H

#include <GLM\common.hpp>
#include <GLM\gtc\matrix_transform.hpp>

#include "RawModel.h"
#include "SolidColorShader.h"

/// <summary> Static Game Class </summary>
class Game
{
private:
	/// <summary> Render the Game </summary>
	static void _Render();

	/// <summary> Update the Game </summary>
	static void _Update();

	/// <summary> Is the Game Running </summary>
	static bool _isRunning;

	/// <summary> Run the Game Loop </summay>
	static void _Run();

	/// <summary> Close the Game </summary>
	static void _Close();

	static RawModel* _model;
	static SolidColorShader* _shader;
	/// <summary> Is going fullscreen Allowed, to save Game object positions and the like </summary>
	static bool fullscreenAllowed;
public:
	/// <summary> Starts the Game </summary>
	static void Start();
	/// <summary> Stop the Game </summary>
	static void Stop();
	/// <summary> Create all GLEW dependent objects </summary>
	static void Create();

	/// <summary> Clear the Screen </summary>
	/// <param name="color"> The color to clear the screen </param>
	static void Clear(glm::vec3 color = { 0, 0, 0 });
};

#endif
