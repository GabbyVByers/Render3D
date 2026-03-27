
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 uModel;
uniform mat4 uModelViewProject;
uniform vec3 uLightDir;

out vec4 vertColor;
out vec2 texCoord;
out vec3 vWorldPos;
out vec3 lightDir;

void main() {
	gl_Position = uModelViewProject * vec4(aPos, 1.0);
	vertColor = aColor;
	texCoord = aTexCoord;

	vec4 world = uModel * vec4(aPos, 1.0);
	vWorldPos = world.xyz;
	lightDir = uLightDir;
}

