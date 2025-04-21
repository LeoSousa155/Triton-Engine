#include "graphics/Mesh.h"


namespace graphics {


    void Mesh::draw() const {
        shader->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }


    Mesh createTriangleMesh(Shader* shader, float vertices[3][3]) {
        GLuint VAO, VBO;
        

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        return {VAO, VBO, shader, 3};
    }
}