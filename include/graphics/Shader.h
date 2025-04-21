#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <vector>
#include <utility> // Required for std::pair

namespace graphics {

    
    /** @brief Specifies the stage of shader compilation/linking for error checking. */
    enum class CompileTarget {
        VERTEX,     ///< Vertex shader compilation stage.
        FRAGMENT,   ///< Fragment shader compilation stage.
        PROGRAM     ///< Shader program linking stage.
    };


    /**
     * @class Shader
     * @brief Manages loading, compiling, and linking GLSL shader programs.
     * Reads shader source from files, compiles vertex and fragment shaders,
     * links them into a program, and provides error checking.
     */
    class Shader {
        public:
            unsigned int ID; ///< The OpenGL handle (ID) for the linked shader program.


            /**
             * @brief Constructs a Shader object by loading, compiling, and linking shaders.
             * @param vertexPath Path to the vertex shader source file.
             * @param fragmentPath Path to the fragment shader source file.
             * @param attribBindings Optional vector of pairs specifying vertex attribute locations and names
             *                     (used with glBindAttribLocation before linking).
             */
            Shader(const std::string& vertexPath, const std::string& fragmentPath,
                   const std::vector<std::pair<GLuint, std::string>>& attribBindings = {});


            /** @brief Activates this shader program for subsequent rendering calls (glUseProgram). */
            void use();


        private:
            /**
             * @brief Checks for compilation or linking errors for a given shader or program.
             * Logs errors if any are found.
             * @param shader The OpenGL handle of the shader or program to check.
             * @param type The stage (VERTEX, FRAGMENT, PROGRAM) to check for errors.
             */
            void checkCompileErrors(unsigned int shader, CompileTarget type);


            /**
             * @brief Reads the entire content of a file into a string.
             * @param filePath The path to the file to read.
             * @return A string containing the file's content, or an empty string on failure.
             */
            std::string readFile(const std::string& filePath);
    };
}

#endif
