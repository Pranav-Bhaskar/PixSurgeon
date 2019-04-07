//The Line class is used to draw a line.
class Line: public Mode{
	unsigned int cord_x[2];
	unsigned int cord_y[2];
	unsigned int state;
	public:
	void leftClick(int, int);
	void undeadPoints();
	void ghostPointer();
	std::string modeData();
	void draw();
	void quit();
	Line();
};

Line::Line(){
	setMode(1);
	this->state = 0;
	this->makeMenu();
}

void Line::undeadPoints(){
	if(this->state != 1)
		return;
	curCol.setEnv();
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glVertex2f(this->cord_x[0], this->cord_y[0]);
	glEnd();
}

void Line::ghostPointer(){
	if(this->state != 1)
		return;
	curCol.setEnv();
	glBegin(GL_LINES);
		glVertex2f(this->cord_x[0], this->cord_y[0]);
		glVertex2f(pointerX, pointerY);
	glEnd();
}

std::string Line::modeData(){
	if(this->state == 0)
		return std::string("Click for P1");
	std::string s("P1(");
	s += std::to_string(this->cord_x[0]) + ":" + std::to_string(cord_y[0]) + "). ";
	return  s + "Click for P2";
}

void Line::draw(){
	this->objectColour.setEnv();
	glBegin(GL_LINES);
		glVertex2f(cord_x[0], cord_y[0]);
		glVertex2f(cord_x[1], cord_y[1]);
	glEnd();
}

void Line::leftClick(int x, int y){
	this->cord_x[this->state] = x;
	this->cord_y[this->state++] = y;
	if(this->state == 2){
		this->objectColour = curCol;
		buffer.push_back(this);
		cMode = new Line;
	}
	glutPostRedisplay();
}

void Line::quit(){
	this->state = 0;
	errorBuffer = "Mode Reseting Success";
}
