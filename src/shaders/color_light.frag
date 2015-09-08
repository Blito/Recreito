#version 430 core
struct Material
{
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
    float shininess;
};

struct Light
{
    vec4 color;
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

layout(location = 0) out vec4 out_color;

in vec4 objectColor;
in vec2 textCoord;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D ourSampler;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main(void)
{
    // Ambient light component
    vec4 ambientLight = light.ambient * material.ambient * light.color;

    // Diffuse light component
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diffuse = max(dot(norm, lightDir), 0.0);
    vec4 diffuseLight = light.diffuse * material.diffuse * diffuse * light.color;

    // Specular light component
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float specular = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec4 specularLight = light.specular * material.specular * specular * light.color;

    out_color = (ambientLight + diffuseLight + specularLight) * objectColor;
}
