class Loader{
	private:
	unsigned char* pix;
	std::string fileName;
	public:
	Loader(std::string);
};

Loader::Loader(std::string l){
	this->fileName = l;
	if(fileName == ""){
		errorBuffer = "ERROR : Name Not Provided ";
		return;
	}
	this->fileName += ".tga";
	try{
		std::ifstream file;
		file.open(fileName.c_str());
		short header[9];
		pix = new unsigned char [1200 * 694 * 3];
		short expected[] = {0, 2, 0, 0, 0, 0, (short) 1200, (short) 694, 24};
		file.read((char*)&header, sizeof(header));
		for(int i=0;i<9;++i)
			if(header[i] != expected[i])
				throw "File Incorrect.";
		file.read((char*)pix, 2498400);
		file.close();
		Mode* temp = new Render(pix);
		buffer.push_back(temp);
		errorBuffer = "File Loaded  ";
	}catch(...){
		errorBuffer = "ERROR : Could'nt Read From File.";
	}
}
