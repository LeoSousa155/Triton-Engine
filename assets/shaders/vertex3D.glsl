#version 330 core

in vec3 aPos;

out vec3 fragPos;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main() {
    gl_Position = u_Projection * u_View* u_Model * vec4(aPos, 1.0);
    fragPos = aPos;
}