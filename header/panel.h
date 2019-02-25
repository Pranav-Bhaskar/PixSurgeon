#include "scanline.h"

class Panel{
	void showOptions();
	void showPalet();
	void setBackground();
	float triangleArea(int, int, int, int, int, int);
	ColourHandler* backGround;
	ColourHandler* foreGround;
	ColourHandler* textCol;
	double darkFactor;
	bool isInTriangle(int, int);
	public:
	Panel();
	void draw();
	void leftClick(int, int);
};

Panel::Panel(){
	this->darkFactor = 1.0000;
	this->backGround = new ColourHandler(0, 0, 0, 0);
	this->foreGround = new ColourHandler(1, 1, 1, 0);
	this->textCol = new ColourHandler(0, 0, 0, 0);
}

float Panel::triangleArea(int x1, int y1, int x2, int y2, int x3, int y3){
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool Panel::isInTriangle(int x, int y){
	int x1 = 1220, x2 = 1285, x3 = 1350;
	int y1 = 200, y2 = 313, y3 = 200;
	float A = triangleArea(x1, y1, x2, y2, x3, y3); 
	float A1 = triangleArea(x, y, x2, y2, x3, y3);
	float A2 = triangleArea(x1, y1, x, y, x3, y3);
	float A3 = triangleArea(x1, y1, x2, y2, x, y);
	return (A == A1 + A2 + A3);
}

void Panel::setBackground(){
	this->backGround->setColour();
	glBegin(GL_POLYGON);
		glVertex2f(1200, 0);
		glVertex2f(1200, 690);
		glVertex2f(1365, 690);
		glVertex2f(1365, 0);
	glEnd();
}

void Panel::draw(){
	glBegin(GL_LINES);
		glVertex2f(1200, 0);
		glVertex2f(1200, 690);
	glEnd();
	this->setBackground();
	this->showOptions();
	this->showPalet();
}

void Panel::showOptions(){
	this->foreGround->setColour();
	drawString(GLUT_BITMAP_HELVETICA_10, 1260, 645, std::string("MODES"));
	for(int i=0;i<modes.size();++i){
		this->foreGround->setColour();
		glBegin(GL_POLYGON);
			glVertex2f(1220, 620 - (i * 21));
			glVertex2f(1220, 634 - (i * 21));
			glVertex2f(1350, 634 - (i * 21));
			glVertex2f(1350, 620 - (i * 21));
		glEnd();
		this->textCol->setColour();
		float sp_x = 1285 - (modes[i].length()*3);
		float sp_y = 620 - (i * 21) + 4;
		drawString(GLUT_BITMAP_HELVETICA_10, sp_x, sp_y, modes[i]);
		if(i == cMode->getMode()){
			this->foreGround->setColour();
			drawString(GLUT_BITMAP_HELVETICA_10, 1212, sp_y, std::string(">"));
			drawString(GLUT_BITMAP_HELVETICA_10, 1354, sp_y, std::string("<"));
		}
	}
}

void Panel::showPalet(){
	std::vector<int> xcord = {1220, 1285, 1350};
	std::vector<int> ycord = {200, 313, 200};
	ScanLine(xcord, ycord, true, this->darkFactor);
	foreGround->setColour();
	glBegin(GL_POLYGON);
		glVertex2f(1220, 170);
		glVertex2f(1220, 190);
		glVertex2f(1275, 190);
		glVertex2f(1275, 170);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1295, 170);
		glVertex2f(1295, 190);
		glVertex2f(1350, 190);
		glVertex2f(1350, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(1220, 140);
		glVertex2f(1220, 160);
		glVertex2f(1350, 160);
		glVertex2f(1350, 140);
	glEnd();
	textCol->setColour();
	drawString(GLUT_BITMAP_HELVETICA_10, 1227, 175, std::string("BRIGHT"));
	drawString(GLUT_BITMAP_HELVETICA_10, 1301, 175, std::string("DARKEN"));
	curCol.setColour();
	glBegin(GL_POLYGON);
		glVertex2f(1221, 141);
		glVertex2f(1221, 159);
		glVertex2f(1349, 159);
		glVertex2f(1349, 141);
	glEnd();
}

void Panel::leftClick(int x ,int y){
	if(x < 1220 || x > 1350)
		return;
	int nextMode = -1;
	for(int i=0;i<modes.size();++i){
		if(y > (620 - (i * 21)) && (y < (634 - (i * 21)))){
			switch(i){
			case 0 : cMode = new None;
				return;
			case 1 : cMode = new Line;
				return;
			case 2 : cMode = new PolyLine;
				return;
			case 3 : cMode = new PolyNom;
				return;
			}
		}
	}
	glVertex2f(1295, 170);
		glVertex2f(1295, 190);
		glVertex2f(1350, 190);
		glVertex2f(1350, 170);
	if((y > 170) && (y < 190)){
		if(x < 1275){
			this->darkFactor *= 1.5;
			return;
		}
		if(x > 1295){
			this->darkFactor /= 1.5;
			return;
		}
	}
	if(isInTriangle(x, y)){
		double dis_r, dis_g, dis_b;
		dis_b = (pow(1220 - x, 2) + pow(200 - y, 2))/16900;
		dis_g = (pow(1350 - x, 2) + pow(200 - y, 2))/16900;
		dis_r = (pow(1285 - x, 2) + pow(313 - y, 2))/16900;
		curCol.getColour((1 - dis_r)*darkFactor, (1 - dis_g)*darkFactor, (1 - dis_b)*darkFactor);
		return;
	}
}
