#version 430 core
struct Material
{
    sampler2D texture_diffuse_1;
    sampler2D texture_diffuse_2;
    sampler2D texture_diffuse_3;
    sampler2D texture_specular_1;
    sampler2D texture_specular_2;
    float shininess;
};

struct Light
{
    vec3 position;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    float constant;
    float linear;
    float quadratic;
};

layout(location = 0) out vec4 out_color;

in vec2 textCoord;
in vec3 normal;
in vec3 fragPos;

uniform vec4 lightColor;
uniform vec3 viewPos;
uniform Light light;
uniform Material material;

void main(void)
{
    float lightDistance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * lightDistance +
                                light.quadratic * (lightDistance * lightDistance));

    // Ambient light component
    vec4 ambientLight = light.ambient * vec4(texture(material.texture_diffuse_1, textCoord));

    // Diffuse light component
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos);
    float diffuse = max(dot(norm, lightDir), 0.0);
    vec4 diffuseLight = light.diffuse * vec4(texture(material.texture_diffuse_1, textCoord)) * diffuse;

    // Specular light component
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float specular = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec4 specularLight = light.specular * vec4(texture(material.texture_specular_1, textCoord)) * specular;

    vec4 specularFixed = vec4(max(specularLight.x, 0.0),
                              max(specularLight.y, 0.0),
                              max(specularLight.z, 0.0),
                              1.0);

    out_color = attenuation * (ambientLight + diffuseLight + specularFixed);
}
