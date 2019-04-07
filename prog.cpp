#include "./header/prog.h"

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	cMode = new None;
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pix Surgeon");
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMotionFunc(activePointer);
	glutPassiveMotionFunc(passivePointer);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
