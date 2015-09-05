#version 430 core
layout(location = 0) out vec4 out_color;

in vec4 objectColor;
in vec2 textCoord;

uniform sampler2D ourSampler;
uniform vec4 lightColor;

void main(void)
{
	float ambientStrength = 0.2f;
	vec4 ambientLight = ambientStrength * lightColor;
    out_color = ambientLight * objectColor;
}
