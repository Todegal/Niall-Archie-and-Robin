#include "SolidColorShader.h"

#include "shader.hpp"

SolidColorShader::SolidColorShader(glm::vec3 color, bool* result)
{
	_color = color;

	std::string vertexShader = "#version 440 core\n"
		"layout(location = 0) in vec3 pos;\n"
		"layout(location = 1) in vec3 norm;\n"
		"layout(location = 2) in vec2 uv;\n"

		"uniform mat4 M;\n"
		"uniform mat4 V;\n"
		"uniform mat4 P;\n"
		"uniform mat3 NM;\n"

		"uniform vec3 COLOR;\n"

		"out vec4 Colour;\n"
		"out vec3 Normal;\n"
		"out vec3 Position;\n"
		"void main()\n"
		"{\n"
		"Colour = vec4(vec3(1, 1, 1), 1);\n"

		"Normal = normalize(NM * norm);\n"
		"mat4 MVP = P * V * M;\n"


		"Position = (P * V * M * vec4(pos, 1.0)).xyz;\n"
		"gl_Position = MVP * vec4(pos, 1.0);\n"
		"};";

	std::string fragmentShader = "#version 440\n"

		"in vec3 Position;\n"
		"in vec4 Colour;\n"
		"in vec3 Normal;\n"

		"vec3 LightColour = vec3(0, 1, 1);\n"
		"vec3 LightDirection = vec3(-1, -1, 0);\n"
		"vec3 HalfVector = normalize(-LightDirection + normalize(-Position));\n"
		"float Shininess = 2;\n"
		"float Strength = 1;\n"
		"vec3 Ambient = vec3(0.2) * LightColour;\n"

		"out vec4 FragColour;\n"

		"void main() {\n"
		"	float diffuse = max(0.0, dot(Normal, LightDirection));\n"
		"	float specular = max(0.0, dot(Normal, HalfVector));\n"

		"	if (diffuse == 0.0)\n"
		"		specular = 0.0;\n"
		"	else\n"
		"		specular = pow(specular, Shininess);\n"

		"	vec3 scatteredLight = Ambient + LightColour * diffuse;\n"
		"	vec3 reflectedLight = LightColour * specular * Strength;\n"

		"	vec3 rgb = min((Colour.rgb * scatteredLight) + reflectedLight, vec3(1.0, 1.0, 1.0));\n"
		"	FragColour = vec4(rgb.x, rgb.y, rgb.z, 1.0);\n"
		"}";

	_program = LoadShaders(vertexShader, fragmentShader);

	if (_program == NULL)
	{
		*result = false;
		return;
	}

	*result = true;
	return;
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

void SolidColorShader::Update(glm::mat4 M, glm::mat4 V, glm::mat4 P, glm::mat3 NM)
{
	UniformMat4(M, "M", _program);
	UniformMat4(V, "V", _program);
	UniformMat4(P, "P", _program);
	UniformMat3(NM, "NM", _program);

	UniformVec3(_color, "COLOR", _program);
}