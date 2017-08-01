#ifndef SOLIDCOLORSHADER_H
#define SOLIDCOLORSHADER_H

#include <GL\glew.h>

#include <GLM\matrix.hpp>

/// <summary> Will render the model in 3D space in a single color </summary>
class SolidColorShader
{
private:
	/// <summary> The Shader program </summary>
	GLuint _program = NULL;

	/// <summary> The color to be rendered </summary>
	glm::vec3 _color;
public:
	/// <summary> Will render the model in 3D space in a single color </summary>
	/// <param name="color"> The color to render the model </param>
	/// <param name="result"> The address of a bool which will store whether or not this operation was succesful </param>
	SolidColorShader(glm::vec3 color, bool* result);
	~SolidColorShader();

	/// <summary> Use the shader with the next thing we render </summary>
	void Start();

	/// <summary> Stop using this shader I want to use a different one </summary>
	void Stop();

	/// <summary> Update the Matrices to be loaded into the shader, must be called after start. </summary>
	/// <param name="M"> The position of the model in 3D space </param>
	/// <param name="V"> Translates everything dependent on the camera </param>
	/// <param name="P"> Gives everything some perspective </param>
	/// <param name = "NM"> The Inverse Transpose of the Model matrix, glm::inverseTranspose() </param>
	void Update(glm::mat4 M, glm::mat4 V, glm::mat4 P, glm::mat3 NM);
};

#endif