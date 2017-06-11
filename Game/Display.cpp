#include "Display.h"

#include "ErrorFunctions.h"

#include "Game.h"

//Extern Variables
GLFWwindow* Display::window = NULL;
int Display::width = 800, Display::height = 600;
const char* Display::title = "Game";
bool Display::fullscreen = false;

bool Display::Init()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		Error("Failed to Initialize GLFW");
		return false;
	}

	// Create the Window
	window = Display::Create();
	
	return true;
}

bool Display::Destroy(GLFWwindow* window)
{
	glfwDestroyWindow(window);

	return true;
}

GLFWwindow* Display::Create()
{
	GLFWwindow* window = NULL;

	// Set glfw window RECOMMENDATIONS, not guarenteed
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	/// <summary> Your Monitor's Video Settings </summary>
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// Customize the display to your monitor
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	// If fullscreen
	if (Display::fullscreen)
	{
		// Create the window stretched to your moniter
		window = glfwCreateWindow(mode->width, mode->height, Display::title, glfwGetPrimaryMonitor(), NULL);
	}
	else
	{
		// Create the window normally
		window = glfwCreateWindow(Display::width, Display::height, Display::title, NULL, NULL);
	}

	// Window creation failed
	if (window == NULL)
	{
		Error("Failed to Create Window");
		return NULL;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		Error("Failed to Init GLEW");
		return NULL;
	}

	return window;
}

void Display::Fullscreen(bool fullscreen)
{
	Display::fullscreen = fullscreen;

	Display::Destroy(Display::window);
	Display::window = Display::Create();

	Game::Create();
}

void Display::SwapBuffers()
{
	glfwSwapBuffers(window);
}

bool Display::Close()
{
	glfwTerminate();

	window = NULL;

	return true;
}