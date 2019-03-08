class Render: public Mode{
	private:
	unsigned int size;
	unsigned char* pixels;
	public:
	Render();
	unsigned char* sendPixels();
	void draw();
};

Render::Render(){
	this->size = 1200 * 694 * 3;
	pixels = new unsigned char [size];
	glReadPixels(0, 10, 1200, 694, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
}

void Render::draw(){
	glRasterPos2f(0, 0);
	glDrawPixels(1200, 694, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
}

unsigned char* Render::sendPixels(){
	return pixels;
}
