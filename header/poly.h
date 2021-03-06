//The PolyNom class is used to draw a Polygon.
class PolyNom: public Mode{
	unsigned int vert;
	std::vector<int> cord_x;
	std::vector<int> cord_y;
	protected:
	void makeMenu();
	public:
	void leftClick(int, int);
	void menuOption(int);
	void undeadPoints();
	void ghostPointer();
	std::string modeData();
	void draw();
	void quit();
	PolyNom();
	~PolyNom();
};

PolyNom::PolyNom(){
	setMode(3);
	this->vert = 0;
}

PolyNom::~PolyNom(){
	std::vector<int>().swap(cord_x);
	std::vector<int>().swap(cord_y);
}

void PolyNom::quit(){
	this->vert = 0;
	this->cord_x.clear();
	this->cord_y.clear();
	errorBuffer = "Mode Reseting Success";
}

void PolyNom::undeadPoints(){
	if(this->vert < 1)
		return;
	curCol.setEnv();
	glPointSize(5.0);
	glBegin(GL_POINTS);
		for(int i=0;i<this->vert;++i)
			glVertex2f(this->cord_x[i], this->cord_y[i]);
	glEnd();
}

void PolyNom::ghostPointer(){
	if(this->vert < 1)
		return;
	curCol.setEnv();
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<this->vert;++i)
			glVertex2f(this->cord_x[i], this->cord_y[i]);
		glVertex2f(pointerX, pointerY);
	glEnd();
}

std::string PolyNom::modeData(){
	return std::string("Right click to stop");
}

void PolyNom::draw(){
	this->objectColour.setEnv();
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<this->vert;++i)
		glVertex2f(cord_x[i], cord_y[i]);
	glEnd();
}

void PolyNom::menuOption(int opt){
	this->objectColour = curCol;
	buffer.push_back(this);
	cMode = new PolyNom;
}

void PolyNom::makeMenu(){
	this->makeSizeMenu();
	glutDetachMenu(GLUT_RIGHT_BUTTON);
	this->rightMainMenu = glutCreateMenu(mainMenu);
	glutAddMenuEntry("Done", 0);
	glutAddSubMenu("Size", this->sizeMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}	

void PolyNom::leftClick(int x, int y){
	if(this->cord_x.size() == 0)
		this->makeMenu();
	this->cord_x.push_back(x);
	this->cord_y.push_back(y);
	++this->vert;
}
