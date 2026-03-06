#include<GL/glut.h>
#include"ball.h"

float ballY = 2.0f;
float speedY = 0.0f;
const float gravity = -0.01f;

void drawBall(){
	glColor3f(1.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0f, ballY, -5.0f);
	glutSolidSphere(0.5f, 30, 30);
	glPopMatrix();
}

void updateBall(){
	speedY += gravity;
	ballY += speedY;

	if(ballY <= -2.0f){
		ballY =-2.0f;
		speedY = -speedY * 0.8f;
	}
}
