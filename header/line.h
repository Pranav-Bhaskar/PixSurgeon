//The Line class is used to draw a line.
class Line: public Mode{
	unsigned int cord_x[2];
	unsigned int cord_y[2];
	unsigned int state;
	//void right_click();
	public:
	void left_click(int, int);
	void draw();
	Line();
};

Line::Line(){
	set_mode(1);
	this->state = 0;
}

void Line::draw(){
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(cord_x[0], cord_y[0]);
		glVertex2f(cord_x[1], cord_y[1]);
	glEnd();
}

void Line::left_click(int x, int y){
	std::cout<<" x:"<<x<<" y:"<<y<<std::endl;
	this->cord_x[this->state] = x;
	this->cord_y[this->state++] = 703 - y;
	if(this->state == 2){
		buffer.push_back(this);
		cMode = new Line;
		glutPostRedisplay();
	}
}
