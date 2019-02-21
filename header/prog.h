#include<iostream>
#include<GL/glut.h>

#include "./mode.h"
Mode* cMode;

void drawString (void*, float, float, char*);
void display();
void keyboard(unsigned char, int, int);
void mouseClick(int, int, int, int);
void passivePointer(int, int);

#include "./glob.h"
#include "./line.h"
//#include "./poly.h"
