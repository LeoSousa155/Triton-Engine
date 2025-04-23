#version 330 core

in vec3 aPos;
uniform mat4 u_Model;

void main() {
    gl_Position = u_Model * vec4(aPos, 1.0);
}