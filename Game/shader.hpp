#ifndef SHADER_HPP
#define SHADER_HPP

#include <GLM\matrix.hpp>
#include <GL\glew.h>

#include <string>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

GLuint LoadShaders(std::string vertexShader, std::string fragmentShader);

void UniformMat4(glm::mat4 mat, const char* id, GLuint program);

void UniformVec3(glm::vec3 vec3, const char* id, GLuint program);

void UniformMat3(glm::mat3 mat3, const char* id, GLuint program);

#endif
