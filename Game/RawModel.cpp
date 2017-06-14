#include "RawModel.h"

#include "objloader.hpp"

RawModel::RawModel(const char* path)
{
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	loadAssImp(path, indices, positions, uvs, normals);
	_size = indices.size();

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// Buffer Positions
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);


	// Buffer Indices
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * indices.size(), indices.data(), GL_STATIC_DRAW);

	// Buffer Normals
	GLuint nbo;
	glGenBuffers(1, &nbo);
	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), normals.data(), GL_STATIC_DRAW);

	// Buffer UV
	GLuint ubo;
	glGenBuffers(1, &ubo);
	glBindBuffer(GL_ARRAY_BUFFER, ubo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * uvs.size(), uvs.data(), GL_STATIC_DRAW);

	// Setup Vertex Data
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		0,					// attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,					// number of dimensions
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glDisableVertexAttribArray(0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDisableVertexAttribArray(1);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, ubo);
	glVertexAttribPointer(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDisableVertexAttribArray(2);

	glBindVertexArray(0);

}

RawModel::~RawModel()
{
}

void RawModel::Draw()
{
	// Bind the VAO
	glBindVertexArray(_vao);

	// Enable Attribute Arrays
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	// Draw Model
	glDrawElements(GL_TRIANGLES, _size, GL_UNSIGNED_SHORT, (void*)0);

	// Disable Attribute Arrays
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	// Un-Bind
	glBindVertexArray(0);
}
