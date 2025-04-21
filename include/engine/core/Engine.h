#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/system/Window.h"
#include "engine/system/Input.h"
#include "engine/system/Renderer.h"

#include "engine/core/Application.h"
#include "engine/core/EngineContext.h"

#include <string>

namespace core {


    /**
     * @class Engine
     * @brief Manages the core engine loop, subsystems (Window, Renderer), and runs the user Application.
     */
    class Engine {
        public:
            /**
             * @brief Constructs the Engine, storing initial window settings.
             * @param width Initial window width.
             * @param height Initial window height.
             * @param title Initial window title.
             */
            Engine(int width, int height, const char* title);


            /** @brief Destructor (handles cleanup of member objects like Window). */
            ~Engine();


            /**
             * @brief Starts the main engine loop.
             * Initializes subsystems, creates the context, and runs the provided Application's loop.
             * @param app Pointer to the user-defined Application instance to run.
             */
            void run(Application* app);


        private:
            // --- Core Subsystems ---
            sys::Window window;         ///< Manages the application window and OpenGL context.
            sys::Renderer renderer;     ///< Handles rendering operations.
            sys::Input inputHandler;


            // --- Window Configuration ---
            int width;                  ///< Initial window width.
            int height;                 ///< Initial window height.
            std::string title;          ///< Initial window title.


            // --- Timing ---
            float lastTimeFrame = 0.0f; ///< Stores the time of the last frame (for delta time calculation).


            // --- Context ---
            EngineContext context;      ///< Holds pointers to essential subsystems for Application access.

            
            /**
             * @brief Initializes GLFW and the main application window.
             * @return True if initialization was successful, false otherwise.
             */
            bool initWindow();
    };
}

#endif
