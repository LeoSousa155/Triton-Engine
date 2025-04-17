#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


namespace sys {


    class Window {
        public:
            Window();
            ~Window();

            bool init(int width, int height, std::string title);
            void swapBuffers();
            bool shouldClose() const;

            GLFWwindow* getNativeHandle();

        private:
            GLFWwindow* window;
    };
}

#endif 