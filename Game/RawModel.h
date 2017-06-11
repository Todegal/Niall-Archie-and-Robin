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

	/// <summary> Create A RawModel from Hard Coded Data </summary>
	/// <param name="positions"> 3-Dimensional vertex information </param>
	/// <param name="indices"> Element Data </param>
	RawModel(std::vector<glm::vec3> positions, std::vector<unsigned int> indices);
	~RawModel();

	/// <summary> Draw the Model </summary>
	void Draw();
};

#endif