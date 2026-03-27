
#version 330 core

in vec4 vertColor;
in vec2 texCoord;
in vec3 vWorldPos;
in vec3 lightDir;

uniform sampler2D ourTexture;

out vec4 FragColor;

void main() {
    vec3 dx = dFdx(vWorldPos);
    vec3 dy = dFdy(vWorldPos);
    vec3 normal = normalize(cross(dx, dy));
    float light = max(dot(normal, -lightDir), 0.0);
    FragColor = texture(ourTexture, texCoord) * vertColor * vec4(light, light, light, 1.0);
}

