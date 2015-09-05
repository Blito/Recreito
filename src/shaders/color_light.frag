#version 330 core
layout(location = 0) out vec4 out_color;

in vec4 objectColor;
in vec2 textCoord;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D ourSampler;
uniform vec4 lightColor;
uniform vec3 lightPos;

void main(void)
{
	// Difuse light component
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);
	float diffuseStrength = max(dot(norm, lightDir), 0.0);
	vec4 diffuseLight = diffuseStrength * lightColor;

	// Ambient light component
	float ambientStrength = 0.2f;
	vec4 ambientLight = ambientStrength * lightColor;

    out_color = (ambientLight + diffuseLight) * objectColor;
}
