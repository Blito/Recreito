#version 430 core
layout(location = 0) out vec4 out_color;

in vec4 objectColor;
in vec2 textCoord;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D ourSampler;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main(void)
{
    // Ambient light component
    float ambientStrength = 0.2f;
    vec4 ambientLight = ambientStrength * lightColor;

    // Diffuse light component
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diffuseStrength = max(dot(norm, lightDir), 0.0);
    vec4 diffuseLight = diffuseStrength * lightColor;

    // Specular light component
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec4 specularLight = specularStrength * spec * lightColor;

    out_color = (ambientLight + diffuseLight + specularLight) * objectColor;
}
