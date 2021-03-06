#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& fileName);
    //Make the GPU use the vertex and fragment shaders.
    void bind();
    virtual ~Shader();
protected:
private:
    static constexpr unsigned int NUM_SHADERS = 2;
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif //SHADER_H_