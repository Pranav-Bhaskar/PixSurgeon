void display(){
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0;i<buffer.size();++i)
		buffer[i]->draw();
	glColor3f(1.0, 1.0, 1.0);
	drawString(GLUT_BITMAP_HELVETICA_10, 0.0, 0.0, (char*)"Press Esc to quit");
	glFlush();
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
	else
		std::cout<<"You pressed "<<key<<std::endl;
}

void mouseClick(int button, int state, int x, int y){
	if(GLUT_DOWN == state)
		return;
	if(button == GLUT_LEFT_BUTTON)
		cMode->left_click(x, y);
}

void passivePointer(int x, int y){
	std::cout<<"\r x :"<<x<<" y:"<<y;
}

void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1365.0, 0.0,703.0);
}
