//The Line class is used to draw a line.
class Line: public Mode{
	int cord_x[2];
	int cord_y[2];
	unsigned int state;
	void draw();
	//void right_click();
	public:
	void left_click(int, int);
	Line();
};

Line::Line(){
	set_mode(1);
	this->state = 0;
}

void Line::draw(){
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE);
		glVertex2f(cord_x[0], cord_y[0]);
		glVertex2f(cord_x[1], cord_y[1]);
	glEnd();
	glFlush();
}

void Line::left_click(int x, int y){
	if(this->state == 2){
		cMode = new Line;
		cMode->left_click(x, y);
		return;
	}
	this->cord_x[this->state] = x;
	this->cord_y[this->state++] = y;
	if(this->state == 2)
		this->draw();
}
