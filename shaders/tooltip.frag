#version 330 core

in vec3 Color;

out vec4 FragColor;

void main() {
	FragColor = vec4(Color.xyz, 1.0);
}
