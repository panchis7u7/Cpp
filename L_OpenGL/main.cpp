#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(){
    Display display(800,600, "Hello World!");
    Vertex vertices[] = { Vertex(glm::vec3( -0.5, -0.5, 0 )),
                          Vertex(glm::vec3( 0, 0.5, 0 )),
                          Vertex(glm::vec3( 0.5, -0.5, 0 )),};
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    Shader shader("./res/Basic_Shader");
    while (!display.isClosed())
    {   
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();
        mesh.draw();
        display.update();
    }
    return 0;
}