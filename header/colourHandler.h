class ColourHandler{
	private:
	float size;
	double red;
	double green;
	double blue;
	double alpha;
	public:
	void setEnv();
	void swap(ColourHandler&);
	void getColour(double, double, double, double);
	ColourHandler();
	ColourHandler(double, double, double, double);
	ColourHandler(ColourHandler&);
	void operator =(ColourHandler&);
};

ColourHandler::ColourHandler(double a, double b, double c, double d){
	this->red = a;
	this->green = b;
	this->blue = c;
	this->alpha = d;
	this->size = 1.0;
}

void ColourHandler::swap(ColourHandler& col){
	double temp;
	temp = this->red;
	this->red = col.red;
	col.red = temp;
	
	temp = this->green;
	this->green = col.green;
	col.green = temp;
	
	temp = this->blue;
	this->blue = col.blue;
	col.blue = temp;
	
	temp = this->size;
	this->size = col.size;
	col.size = temp;
}

void ColourHandler::setEnv(){
	glColor4d(this->red, this->green, this->blue, this->alpha);
	glPointSize(this->size);
}

void ColourHandler::getColour(double a, double b, double c, double d = 0.0000){
	this->red = a;
	this->green = b;
	this->blue = c;
	this->alpha = d;
}

ColourHandler::ColourHandler(){
	this->size = this->red = this->green = this->blue = this->alpha = 0.0;
}

ColourHandler::ColourHandler(ColourHandler& col){
	this->red = col.red;
	this->green = col.green;
	this->blue = col.blue;
	this->alpha = col.alpha;
	this->size = col.size;
}

void ColourHandler::operator =(ColourHandler& col){
	this->red = col.red;
	this->green = col.green;
	this->blue = col.blue;
	this->alpha = col.alpha;
	this->size = col.size;
}
