#ifndef TRANSFORM_3D
#define TRANSFORM_3D

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace math {
    struct Transform3D {
        glm::vec3 position = glm::vec3(0.0f);
        glm::vec3 rotation = glm::vec3(0.0f); // in degrees
        glm::vec3 scale    = glm::vec3(1.0f);

        glm::mat4 getMatrix() const;
    };
    
    void showMatrix(glm::mat4 model);
}

#endif