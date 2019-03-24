class Bucket:public Mode{
	private:
	void fill();
	void store(int, int);
	bool isBack(unsigned char[3], unsigned char[3]);
	std::vector<std::pair<int, int>> points;
	public:
	std::string modeData();
	Bucket();
	void draw();
	void leftClick(int, int);
};

Bucket::Bucket(){
	setMode(5);
}

std::string Bucket::modeData(){
	return std::string("Click To Fill");
}

void Bucket::store(int cordX, int cordY){
	std::vector<std::pair<int, int>> buff;
	buff.push_back({cordX, cordY});
	int size = 1200 * 690 * 3;
	unsigned char* pixels = new unsigned char [size];
	glReadPixels(0, 10, 1200, 690, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	unsigned char coords[1200][690];
	for(int i=0;i<1200;++i)
		for(int j=0;j<690;++j)
			coords[i][j] = 0;
	while(buff.size()){
		if((buff[0].first > 0) && (buff[0].first < 1200) && ((buff[0].second + 1) > 0) && ((buff[0].second + 1) < 690)){
			if(coords[buff[0].first][buff[0].second + 1] == 0){
				coords[buff[0].first][buff[0].second + 1] = 1;
				if((pixels[((cordY*1200)+cordX)*3] == pixels[(((buff[0].second + 1)*1200)+buff[0].first)*3]) && (pixels[(((cordY*1200)+cordX)*3)+1] == pixels[((((buff[0].second + 1)*1200)+buff[0].first)*3)+1])&& (pixels[(((cordY*1200)+cordX)*3)+2] == pixels[((((buff[0].second + 1)*1200)+buff[0].first)*3)+2]))
					buff.push_back({buff[0].first, buff[0].second + 1});
				}
		}
		if((buff[0].first > 0) && (buff[0].first < 1200) && ((buff[0].second - 1) > 0) && ((buff[0].second - 1) < 690)){
			if(coords[buff[0].first][buff[0].second - 1] == 0){
				coords[buff[0].first][buff[0].second - 1] = 1;
				if((pixels[((cordY*1200)+cordX)*3] == pixels[(((buff[0].second - 1)*1200)+buff[0].first)*3]) && (pixels[(((cordY*1200)+cordX)*3)+1] == pixels[((((buff[0].second - 1)*1200)+buff[0].first)*3)+1])&& (pixels[(((cordY*1200)+cordX)*3)+2] == pixels[((((buff[0].second - 1)*1200)+buff[0].first)*3)+2]))
					buff.push_back({buff[0].first, buff[0].second - 1});
				}
		}
		if(((buff[0].first + 1) > 0) && ((buff[0].first + 1) < 1200) && (buff[0].second > 0) && (buff[0].second < 690)){
			if(coords[buff[0].first + 1][buff[0].second] == 0){
				coords[buff[0].first + 1][buff[0].second] = 1;
				if((pixels[((cordY*1200)+cordX)*3] == pixels[(((buff[0].second)*1200)+buff[0].first + 1)*3]) && (pixels[(((cordY*1200)+cordX)*3)+1] == pixels[((((buff[0].second)*1200)+buff[0].first + 1)*3)+1])&& (pixels[(((cordY*1200)+cordX)*3)+2] == pixels[((((buff[0].second)*1200)+buff[0].first + 1)*3)+2]))
					buff.push_back({buff[0].first + 1, buff[0].second});
				}
		}
		if(((buff[0].first - 1) > 0) && ((buff[0].first - 1) < 1200) && (buff[0].second > 0) && (buff[0].second < 690)){
			if(coords[buff[0].first - 1][buff[0].second] == 0){
				coords[buff[0].first - 1][buff[0].second] = 1;
				if((pixels[((cordY*1200)+cordX)*3] == pixels[(((buff[0].second)*1200)+buff[0].first - 1)*3]) && (pixels[(((cordY*1200)+cordX)*3)+1] == pixels[((((buff[0].second)*1200)+buff[0].first - 1)*3)+1])&& (pixels[(((cordY*1200)+cordX)*3)+2] == pixels[((((buff[0].second)*1200)+buff[0].first - 1)*3)+2]))
					buff.push_back({buff[0].first - 1, buff[0].second});
				}
		}
		coords[buff[0].first][buff[0].second] = 1;
		points.push_back(buff[0]);
		buff.erase(buff.begin());
	}
}

void Bucket::draw(){
	this->objectColour.setEnv();
	glBegin(GL_POINTS);
	for(int i=0;i<this->points.size();++i){
		glVertex2f(points[i].first, points[i].second - 1.75);
		glVertex2f(points[i].first, points[i].second - 1.5);
		glVertex2f(points[i].first, points[i].second - 1.25);
	}
	glEnd();
}

void Bucket::leftClick(int x, int y){
	this->store(x, y);
	this->objectColour = curCol;
	buffer.push_back(this);
	cMode = new Bucket;
	glutPostRedisplay();
}
