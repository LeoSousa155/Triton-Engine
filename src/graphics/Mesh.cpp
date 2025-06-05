#include <glm/gtc/type_ptr.hpp>

#include "graphics/Mesh.h"

namespace graphics {


    void Mesh::draw(const Camera3D& camera, float aspectRatio) const {
        shader->use();

        GLuint modelLoc = glGetUniformLocation(shader->ID, "u_Model");
        GLuint viewLoc = glGetUniformLocation(shader->ID, "u_View");
        GLuint projLoc = glGetUniformLocation(shader->ID, "u_Projection");
        GLint timeLoc = glGetUniformLocation(shader->ID, "u_Time");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(transform.getMatrix()));

        // Define câmera e perspectiva
        glm::mat4 view = camera.getViewMatrix();

        glm::mat4 projection = glm::perspective(
            glm::radians(camera.fov),
            aspectRatio,
            0.1f,
            100.0f
        );

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform1f(timeLoc, glfwGetTime());

        // render
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }


    void Mesh::updateVertices(const void* data, size_t size) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }


    Mesh createTriangleMesh(Shader* shader, float vertices[][3], size_t size) {
        GLuint VAO, VBO;
        

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        int vertexCount = size / (sizeof(float) * 3);
        return {VAO, VBO, shader, vertexCount};
    }
}