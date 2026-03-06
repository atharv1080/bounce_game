#include<GL/glut.h>
#include"ball.h"
#include"game.h"

void keyboard(unsigned char key, int x, int y){
    if(key == ' '){
        setBallSpeedY(0.2f);
    }
}

void display(){ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawFloor();
	drawBall();
	glutSwapBuffers();
}

void reshape(int width, int height){
    if(height == 0) height = 1;
    float aspect = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int){
	updateBall();
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void drawFloor(){
    glColor3f(0.2, 0.8, 0.2);

    glBegin(GL_QUADS);
        glVertex3f(-5,-2,-5);
        glVertex3f(5,-2,-5);
        glVertex3f(5,-2,5);
        glVertex3f(-5,-2,5);
    glEnd();
}
