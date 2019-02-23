//The None class is used to do nothing.
class None: public Mode{
	//void right_click();
	public:
	void leftClick(int, int);
	std::string modeData();
	void draw();
	void quit();
	None();
};

None::None(){
	setMode(0);
}

std::string None::modeData(){
	return std::string("This Mode does NOTHING");	
}

void None::draw(){}

void None::leftClick(int x, int y){}

void None::quit(){}
