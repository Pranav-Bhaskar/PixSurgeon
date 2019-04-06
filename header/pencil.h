class Pencil: public Mode{
	private:
	unsigned int vert;
	std::vector<int> cord_x;
	std::vector<int> cord_y;
	public:
	void leftClick(int, int);
	void draw();
	Pencil();
	~Pencil();
	void quit();
	std::string modeData();
	void ghostPointer();
};

Pencil::Pencil(){
	setMode(4);
	this->vert = 0;
}

std::string Pencil::modeData(){
	return std::string("Drag to Draw");
}

void Pencil::draw(){
	this->objectColour.setEnv();
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<this->vert;++i)
		glVertex2f(cord_x[i], cord_y[i]);
	glEnd();
}

void Pencil::leftClick(int, int){
	this->objectColour = curCol;
	buffer.push_back(this);
	cMode = new Pencil;
}

void Pencil::quit(){
	this->vert = 0;
	cord_x.clear();
	cord_y.clear();
	errorBuffer = "Mode Reseting Success";
}

Pencil::~Pencil(){
	std::vector<int>().swap(cord_x);
	std::vector<int>().swap(cord_y);
}

void Pencil::ghostPointer(){
	curCol.setEnv();
	glBegin(GL_LINE_STRIP);
		for(int i=0;i<this->vert;++i)
			glVertex2f(this->cord_x[i], this->cord_y[i]);
	glEnd();
	if(!keyDownStat)
		return;
	this->cord_x.push_back(pointerX);
	this->cord_y.push_back(pointerY);
	++this->vert;
}
