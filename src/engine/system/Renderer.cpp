#include "engine/system/Renderer.h"
#include "utils/Logger.h"


namespace sys {


    bool Renderer::init() {
        shader = new graphics::Shader(
            "/home/leo/projects/triton_engine/assets/shaders/vertex.glsl",
            "/home/leo/projects/triton_engine/assets/shaders/fragment.glsl",
            {{0, "aPos"}}
        );
        shader->use();

        initTriangle();
        return true;
    }


    void Renderer::initTriangle() {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };
        
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }


    void Renderer::render() {
        shader->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}