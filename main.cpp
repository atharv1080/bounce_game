#include<GL/glut.h>

float ballY = 2.0f;
float speedY = 0.0f;
const float gravity = -0.01f;

void drawBall(){
	glPushMatrix();
	glTranslatef(0.0f, ballY, -1.0f);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();
}

void update(){
	speedY += gravity;
	ballY += speedY;

	if(ballY <= -1.5f){
		ballY = -1.5f;
		speedY = -speedY * 0.8f;
	}
	glutPostRedisplay();
}

void timer(int){
	update();
	glutTimerFunc(16, timer, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawBall();

	glutSwapBuffers();
}

void init(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("Bouncing Ball");

	init();

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutTimerFunc(16, timer, 0);
	glutMainLoop();
	return 0;
}
