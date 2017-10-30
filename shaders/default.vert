#version 330 core
layout (location = 0) in vec3 aPos;

/*uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;*/

uniform mat4 glob;

void main() {
	gl_Position = glob * vec4(aPos, 1.0);
}
