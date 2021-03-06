#include "shader.h"
#include <fstream>
#include <iostream>

static std::string loadShader(const std::string& fileName);
static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint createShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName){
    m_program = glCreateProgram();
    m_shaders[0] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);
    
    for(unsigned int i = 0; i < NUM_SHADERS; ++i)
        glAttachShader(m_program, m_shaders[i]);

    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    checkShaderError(m_program, GL_LINK_STATUS, true, "Program linking failed!: ");
    glValidateProgram(m_program);
    checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Program validation failed: ");
}

Shader::~Shader(){
    for(unsigned int i = 0; i < NUM_SHADERS; ++i){
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void Shader::bind(){
    glUseProgram(m_program);
}

static GLuint createShader(const std::string& text, GLenum shaderType){
    GLuint shader = glCreateShader(shaderType);

    if(shader == 0)
        std::cerr << "Error!, Shader creation failed!." << std::endl;
    
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringsLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringsLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLengths);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error!, shader compilation failed: ");
    
    return shader;
}

static std::string loadShader(const std::string& fileName){
    std::fstream file;
    file.open(fileName);
    std::string output, line;

    if(file.is_open()){
        while(file.good()){
            std::getline(file, line);
            output.append(line + "\n");
        }
    } else {
        std::cerr << "Unable to load shader!: " << fileName << std::endl;
    }
    return output;
}

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else 
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE){
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
         else 
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    std::cerr << errorMessage << ": '" << error << " '" << std::endl;
    }
}