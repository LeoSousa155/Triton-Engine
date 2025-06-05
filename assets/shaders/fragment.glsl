#version 330 core

in vec3 fragPos;

out vec4 FragColor;

uniform float u_Time;

void main() {

    FragColor = vec4(0.7, fragPos.y, abs(sin(u_Time * 3)) / 2.2, 1.0);
}
