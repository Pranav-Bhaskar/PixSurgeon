#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<string>
#include<fstream>
#define WINDOW_WIDTH 1365.0
#define WINDOW_HEIGHT 700.0

#include "colourHandler.h"
bool saveMe = false;
ColourHandler curCol;
void drawString(void*, float, float, std::string);
std::vector<std::string> modes = {"NONE", "LINE", "POLYLINE", "POLYNOMIAL", "PENCIL", "ERASER", "RENDER", "SAVIOUR"};
std::string console, pointer("Welcome To Pix Surgeon"), mode, errorBuffer;
#include "./mode.h"
Mode* cMode;
std::vector<Mode*> buffer;
bool consoleMode;
bool keyDownStat;
int pointerX;
int pointerY;

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
void activePointer(int, int);

#include "./none.h"
#include "./line.h"
#include "./pencil.h"
#include "./eraser.h"
#include "./poly.h"
#include "./polyLine.h"
#include "./render.h"
#include "./saviour.h"
#include "panel.h"
Panel panel;
#include "./glob.h"
