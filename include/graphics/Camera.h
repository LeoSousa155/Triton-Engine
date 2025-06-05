#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>


namespace graphics {

    enum class CameraMovement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    // Default camera values
    const float YAW         = -90.0f;
    const float PITCH       =  0.0f;
    const float SPEED       =  2.5f;
    const float SENSITIVITY =  0.1f;
    const float ZOOM        =  45.0f;


    class Camera3D {
        public:
            // camera attributes
            glm::vec3 position;
            glm::vec3 front;
            glm::vec3 up;
            glm::vec3 right;
            glm::vec3 worldUp;

            // euler angles
            float yaw;
            float pitch;

            // camera options
            float movementSpeed;
            float mouseSensitivity;
            float fov;

            //constructor
            Camera3D(
                glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
                glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
                float yaw = YAW, 
                float pitch = PITCH
            );

            glm::mat4 getViewMatrix() const;

            void processKeyboard(CameraMovement direction, float deltaTime);
            void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
            void processMouseScroll(float yoffset);

        private:
            void updateCameraVectors();
    };
}
#endif