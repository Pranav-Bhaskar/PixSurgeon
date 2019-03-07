//The PolyLine class is used to draw multi-line.
class PolyLine: public Mode{
	unsigned int vert;
	std::vector<int> cord_x;
	std::vector<int> cord_y;
	public:
	void leftClick(int, int);
	void rightClick(int, int);
	void undeadPoints();
	void ghostPointer();
	std::string modeData();
	void draw();
	void quit();
	PolyLine();
	~PolyLine();
};

PolyLine::PolyLine(){
	setMode(2);
	this->vert = 0;
}

PolyLine::~PolyLine(){
	std::vector<int>().swap(cord_x);
	std::vector<int>().swap(cord_y);
}

void PolyLine::quit(){
	this->vert = 0;
	this->cord_x.clear();
	this->cord_y.clear();
	errorBuffer = "Mode Reseting Success";
	glutPostRedisplay();
}

std::string PolyLine::modeData(){
	return std::string("Right click to stop");
}

void PolyLine::undeadPoints(){
	if(this->vert < 1)
		return;
	curCol.setEnv();
	glPointSize(5.0);
	glBegin(GL_POINTS);
		for(int i=0;i<this->vert;++i)
			glVertex2f(this->cord_x[i], this->cord_y[i]);
	glEnd();
	curCol.setEnv();
	glBegin(GL_LINE_STRIP);
		for(int i=0;i<this->vert;++i)
			glVertex2f(this->cord_x[i], this->cord_y[i]);
	glEnd();
}

void PolyLine::ghostPointer(){
	if(this->vert < 1)
		return;
	curCol.setEnv();
	glBegin(GL_LINES);
		glVertex2f(this->cord_x[this->vert - 1], this->cord_y[this->vert - 1]);
		glVertex2f(pointerX, pointerY);
	glEnd();
}

void PolyLine::draw(){
	this->objectColour.setEnv();
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<this->vert;++i)
		glVertex2f(this->cord_x[i], this->cord_y[i]);
	glEnd();
}

void PolyLine::rightClick(int x, int y){
	this->leftClick(x, y);
	this->objectColour = curCol;
	buffer.push_back(this);
	cMode = new PolyLine;
}

void PolyLine::leftClick(int x, int y){
	this->cord_x.push_back(x);
	this->cord_y.push_back(y);
	++this->vert;
}
