#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <GLM\common.hpp>

#include <vector>

/// <summary> Basic Model Data, No Shader and Will Render White </summary>
class RawModel
{
private:
	/// <summary> Vertex Array Object </summary>
	GLuint _vao;

	/// <summary> Number of Vertices </summary>
	int _size;
public:
	/// <summary> Load an OBJ file </summary>
	/// <param name="path"> The path of the model to load </param>
	RawModel(const char* path);
	~RawModel();

	/// <summary> Draw the Model </summary>
	void Draw();
};

#endif