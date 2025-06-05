#include "graphics/Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace graphics {

    Camera3D::Camera3D(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : front(glm::vec3(0.0f, 0.0f, -1.0f)),
        movementSpeed(SPEED),
        mouseSensitivity(SENSITIVITY),
        fov(ZOOM) {
        this->position = position;
        this->worldUp = up;
        this->yaw = yaw;
        this->pitch = pitch;
        updateCameraVectors();
    }


    glm::mat4 Camera3D::getViewMatrix() const {
        return glm::lookAt(position, position + front, up);
    }

    void Camera3D::processKeyboard(CameraMovement direction, float deltaTime) {
        float velocity = movementSpeed * deltaTime;
        if (direction == CameraMovement::FORWARD)
            position += front * velocity;
        if (direction == CameraMovement::BACKWARD)
            position -= front * velocity;
        if (direction == CameraMovement::LEFT)
            position -= right * velocity;
        if (direction == CameraMovement::RIGHT)
            position += right * velocity;
        if (direction == CameraMovement::UP)
            position += worldUp * velocity;
        if (direction == CameraMovement::DOWN)
            position -= worldUp * velocity;
    }

    void Camera3D::processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
        xoffset *= mouseSensitivity;
        yoffset *= mouseSensitivity;

        yaw += xoffset;
        pitch += yoffset;

        // Make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch) {
            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;
        }

        // Update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    void Camera3D::processMouseScroll(float yoffset) {
        fov -= (float)yoffset; // yoffset is usually scroll speed (e.g., 1 or -1)
        if (fov < 1.0f)
            fov = 1.0f;
        if (fov > 75.0f) // Max FoV, adjust as needed
            fov = 75.0f;
    }

    void Camera3D::updateCameraVectors() {
        // Calculate the new Front vector
        glm::vec3 newFront;
        newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        newFront.y = sin(glm::radians(pitch));
        newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(newFront);

        // Also re-calculate the Right and Up vector
        // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        right = glm::normalize(glm::cross(front, worldUp));
        up    = glm::normalize(glm::cross(right, front));
    }
} 