#version 440

in vec3 Position;
in vec4 Colour;
in vec3 Normal;

vec3 LightColour = vec3(0, 1, 1);
vec3 LightDirection = vec3(-1, -1, 0);
vec3 HalfVector = normalize(-LightDirection + normalize(- Position));
float Shininess = 2;
float Strength = 1;
vec3 Ambient = vec3(0.2	) * LightColour;

out vec4 FragColour;

void main() {
	float diffuse = max(0.0, dot(Normal, LightDirection));
	float specular = max(0.0, dot(Normal, HalfVector));

	if	(diffuse == 0.0)
		specular = 0.0;
	else
		specular = pow(specular, Shininess);

	vec3 scatteredLight = Ambient + LightColour * diffuse;
	vec3 reflectedLight = LightColour * specular * Strength;

	vec3 rgb = min((Colour.rgb * scatteredLight) + reflectedLight, vec3(1.0, 1.0, 1.0));
	FragColour = vec4(rgb.x, rgb.y, rgb.z, 1.0);
}