void display(){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	drawString (GLUT_BITMAP_HELVETICA_18, -1.0, -1.0, (char*)"Press Esc to quit");
	glFlush();
}

void drawString (void *font, float x, float y, char *str){
	char *ch;
	glRasterPos3f(x, y, 0.0);
	for(ch= str; *ch; ch++)
		glutBitmapCharacter(font, (int)*ch);
}

void keyboard(unsigned char key, int x, int y){
	std::cout<<x<<" : "<<y<<std::endl;
	if(key == 27){
		std::cout<<"Exitting...\n";
		exit(0);
	}
	else
		std::cout<<"You pressed "<<key<<std::endl;
}
