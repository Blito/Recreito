#version 430 core
layout(location = 0) out vec4 out_color;

in vec4 objectColor;

void main(void)
{
    out_color = vec4(1.0f, 0.6f, 0.2f, 1.0f);
}
