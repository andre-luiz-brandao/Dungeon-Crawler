OS := $(shell uname -s)
programa = trabalho.cpp

all:
    ifeq ("$(OS)", "Darwin")
	g++ $(programa) -o  trabalho -framework OpenGL -framework GLUT
    else
	g++ $(programa) -o trabalho -lGL -lGLU -lglut
    endif

clean:
	rm -rf trabalho

run:
	./trabalho
