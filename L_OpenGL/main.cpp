#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "display.h"

int main(){
    Display display(800,600, "Hello World!");
    while (!display.isClosed())
    {
        glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        display.update();
    }
    return 0;
}