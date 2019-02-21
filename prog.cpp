#include "./header/prog.h"

int main(int argc, char* argv[]){
	cMode = new Line;
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pix Surgeon");
	glutMouseFunc(mouseClick);
	glutDisplayFunc(display);
	glutPassiveMotionFunc(passivePointer);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
