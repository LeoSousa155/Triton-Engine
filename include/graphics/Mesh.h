#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics/Shader.h"


namespace graphics {
    

    struct Mesh {
        GLuint VAO;
        GLuint VBO;
        Shader* shader;
        GLsizei vertexCount;
    
        void draw() const;
    };

    Mesh createTriangleMesh(Shader* shader, float vertices[3][3]);
}

#endif 
