#version 440

in vec3 col;

out vec4 o;

void main() 
{
	o = vec4(col, 1);
}