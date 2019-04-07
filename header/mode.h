//This is the parent class of all the mode classes we could use a single pointer to get current mode because of it.
//To be inherited publically.
class Mode{
	protected:
	void makeSizeMenu();
	int sizeMenu;
	void setMode(unsigned int);
	unsigned int mode;
	ColourHandler objectColour;
	virtual void makeMenu();
	int rightMainMenu;
	public:
	Mode();
	unsigned int getMode();
	virtual void menuOption(int);
	virtual unsigned char* sendPixels();
	virtual void leftClick(int, int);
	virtual void draw()=0;
	virtual std::string modeData();
	virtual void quit();
	virtual void ghostPointer();	//The dotted line which follows your
	virtual void undeadPoints();	//The Points which were clicked at some time in the history
};

Mode::Mode(){
}

void Mode::setMode(unsigned int update){
	this->mode = update;
}

unsigned char* Mode::sendPixels(){return NULL;}

void Mode::quit(){}

std::string Mode::modeData(){return std::string("");}

void Mode::leftClick(int, int){}

void Mode::ghostPointer(){}

void Mode::undeadPoints(){}

void Mode::menuOption(int){}

void Mode::makeSizeMenu(){
	this->sizeMenu = glutCreateMenu(pointSize);
	glutAddMenuEntry("1px", 1);
	glutAddMenuEntry("4px", 2);
	glutAddMenuEntry("8px", 3);
}

void Mode::makeMenu(){
	this->makeSizeMenu();
	glutDetachMenu(GLUT_RIGHT_BUTTON);
	this->rightMainMenu = glutCreateMenu(mainMenu);
	glutAddSubMenu("Size", this->sizeMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

unsigned int Mode::getMode(){
	return this->mode;
}
