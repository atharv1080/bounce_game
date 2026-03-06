#include<GL/glut.h>
#include"init.h"
#include"game.h"

int main(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bounce");
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);
	glutTimerFunc(16, timer, 0);
	glutMainLoop();
}
