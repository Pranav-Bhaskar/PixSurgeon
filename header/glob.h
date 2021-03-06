std::vector<std::string> cutter(std::string& str, char delimer){
	std::vector<std::string> cut;
	std::string temp;
	temp.clear();
	for(int i=0;i<str.length();++i){
		if(str[i] == delimer){
			if(!temp.empty())
				cut.push_back(temp);
			temp.clear();
			continue;
		}
		temp.push_back(str[i]);
	}
	if(!temp.empty())
		cut.push_back(temp);
	return cut;
}

void pointSize(int opt){
	skipClick = true;
	switch(opt){
	case 1:
		curCol.getSize(1);
		break;
	case 2:
		curCol.getSize(4);
		break;
	case 3:
		curCol.getSize(8);
		break;
	case 4:
		curCol.getSize(12);
		break;
	case 5:
		curCol.getSize(16);
		break;
	}
}

void eraserSizeMenuFunc(int opt){
	skipClick = true;
	cMode->menuOption(opt);
}

void mainMenu(int opt){
	skipClick = true;
	cMode->menuOption(opt);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0;i<buffer.size();++i)
		buffer[i]->draw();
	cMode->ghostPointer();
	cMode->undeadPoints();
	panel.draw();
	displayEventBar();
	glutSwapBuffers();
}

void drawString(void *font, float x, float y, std::string str){
	glRasterPos3f(x, y, 0.0);
	for(int i=0;i < str.length();i++)
		glutBitmapCharacter(font, (int)str[i]);
}

void changeColour(std::vector<std::string>& args){
	if(args.size() != 4){
		errorBuffer = "UsageError: COL <R> <G> <B> <Alpha>";
		return;
	}
	try{
		curCol.getColour(stod(args[0]), stod(args[1]), stod(args[2]), stod(args[3]));
	}
	catch(...){
		errorBuffer = "ConvertionError: Try entering numerical values";
	}
}

void processCommand(){
	console.erase(0, 5);
	if(saveMe){
		Saviour s(console);
		saveMe = false;
		console.clear();
		consoleMode = false;
		return;
	}
	if(loadMe){
		Loader l(console);
		loadMe = false;
		console.clear();
		consoleMode = false;
		return;
	}
	std::vector<std::string> args = cutter(console, ' ');
	if(args.size() < 1)
		return;
	if(args[0] == "COL"){
		args.erase(args.begin());
		changeColour(args);
	}
	else{
		errorBuffer = "Error : '" + console + "' Command not found";
	}
}

void keyboard(unsigned char key, int x, int y){
	if((key >= 'a') && (key <= 'z'))
		key -= 32;
	if(key == 13){
		if(consoleMode){
			console.pop_back();
			processCommand();
			glutPostRedisplay();
			if(consoleMode)
				console = ">>>  #";
			return;
		}
		errorBuffer = "Error : '";
		errorBuffer.push_back(key);
		errorBuffer += "' Command not found";
		glutPostRedisplay();
		return;
	}
	if((consoleMode) && (key != '`')){
		console.pop_back();
		if(key == 8 && console.length() > 5)
			console.pop_back();
		else
		if((key >= '0' && key <= '9') || ((key >= 'A') && (key <= 'Z')) || key == 32)
			console.push_back(key);
		glutPostRedisplay();
		console.push_back('#');
		return;
	}
	switch(key){
	case 27 :std::cout<<"\nExitting...\n";
		exit(0);
		break;
	case 26 :if(buffer.size() != 0){
			delete buffer[buffer.size() - 1];
			buffer.pop_back();
			errorBuffer = "Undo Successful";
		}
		break;
	case 'Q':cMode->quit();
		break;
	case '`':consoleMode = !consoleMode;
		if(consoleMode)
			console = ">>>  #";
		else
			console.clear();
		break;
	default :
		errorBuffer = "Error : '";
		errorBuffer.push_back(key);
		errorBuffer += "' Command not found";
	}
	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y){
	pointerX = x;
	pointerY = 690 - y;
	if(skipClick){
		skipClick = false;
		glutPostRedisplay();
		return;
	}
	if(saveMe || loadMe)
		return;
	if((GLUT_DOWN == state) && (button == GLUT_LEFT_BUTTON) && ((690 - y > 0) && (x < 1200))){
		keyDownStat = true;
		glutPostRedisplay();
		return ;
	}
	if(GLUT_UP == state && GLUT_LEFT_BUTTON == button)
		keyDownStat = false;
	if((690 - y < 0) || (y < 1) || (x < 1) || (y > 690) || (x > 1365)){
		errorBuffer = "ERROR : Click out of bound";
		glutPostRedisplay();
		return ;
	}
	if(button == GLUT_LEFT_BUTTON){
		if(x > 1200)
			panel.leftClick(x, 690 - y);
		else
			cMode->leftClick(x, 690 - y);
	}
	glutPostRedisplay();
}

void passivePointer(int x, int y){
	if(x > 1200 || y > 690)
		return ;
	pointerX = x;
	pointerY = 690 - y;
	pointer.clear();
	pointer = "X:" + std::to_string((int)x) + " Y: " + std::to_string((int)690 - y) + " ";
	glutPostRedisplay();
}

void activePointer(int x, int y){
	if(x > 1200 || y > 690)
		return ;
	pointerX = x;
	pointerY = 690 - y;
	pointer.clear();
	pointer = "X:" + std::to_string((int)x) + " Y: " + std::to_string((int)690 - y) + " ";
	glutPostRedisplay();
}

void updateCurrentMode(){
	if(saveMe){
		mode = " Move: SAVE <Enter File Name> ";
		return;
	}
	if(loadMe){
		mode = " Move: LOAD <Enter File Name> ";
		return;
	}
	mode = "Mode: " + modes[cMode->getMode()] + "  < " + cMode->modeData() + " >";
}

void displayEventBar(){		//228 -> length of the console.
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0, -10);
		glVertex2f(WINDOW_WIDTH, -10);
		glVertex2f(WINDOW_WIDTH, 0);
		glVertex2f(0, 0);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	updateCurrentMode();
	std::string bar;
	bar = pointer;
	while(bar.length() < 20)
		bar.push_back('_');
	bar += console;
	while(bar.length() < 150)
		bar.push_back('_');
	bar += errorBuffer;
	while(bar.length() < 180)
		bar.push_back('_');
	bar += mode;
	if(bar.length() > 225)
		bar = "ERROR : Size of Event bar is smaller than your wishlist ;)";
	drawString(GLUT_BITMAP_HELVETICA_10, 2.0, -9.0, bar);
	if(errorBuffer.length() > 0)
		std::cout<<errorBuffer<<std::endl;
	errorBuffer.clear();
}

void init(){
	consoleMode = false;
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_WIDTH, -10.0, (WINDOW_HEIGHT - 10));
}
