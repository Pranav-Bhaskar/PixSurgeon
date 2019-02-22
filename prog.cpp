#include "./header/prog.h"

int main(int argc, char* argv[]){
	cMode = new Line;
	glutInit(&argc, argv);
	glutInitWindowSize(1365, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pix Surgeon");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(passivePointer);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
