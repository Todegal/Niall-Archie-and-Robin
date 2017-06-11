#ifndef SHADER_HPP
#define SHADER_HPP

#include <GLM\matrix.hpp>
#include <GL\glew.h>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

void UniformMat4(glm::mat4 mat, const char* id, GLuint program);

void UniformVec3(glm::vec3 vec3, const char* id, GLuint program);

#endif
