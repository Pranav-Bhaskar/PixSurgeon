class Saviour{
	private:
	std::string fileName;
	unsigned char* pixels;
	void getPixels();
	void saveFile();
	public:
	Saviour(std::string);
};

Saviour::Saviour(std::string s){
	this->fileName = s;
	if(fileName == ""){
		errorBuffer = "ERROR : Name Not Provided ";
		return;
	}
	this->fileName += ".tga";
	this->getPixels();
	this->saveFile();
	delete cMode;
	cMode = new None;
	errorBuffer = "File Saved  ";
}

void Saviour::getPixels(){
	pixels = cMode->sendPixels();
}

void Saviour::saveFile(){
	std::ofstream file;
	file.open(fileName.c_str());
	short header[] = {0, 2, 0, 0, 0, 0, (short) 1200, (short) 694, 24};
	file.write((char *)& header, sizeof(header));
	file.write((char *)pixels, 2498400);
	file.close();
}
