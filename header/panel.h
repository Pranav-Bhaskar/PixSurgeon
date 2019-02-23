class Panel{
	void showOptions();
	void showPalet();
	void setBackground();
	ColourHandler* backGround;
	ColourHandler* foreGround;
	ColourHandler* textCol;
	public:
	Panel();
	void draw();
	void leftClick(int, int);
};

Panel::Panel(){
	this->backGround = new ColourHandler(0, 0, 0, 0);
	this->foreGround = new ColourHandler(1, 1, 1, 0);
	this->textCol = new ColourHandler(0, 0, 0, 0);
}

void Panel::setBackground(){
	this->backGround->setColour();
	glBegin(GL_POLYGON);
		glVertex2f(1200, 0);
		glVertex2f(1200, 690);
		glVertex2f(1365, 690);
		glVertex2f(1365, 0);
	glEnd();
}

void Panel::draw(){
	glBegin(GL_LINES);
		glVertex2f(1200, 0);
		glVertex2f(1200, 690);
	glEnd();
	this->setBackground();
	this->showOptions();
	this->showPalet();
}

void Panel::showOptions(){
	this->foreGround->setColour();
	drawString(GLUT_BITMAP_HELVETICA_10, 1260, 645, std::string("MODES"));
	for(int i=0;i<modes.size();++i){
		this->foreGround->setColour();
		glBegin(GL_POLYGON);
			glVertex2f(1220, 620 - (i * 21));
			glVertex2f(1220, 634 - (i * 21));
			glVertex2f(1350, 634 - (i * 21));
			glVertex2f(1350, 620 - (i * 21));
		glEnd();
		this->textCol->setColour();
		float sp_x = 1285 - (modes[i].length()*3);
		float sp_y = 620 - (i * 21) + 4;
		drawString(GLUT_BITMAP_HELVETICA_10, sp_x, sp_y, modes[i]);
		if(i == cMode->getMode()){
			this->foreGround->setColour();
			drawString(GLUT_BITMAP_HELVETICA_10, 1212, sp_y, std::string(">"));
			drawString(GLUT_BITMAP_HELVETICA_10, 1354, sp_y, std::string("<"));
		}
	}
}
//340
void Panel::showPalet(){ //1240
	
}

void Panel::leftClick(int x ,int y){
	if(x < 1220 || x > 1350)
		return;
	int nextMode = -1;
	for(int i=0;i<modes.size();++i){
		if(y > (620 - (i * 21)) && (y < (634 - (i * 21)))){
			switch(i){
			case 0 : cMode = new None;
				return;
			case 1 : cMode = new Line;
				return;
			case 2 : //cMode = new PolyLine;
				return;
			case 3 : //cMode = new PolyNom;
				return;
			}
		}
	}
}
