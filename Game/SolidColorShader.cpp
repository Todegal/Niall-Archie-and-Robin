#include "SolidColorShader.h"

#include "shader.hpp"

SolidColorShader::SolidColorShader(glm::vec3 color)
{
	_color = color;

	_program = LoadShaders("SolidColorShader.vs.glsl", "SolidColorShader.fs.glsl");
}

SolidColorShader::~SolidColorShader()
{
}

void SolidColorShader::Start()
{
	glUseProgram(_program);
}

void SolidColorShader::Stop()
{
	glUseProgram(0);
}

void SolidColorShader::Update(glm::mat4 M, glm::mat4 V, glm::mat4 P)
{
	UniformMat4(M, "M", _program);
	UniformMat4(V, "V", _program);
	UniformMat4(P, "P", _program);

	UniformVec3(_color, "COLOR", _program);
}