#include "Game.h"

#include "Display.h"

#include <GLM\gtc\matrix_inverse.hpp>

// Static variables
bool Game::_isRunning = false;
RawModel* Game::_model = NULL;
SolidColorShader* Game::_shader = NULL;
bool Game::fullscreenAllowed = true;
double Game::_deltaTime = 0.0;

glm::vec3 position = glm::vec3(0, 0, -3);

glm::mat4 m = glm::mat4(1.0f);
glm::mat3 nm = glm::inverseTranspose(m);

void Game::_Render()
{
	glm::mat4 p = glm::perspective(45.0f, (float)Display::width / (float)Display::height, 0.1f, 100.0f);
	glm::mat4 v = glm::lookAt(position, position + glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));

	// Clear the screen
	Clear();

	_shader->Start();

	_shader->Update(m, v, p, nm);

	// Draw Model
	_model->Draw();

	_shader->Stop();

	Display::SwapBuffers();
}

void Game::_Update()
{
	// Check for input
	glfwPollEvents();

	if (glfwWindowShouldClose(Display::window))
	{
		Stop();
	}

	if ((glfwGetKey(Display::window, GLFW_KEY_F) != GLFW_RELEASE) && fullscreenAllowed)
	{
		Display::Fullscreen(!Display::fullscreen);
	}

	if (glfwGetKey(Display::window, GLFW_KEY_ESCAPE) != GLFW_RELEASE)
	{
		Stop();
	}

	if (glfwGetKey(Display::window, GLFW_KEY_W) != GLFW_RELEASE)
	{
		position += glm::vec3(0, 0, (3 * Game::_deltaTime));
	}

	if (glfwGetKey(Display::window, GLFW_KEY_S) != GLFW_RELEASE)
	{
		position -= glm::vec3(0, 0, (3 * Game::_deltaTime));
	}

	if (glfwGetKey(Display::window, GLFW_KEY_A) != GLFW_RELEASE)
	{
		position += glm::vec3((3 * Game::_deltaTime), 0, 0);
	}

	if (glfwGetKey(Display::window, GLFW_KEY_D) != GLFW_RELEASE)
	{
		position -= glm::vec3((3 * Game::_deltaTime), 0, 0);
	}

}

void Game::_Run()
{
	// Main game Loop
	while (_isRunning)
	{
		double sTime = glfwGetTime();

		_Update();

		_Render();

		double tTime = glfwGetTime();
		Game::_deltaTime = tTime - sTime;
	}

	_Close();

}

void Game::_Close()
{
	if (Display::Close())
	{
		return;
	}
}

void Game::Start()
{
	// Init the Display
	if (!Display::Init())
	{
		return;
	}

	_isRunning = true;

	Create();

	_Run();
}

void Game::Stop()
{
	_isRunning = false;
}

void Game::Create()
{
	// Create Model;
	_model = new RawModel("Monkey.obj");

	_shader = new SolidColorShader({ 1, 0, 0 });
}

void Game::Clear(glm::vec3 color)
{
	// Set the clear color
	glClearColor(color.r, color.g, color.b, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
