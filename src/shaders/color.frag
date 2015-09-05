#version 430 core
layout(location = 0) out vec4 out_color;

in vec4 objectColor;

void main(void)
{
    out_color = objectColor;
}
