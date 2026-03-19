
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

uniform mat4 uModelViewProject;

out vec4 vertColor;
void main() {
	gl_Position = uModelViewProject * vec4(aPos, 1.0);
	vertColor = aColor;
}

