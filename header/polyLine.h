//The PolyLine class is used to draw multi-line.
class PolyLine: public Mode{
	unsigned int vert;
	unsigned int maxSize;
	int *cord_x;
	int *cord_y;
	void resize();
	public:
	void leftClick(int, int);
	void rightClick(int, int);
	std::string modeData();
	void draw();
	void quit();
	PolyLine();
};

PolyLine::PolyLine(){
	setMode(2);
	this->vert = 0;
	this->maxSize = 5;
	this->cord_x = new int[maxSize];
	this->cord_y = new int[maxSize];
}

void PolyLine::quit(){
	this->vert = 0;
	errorBuffer = "Mode Reseting Success";
	glutPostRedisplay();
}

std::string PolyLine::modeData(){
	return std::string("Right click to stop");
}

void PolyLine::draw(){
	this->objectColour.setColour();
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<this->vert;++i)
		glVertex2f(cord_x[i], cord_y[i]);
	glEnd();
}

void PolyLine::rightClick(int x, int y){
	this->objectColour = curCol;
	buffer.push_back(this);
	cMode = new PolyLine;
}

void PolyLine::resize(){
	maxSize *= 2;
	int* lis = new int[maxSize];
	for(int i=0;i<this->vert;++i)
		lis[i] = cord_x[i];
	delete cord_x;
	cord_x = lis;
	lis = new int[maxSize];
	for(int i=0;i<this->vert;++i)
		lis[i] = cord_y[i];
	delete cord_y;
	cord_y = lis;
}

void PolyLine::leftClick(int x, int y){
	if(this->vert == this->maxSize)
		this->resize();
	this->cord_x[this->vert] = x;
	this->cord_y[this->vert++] = y;
}
