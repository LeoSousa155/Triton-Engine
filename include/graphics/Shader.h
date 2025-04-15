#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>


namespace graphics {


    enum class CompileTarget {
        VERTEX,
        FRAGMENT,
        PROGRAM
    };


    class Shader {
        public:
            unsigned int ID;
            
            Shader(const std::string& vertexPath, const std::string& fragmentPath);
            void use();
            
        private:
            void checkCompileErrors(unsigned int shader, CompileTarget type);
            std::string readFile(const std::string& filePath);
    };
}

#endif