#version 330 core

in vec3 fragPos;

out vec4 FragColor;

void main() {

    FragColor = vec4(0.3, fragPos.y, 0.4, 1.0); // cor laranja
}
