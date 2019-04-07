//The None class is used to do nothing.
class None: public Mode{
	public:
	std::string modeData();
	void draw();
	void quit();
	None();
};

None::None(){
	setMode(0);
	this->makeMenu();
}

std::string None::modeData(){
	return std::string("NOTHING");	
}

void None::draw(){}

void None::quit(){}
