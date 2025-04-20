#include <iostream>
#include <fstream>
#include <sstream>

#include "graphics/Shader.h"



namespace graphics {
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath, 
        const std::vector<std::pair<GLuint, std::string>>& attribBindings) {

        std::string vertexCode = readFile(vertexPath);
        std::string fragmentCode = readFile(fragmentPath);
    
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
    
        glShaderSource(vertexShader, 1, &vShaderCode, NULL);
        glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    
        glCompileShader(vertexShader); 
        checkCompileErrors(vertexShader, CompileTarget::VERTEX);
       
        glCompileShader(fragmentShader);
        checkCompileErrors(fragmentShader, CompileTarget::FRAGMENT);
    
    
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);

        // Aqui fazes os bindings antes do link
        for (const auto& binding : attribBindings) {
            glBindAttribLocation(ID, binding.first, binding.second.c_str());
        }

        glLinkProgram(ID);
        checkCompileErrors(ID, CompileTarget::PROGRAM);
    }
    
    
    void Shader::use() {
        glUseProgram(ID);
    }
    
    
    void Shader::checkCompileErrors(unsigned int shader, CompileTarget type) {
        int success;
        char infoLog[512];
    
        switch (type) {
            case CompileTarget::PROGRAM:
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if (!success) {
                    glGetProgramInfoLog(shader, 512, NULL, infoLog);
                    std::cerr << "Shader Link ERROR: " << infoLog << '\n';
                }
                break;
            
            case CompileTarget::VERTEX:
            case CompileTarget::FRAGMENT:
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if(!success) {
                    glGetShaderInfoLog(shader, 512, NULL, infoLog);
                    std::cerr << "Shader Compile ERROR: " << infoLog << '\n';
                }
                break;
    
            default:
                std::cerr << "Wrong Compile Target type passed\n";
        }
    }
    
    
    std::string Shader::readFile(const std::string& filePath) {
        std::ifstream file(filePath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
}