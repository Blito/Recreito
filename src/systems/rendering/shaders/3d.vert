#version 430 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_textCoord;

out vec2 textCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    textCoord = in_textCoord;
    normal = in_normal;

    vec4 worldCoord = model * vec4(in_position, 1.0);
    fragPos = vec3(worldCoord);

    gl_Position = projection * view * worldCoord;
}
