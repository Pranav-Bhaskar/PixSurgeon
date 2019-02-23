#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<string>

#include "colourHandler.h"
ColourHandler curCol;
void drawString(void*, float, float, std::string);
std::vector<std::string> modes = {"NONE", "LINE", "POLYLINE", "POLYNOMIAL"};
std::string console, pointer("Welcome To Pix Surgeon"), mode, errorBuffer;
#include "./mode.h"
Mode* cMode;
std::vector<Mode*> buffer;
bool consoleMode;

void init();
void changeColour(std::vector<std::string>&);
std::vector<std::string> cutter(std::string&, char);
void updateCurrentMode();
void displayEventBar();
void display();
void processCommand();
void keyboard(unsigned char, int, int);
void mouseClick(int, int, int, int);
void passivePointer(int, int);

#include "./none.h"
#include "./line.h"
#include "./poly.h"
//#include "./polyLine.h"
#include "panel.h"
Panel panel;
#include "./glob.h"
