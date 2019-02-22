class ColourHandler{
	private:
	double red;
	double green;
	double blue;
	double alpha;
	public:
	void setColour();
	void getColour(double, double, double, double);
	ColourHandler();
	ColourHandler(ColourHandler&);
	void operator =(ColourHandler&);
};

void ColourHandler::setColour(){
	glColor4d(this->red, this->green, this->blue, this->alpha);
}

void ColourHandler::getColour(double a, double b, double c, double d){
	this->red = a;
	this->green = b;
	this->blue = c;
	this->alpha = d;
}

ColourHandler::ColourHandler(){
	this->red = this->green = this->blue = this->alpha = 0.0;
}

ColourHandler::ColourHandler(ColourHandler& col){
	this->red = col.red;
	this->green = col.green;
	this->blue = col.blue;
	this->alpha = col.alpha;
}

void ColourHandler::operator =(ColourHandler& col){
	this->red = col.red;
	this->green = col.green;
	this->blue = col.blue;
	this->alpha = col.alpha;
}

