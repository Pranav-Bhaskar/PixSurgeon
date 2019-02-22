#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<string>

#include "colourHandler.h"
ColourHandler curCol;
std::string console, pointer("Welcome To Pix Surgeon"), mode, errorBuffer;
#include "./mode.h"
Mode* cMode;
std::vector<Mode*> buffer;
bool consoleMode;

void init();
void changeColour(std::vector<std::string>&);
std::vector<std::string> cutter(std::string&, char);
void drawString(void*, float, float, std::string);
void updateCurrentMode();
void displayEventBar();
void display();
void processCommand();
void keyboard(unsigned char, int, int);
void mouseClick(int, int, int, int);
void passivePointer(int, int);

#include "./glob.h"
#include "./line.h"
//#include "./poly.h"
