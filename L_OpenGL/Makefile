CC=g++
CPPFLAGS=-Wall -Wextra -Werror -pedantic-errors -std=c++2a
#PARAMS= -lGL -lGLU -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama -lXcursor -lXext -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp -lGLEW -lGLU -lGL -lm -ldl -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm -lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp

OBJS=main.o Display.o

# find cpp files in subdirectories
SOURCES := $(shell find . -name '*.cpp')

# find headers
HEADERS := $(shell find . -name '*.h')

all: Main

Main: $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) -pthread -g -o $@ $^ -lSDL2 -lGLEW -lGL

Display.o: display.cpp display.h
