#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


namespace sys {

    /** @brief Manages a GLFW window and its associated OpenGL context. */
    class Window {
        public:
            /** @brief Constructs a Window object (window pointer initialized to null). */
            Window();
            /** @brief Destroys the underlying GLFW window if it exists. */
            ~Window();

            /**
             * @brief Initializes and creates the GLFW window.
             * Sets OpenGL context hints (3.3 Core Profile) and makes the context current.
             * @param width The desired window width in pixels.
             * @param height The desired window height in pixels.
             * @param title The text displayed in the window's title bar.
             * @return True if window creation and context setup succeeded, false otherwise.
             */
            bool init(int width, int height, std::string title);

            /** @brief Swaps the front and back rendering buffers of the window. */
            void swapBuffers();

            /**
             * @brief Checks if the window has been flagged to close (e.g., user clicked the close button).
             * @return True if the window should close, false otherwise.
             */
            bool shouldClose() const;

            /**
             * @brief Provides access to the underlying native GLFW window handle.
             * Use with caution, primarily for interfacing with libraries requiring the native handle.
             * @return A pointer to the GLFWwindow object, or nullptr if the window hasn't been initialized.
             */
            GLFWwindow* getNativeHandle();

        private:
            GLFWwindow* window; ///< Pointer to the underlying GLFW window object managed by this class.
    };
}

#endif
