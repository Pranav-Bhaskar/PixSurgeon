//This is the parent class of all the mode classes we could use a single pointer to get current mode because of it.
//To be inherited publically.
class Mode{
	protected:
	void setMode(unsigned int);
	unsigned int mode;
	ColourHandler objectColour;
	//virtual void right_click()=0;	//The right click should show a menu
	public:
	unsigned int getMode();
	virtual void leftClick(int, int);
	virtual void rightClick(int, int);
	virtual void draw()=0;
	virtual std::string modeData()=0;
	virtual void quit()=0;
	virtual void ghostPointer();	//The dotted line which follows your
	virtual void undeadPoints();	//The Points which were clicked at some time in the history
};

void Mode::setMode(unsigned int update){
	this->mode = update;
}

void Mode::leftClick(int, int){}

void Mode::ghostPointer(){}

void Mode::undeadPoints(){}

void Mode::rightClick(int, int){}

unsigned int Mode::getMode(){
	return this->mode;
}
