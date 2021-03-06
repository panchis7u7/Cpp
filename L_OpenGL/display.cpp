#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title){
    //Initialize SDL. (Only for windowing!).
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //Use c_str, because SDL is a C library, not C++.
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glcontext = SDL_GL_CreateContext(m_window);
    GLenum status = glewInit();
    if(status != GLEW_OK){
        std::cerr << "Glew failed to create a window!" << std::endl;
    }
    m_isClosed = false;
}

Display::~Display(){
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a){
    //Set window color.
        glClearColor(r,g,b,a);
        //Clear color buffer and fill with custom color.
        glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::isClosed(){
    return m_isClosed;
}

void Display::update(){
    SDL_GL_SwapWindow(m_window);
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT)
            m_isClosed = true;
    }
}