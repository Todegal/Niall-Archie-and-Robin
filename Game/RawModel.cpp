#include "RawModel.h"

RawModel::RawModel(const char * path)
{
}

RawModel::RawModel(std::vector<glm::vec3> positions, std::vector<unsigned int> indices)
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// Buffer Positions
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions.data(), GL_STATIC_DRAW);


	// Buffer Indices
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);

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

	glBindVertexArray(0);

	_size = indices.size();

}

RawModel::~RawModel()
{
}

void RawModel::Draw()
{
	// Bind the VAO
	glBindVertexArray(_vao);

	// Enable Attribute Array
	glEnableVertexAttribArray(0);

	// Draw Model
	glDrawElements(GL_TRIANGLES, _size, GL_UNSIGNED_INT, (void*)0);

	// Disable Attribute Array
	glDisableVertexAttribArray(0);

	// Un-Bind
	glBindVertexArray(0);
}
