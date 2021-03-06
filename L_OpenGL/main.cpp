#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "display.h"
#include "shader.h"

int main(){
    Display display(800,600, "Hello World!");
    Shader shader("./res/Basic_Shader");
    while (!display.isClosed())
    {   
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();
        display.update();
    }
    return 0;
}