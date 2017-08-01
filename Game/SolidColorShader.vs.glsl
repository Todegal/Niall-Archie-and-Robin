#version 440 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;
layout(location = 2) in vec2 uv;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;
uniform mat3 NM;

uniform vec3 COLOR;

out vec4 Colour;
out vec3 Normal;
out vec3 Position;

void main()
{
	Colour = vec4(vec3(1, 1, 1), 1);

	Normal = normalize(NM * norm);
	mat4 MVP = P * V * M;


	Position = (P * V * M * vec4(pos, 1.0)).xyz;
	gl_Position = MVP * vec4(pos, 1.0);
}