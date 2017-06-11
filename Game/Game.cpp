#include "Game.h"

#include "Display.h"

// Static variables
bool Game::_isRunning = false;
RawModel* Game::_model = NULL;
SolidColorShader* Game::_shader = NULL;
bool Game::fullscreenAllowed = true;

void Game::_Render()
{
	glm::mat4 m = glm::mat4(1.0f);
	glm::mat4 v = glm::lookAt(glm::vec3(0, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 p = glm::perspective(45.0f, (float)Display::width / (float)Display::height, 0.1f, 100.0f);

	// Clear the screen
	Clear();

	_shader->Start();

	_shader->Update(m, v, p);

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

	if ((glfwGetKey(Display::window, GLFW_KEY_F) == GLFW_PRESS) && fullscreenAllowed)
	{
		Display::Fullscreen(!Display::fullscreen);
	}

	if (glfwGetKey(Display::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		Stop();
	}

}

void Game::_Run()
{
	// Main game Loop
	while (_isRunning)
	{
		_Update();

		_Render();
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
	_model = new RawModel({ { -0.5f, -0.5f, 0.0f },
	{ 0.0f, 0.5f, 0.0f },
	{ 0.5f, -0.5f, 0.0f }
	}, { 0, 1, 2 });

	_shader = new SolidColorShader({ 1, 0, 0 });
}

void Game::Clear(glm::vec3 color)
{
	// Set the clear color
	glClearColor(color.r, color.g, color.b, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
