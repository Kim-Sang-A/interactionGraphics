#include "MyModuleRendering.h"


MyModuleRendering::MyModuleRendering(void)
{
}


MyModuleRendering::~MyModuleRendering(void)
{
}

void MyModuleRendering::DrawModlue(void)
{
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);
	glColor3f(0.0,0.0,0.5);
	glTranslatef(0,0.0,0.45);
	glutSolidSphere(0.3,20,20);

	glColor3f(0.5,0.5,0.5);
	glTranslatef(0,0.0,0.45);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);
}
/*
Create the geometry
*/
void MyModuleRendering::MakeGeometry(void)
{
	GLfloat mdiff3[] = {0.5,0.5,0.5,1.0};  /* Grey boxes */
	GLfloat mamb3[]  = {0.2,0.2,0.2,1.0};

	//glTranslatef(1.8,0.2,1.8);
	glTranslatef(0,0.0,-2.0);
	glColor3f(0.5,0.5,0.5);

	DrawModlue();//ÆÈ1¿À¸¥ÂÊ  
	
	glTranslatef(0.0, 0.0, 0.6);
	DrawModlue();// ÆÈ2  ¿ÞÂÊ


	glTranslatef(-0.0,0.0,-2.0);
	glRotatef(90.0f,1.0f,0.0f,0.0f);

	glColor3f(0.5,0.5,0.5);
	glTranslatef(0,0.0,-1.6);
	glTranslatef(0,0.0,0.0);
	DrawModlue();

	DrawModlue();
	glTranslatef(0,0.0,0.0);
	DrawModlue();

	glRotatef(45.0f,1.0f,0.0f,0.0f);
	DrawModlue();

	glRotatef(-45.0f,1.0f,0.0f,0.0f);
	glTranslatef(0.0,1.5,-1.0);
	glRotatef(-45.0f,1.0f,0.0f,0.0f);
	DrawModlue();

}

void MyModuleRendering::HWModuleRendering(void)
{
	fprintf(stderr,"HWModuleRendering ÇÔ¼ö ºÒ¸²\n");
printf("¿Í¿ì¿ì¿ì¿õ");

	GLfloat mdiff3[] = {0.5,0.5,0.5,1.0};  /* Grey boxes */
	GLfloat mamb3[]  = {0.2,0.2,0.2,1.0};

	/* Place a few grey boxes around the place */
	glLoadName(3);
	glColor3f(0.5,0.5,0.5);

	//glPushMatrix();
	glTranslatef(10.0,10.0,0.0);
	glTranslatef(1.8,0.2,1.8);

	glTranslatef(0,0.0,-2.0);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);
	glColor3f(0.0,0.0,0.5);
	glTranslatef(0,0.0,0.45);
	glutSolidSphere(0.3,20,20);

	glColor3f(0.5,0.5,0.5);
	glTranslatef(0,0.0,0.45);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);

	glTranslatef(-3.6,0.0,0.0);

	glColor3f(0.5,0.5,0.5);
	glTranslatef(0,0.0,-1.6);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glColor3f(0.0,0.0,0.5);
	glutSolidSphere(0.3,20,20);

	glColor3f(0.5,0.5,0.5);
	glTranslatef(0,0.0,0.45);
	glutSolidCube(0.4);
	glTranslatef(0,0.0,0.4);
	glutSolidCube(0.4);

}