#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#include "math/Transform3D.h"

namespace math {
    glm::mat4 Transform3D::getMatrix() const {
        glm::mat4 mat = glm::mat4(1.0f);
        mat = glm::translate(mat, position);
        mat = glm::rotate(mat, glm::radians(rotation.x), glm::vec3(1,0,0));
        mat = glm::rotate(mat, glm::radians(rotation.y), glm::vec3(0,1,0));
        mat = glm::rotate(mat, glm::radians(rotation.z), glm::vec3(0,0,1));
        mat = glm::scale(mat, scale);
        return mat;
    }

    void showMatrix(glm::mat4 model) {
        const float* m = glm::value_ptr(model);
        std::cout << "Model matrix:\n";
        for (int i = 0; i < 4; i++) {
            std::cout << m[i] << " " << m[i+4] << " " << m[i+8] << " " << m[i+12] << '\n';
        }  
    }
}