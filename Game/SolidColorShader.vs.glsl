#version 440 core

layout(location = 0) in vec3 positions;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

uniform vec3 COLOR;

out vec3 col;

void main()
{
	mat4 MVP = P * V * M;

	gl_Position = MVP * vec4(positions, 1.0);

	col = COLOR;
}