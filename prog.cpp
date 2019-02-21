#include "./header/prog.h"

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pix Surgeon");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
