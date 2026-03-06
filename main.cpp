#include<GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//place for adding ball
	
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("Bouncing Ball");

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
