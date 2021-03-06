#ifndef _MESH_H_
#define _MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos){this->pos = pos;}
    //virtual ~Vertex();
protected:
private:
    glm::vec3 pos;
};

class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    virtual ~Mesh();
    void draw();
protected:
private:
    enum {
        POSITION_VB,
        NUM_BUFFERS
    };
    //Mesh Data.
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif //_MESH_H_