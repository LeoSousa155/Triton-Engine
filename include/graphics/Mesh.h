#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics/Shader.h"
#include "graphics/Camera.h"
#include "math/Transform3D.h"

namespace graphics {
    

    struct Mesh {
        GLuint VAO;
        GLuint VBO;
        Shader* shader;
        GLsizei vertexCount;
        math::Transform3D transform;
    
        void draw(const Camera3D& camera, float aspetRatio) const;
        void updateVertices(const void* data, size_t size);
    };

    Mesh createTriangleMesh(Shader* shader, float vertices[3][3], size_t size);
}

#endif 
