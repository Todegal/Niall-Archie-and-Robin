#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

/// <summary> Universal Display Namespace </summary>
namespace Display
{
	/// <summary> GLFW Window Pointer </summary>
	extern GLFWwindow* window;

	/// <summary> Width and Height of the Window </summary>
	extern int width, height;
	extern int fWidth, fHeight;

	/// <summary> Title of the Window </summary>
	extern const char* title;

	/// <summary> Is Window Fullscreen </summary>
	extern bool fullscreen;

	/// <summary> Initialize the Display </summary>
	/// <returns> Initialization Succesful </returns>
	bool Init();

	/// <summary> Close the Display </summary>
	/// <returns> Success </returns>
	bool Close();

	/// <summary> Destroy the Window </summary>
	/// <returns> Succes? </returns>
	bool Destroy(GLFWwindow* window);

	/// <summary> Create the Window </summary>
	/// <returns> Succes? </returns>
	GLFWwindow* Create();

	/// <summary> Change fullscreen State </summary>
	/// <param name="fullscreen"> Fullscreen state </param>
	void Fullscreen(bool fullscreen);

	/// <summary> Swap the FrontBuffer with the BackBuffer </summary>
	void SwapBuffers();
}

#endif // !DISPLAY_H
