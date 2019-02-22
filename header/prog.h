#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<string>

std::string console, pointer("Welcome To Pix Surgeon"), mode, errorBuffer;
#include "./mode.h"
Mode* cMode;
std::vector<Mode*> buffer;

void init();
void drawString (void*, float, float, char*);
void displayEventBar();
void display();
void keyboard(unsigned char, int, int);
void mouseClick(int, int, int, int);
void passivePointer(int, int);

#include "./glob.h"
#include "./line.h"
//#include "./poly.h"
