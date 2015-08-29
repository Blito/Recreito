#version 430 core
layout(location = 0) out vec4 out_color;

in vec4 color;
in vec2 textCoord;

uniform sampler2D ourSampler;

void main(void)
{
    out_color = color;
}
