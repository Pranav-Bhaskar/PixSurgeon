class Eraser: public Mode{
	private:
	unsigned int vert;
	std::vector<int> cord_x;
	std::vector<int> cord_y;
	unsigned int size;
	int max(int, int);
	int min(int, int);
	public:
	void leftClick(int, int);
	void draw();
	Eraser();
	~Eraser();
	void quit();
	std::string modeData();
	void ghostPointer();
};

int Eraser::max(int a, int b){
	if(a > b)
		return a;
	return b;
}

int Eraser::min(int a, int b){
	if(a < b)
		return a;
	return b;
}

Eraser::Eraser(){
	setMode(6);
	this->vert = 0;
	this->size = 50;
	objectColour.getColour(1, 1, 1, 0);
}

std::string Eraser::modeData(){
	return std::string("Drag to Erase");
}

void Eraser::draw(){
	this->objectColour.setEnv();
	for(int i=0;i<this->vert;++i){
		glBegin(GL_POLYGON);
			glVertex2f(max(this->cord_x[i]-size, 0), min(this->cord_y[i]+size, 690));
			glVertex2f(min(this->cord_x[i]+size, 1200), min(this->cord_y[i]+size, 690));
			glVertex2f(min(this->cord_x[i]+size, 1200), max(this->cord_y[i]-size, 0));
			glVertex2f(max(this->cord_x[i]-size, 0), max(this->cord_y[i]-size, 0));
		glEnd();
	}
}

void Eraser::leftClick(int, int){
	buffer.push_back(this);
	cMode = new Eraser;
}

void Eraser::quit(){
	this->vert = 0;
	cord_x.clear();
	cord_y.clear();
	errorBuffer = "Mode Reseting Success";
	glutPostRedisplay();
}

Eraser::~Eraser(){
	std::vector<int>().swap(cord_x);
	std::vector<int>().swap(cord_y);
}

void Eraser::ghostPointer(){
	if(keyDownStat){
		this->cord_x.push_back(pointerX);
		this->cord_y.push_back(pointerY);
		++this->vert;
	}
	this->draw();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(max(pointerX-size, 0), min(pointerY+size, 690));
		glVertex2f(min(pointerX+size, 1200), min(pointerY+size, 690));
		glVertex2f(min(pointerX+size, 1200), max(pointerY-size, 0));
		glVertex2f(max(pointerX-size, 0), max(pointerY-size, 0));
	glEnd();
}
