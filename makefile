CC=g++

HDIR=header

_HEAD = prog.h glob.h
HEAD = $(patsubst %,$(HDIR)/%,$(_HEAD))

build: $(HEAD) prog.cpp
	@$(CC) prog.cpp -o PixSurgeon -lGL -lGLU -lglut

.PHONY: clean

clean: 
	@rm -rf ./PixSurgeon
