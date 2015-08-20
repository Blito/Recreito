#version 430 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_textCoord;

out vec4 color;
out vec2 textCoord;

void main()
{
    color = in_color;
    textCoord = in_textCoord;

    gl_Position = vec4(in_position, 1.0); //w is 1.0
}
