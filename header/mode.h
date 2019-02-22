//This is the parent class of all the mode classes we could use a single pointer to get current mode because of it.
//To be inherited publically.
class Mode{
	protected:
	void set_mode(unsigned int);
	unsigned int mode;
	ColourHandler objectColour;
	//virtual void right_click()=0;	//The right click should show a menu
	public:
	unsigned int get_mode();
	virtual void left_click(int, int)=0;	//The left click should also serve a purpose
	virtual void draw()=0;
	virtual std::string modeData()=0;
	virtual void quit()=0;
};

void Mode::set_mode(unsigned int update){
	this->mode = update;
}

unsigned int Mode::get_mode(){
	return mode;
}
