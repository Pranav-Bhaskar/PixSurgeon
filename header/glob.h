void display(){
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0;i<buffer.size();++i)
		buffer[i]->draw();
	displayEventBar();
	glutSwapBuffers();
}

void drawString (void *font, float x, float y, char *str){
	char *ch;
	glRasterPos3f(x, y, 0.0);
	for(ch= str; *ch; ch++)
		glutBitmapCharacter(font, (int)*ch);
}

void keyboard(unsigned char key, int x, int y){
	if(key == 27){
		std::cout<<"\nExitting...\n";
		exit(0);
	}
	else{
		errorBuffer = "Error : '";
		errorBuffer.push_back(key);
		errorBuffer += "' Command not found";
	}
}

void mouseClick(int button, int state, int x, int y){
	if(GLUT_DOWN == state)
		return;
	if((693 - y <= 0) || (y < 1) || (x < 1) || (y > 693) || (x > 1365)){
		errorBuffer = "ERROR : Click out of bound";
		return ;
	}
	if(button == GLUT_LEFT_BUTTON)
		cMode->left_click(x, 693 - y);
}


void passivePointer(int x, int y){
	pointer.clear();
	pointer = "X:" + std::to_string(x) + " Y: " + std::to_string(693 - y) + " ";
	glutPostRedisplay();
}

void updateCurrentMode(){
	mode = "Mode: ";
	switch(cMode->get_mode()){
	case 0 :mode += "Select";
		break;
	case 1 :mode += "Line";
		break;
	case 2 :mode += "Polyline";
		break;
	case 3 :mode += "Polynomial";
		break;
	}
}

void displayEventBar(){		//228 -> length of the console.
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0, -10);
		glVertex2f(1365, -10);
		glVertex2f(1365, 0);
		glVertex2f(0, 0);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	updateCurrentMode();
	std::string bar;
	bar = pointer;
	while(bar.length() < 20)
		bar.push_back('_');
	bar += console;
	while(bar.length() < 160)
		bar.push_back('_');
	bar += errorBuffer;
	while(bar.length() < 200)
		bar.push_back('_');
	bar += mode;
	if(bar.length() > 227)
		bar = "ERROR : Size of Event bar is smaller than your wishlist ;)";
	drawString(GLUT_BITMAP_HELVETICA_10, 0.0, -10.0, (char*)bar.c_str());
}

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1365.0, -10.0, 693.0);
}
