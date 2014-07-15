/****************************************************************************************

Copyright (C) 2014 Autodesk, Inc.
All rights reserved.

Use of this software is subject to the terms of the Autodesk license agreement
provided at the time of installation or download, or which otherwise accompanies
this software in either electronic or hard copy form.

****************************************************************************************/

#include "GlFunction.h"

void GlSetCameraPerspective(double pFieldOfViewY,
	double pAspect,
	double pNearPlane,
	double pFarPlane,
	FbxVector4& pEye,
	FbxVector4& pCenter,
	FbxVector4& pUp,
	double  pFilmOffsetX,
	double  pFilmOffsetY)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glTranslated( pFilmOffsetX, pFilmOffsetY, 0);
	gluPerspective(pFieldOfViewY, 
		pAspect, 
		pNearPlane, 
		pFarPlane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pEye[0], pEye[1], pEye[2],
		pCenter[0], pCenter[1], pCenter[2],
		pUp[0], pUp[1], pUp[2]);
}


void GlSetCameraOrthogonal(double pLeftPlane,
	double pRightPlane,
	double pBottomPlane,
	double pTopPlane,
	double pNearPlane,
	double pFarPlane,
	FbxVector4& pEye,
	FbxVector4& pCenter,
	FbxVector4& pUp)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  
	glOrtho(pLeftPlane, 
		pRightPlane, 
		pBottomPlane, 
		pTopPlane, 
		pNearPlane, 
		pFarPlane); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pEye[0], pEye[1], pEye[2],
		pCenter[0], pCenter[1], pCenter[2],
		pUp[0], pUp[1], pUp[2]);
}


void GlDrawMarker(FbxAMatrix& pGlobalPosition)
{
	glColor3f(0.0, 1.0, 1.0);
	glLineWidth(3.0);

	glPushMatrix();
	glMultMatrixd((double*) pGlobalPosition);

	glBegin(GL_LINE_LOOP);
	glVertex3f(+10.0f, -10.0f, +10.0f);
	glVertex3f(+10.0f, -10.0f, -10.0f);
	glVertex3f(+10.0f, +10.0f, -10.0f);
	glVertex3f(+10.0f, +10.0f, +10.0f);

	glVertex3f(+10.0f, +10.0f, +10.0f);
	glVertex3f(+10.0f, +10.0f, -10.0f);
	glVertex3f(-10.0f, +10.0f, -10.0f);
	glVertex3f(-10.0f, +10.0f, +10.0f);

	glVertex3f(+10.0f, +10.0f, +10.0f);
	glVertex3f(-10.0f, +10.0f, +10.0f);
	glVertex3f(-10.0f, -10.0f, +10.0f);
	glVertex3f(+10.0f, -10.0f, +10.0f);

	glVertex3f(-10.0f, -10.0f, +10.0f);
	glVertex3f(-10.0f, +10.0f, +10.0f);
	glVertex3f(-10.0f, +10.0f, -10.0f);
	glVertex3f(-10.0f, -10.0f, -10.0f);

	glVertex3f(-10.0f, -10.0f, +10.0f);
	glVertex3f(-10.0f, -10.0f, -10.0f);
	glVertex3f(+10.0f, -10.0f, -10.0f);
	glVertex3f(+10.0f, -10.0f, +10.0f);

	glVertex3f(-10.0f, -10.0f, -10.0f);
	glVertex3f(-10.0f, +10.0f, -10.0f);
	glVertex3f(+10.0f, +10.0f, -10.0f);
	glVertex3f(+10.0f, -10.0f, -10.0f);
	glEnd();

	glPopMatrix();
}

void GlDrawLimbNode(FbxAMatrix& pGlobalBasePosition, FbxAMatrix& pGlobalEndPosition)
{
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(30.0);
	//glTranslated(pGlobalBasePosition.GetT()[0],pGlobalBasePosition.GetT()[1],pGlobalBasePosition.GetT()[2]);
	//glRotated(10.0f,pGlobalBasePosition.GetR()[0],pGlobalBasePosition.GetR()[1],pGlobalBasePosition.GetR()[2]);

	//glutSolidCube(0.2);
	//glTranslated(pGlobalEndPosition.GetT()[0],pGlobalEndPosition.GetT()[1],pGlobalEndPosition.GetT()[2]);
	//glRotated(10.0f,pGlobalEndPosition.GetR()[0],pGlobalEndPosition.GetR()[1],pGlobalEndPosition.GetR()[2]);

	//glutSolidCube(0.2);
	 glPointSize(10.0);
glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);
	glBegin(GL_LINES);
	glVertex3d(pGlobalBasePosition.GetT()[0],pGlobalBasePosition.GetT()[1],pGlobalBasePosition.GetT()[2]);
	glVertex3d(pGlobalEndPosition.GetT()[0],pGlobalEndPosition.GetT()[1],pGlobalEndPosition.GetT()[2]);

	glEnd();

}

void GlDrawCamera(FbxAMatrix& pGlobalPosition, double pRoll)
{
	glColor3d(1.0, 1.0, 1.0);
	glLineWidth(1.0);

	glPushMatrix();
	glMultMatrixd((double*) pGlobalPosition);
	glRotated(pRoll, 1.0, 0.0, 0.0);

	int i;
	float lCamera[10][2] = {{ 0, 5.5 }, { -3, 4.5 },
	{ -3, 7.5 }, { -6, 10.5 }, { -23, 10.5 },
	{ -23, -4.5 }, { -20, -7.5 }, { -3, -7.5 },
	{ -3, -4.5 }, { 0, -5.5 }   };

	glBegin( GL_LINE_LOOP );
	{
		for (i = 0; i < 10; i++)
		{
			glVertex3f(lCamera[i][0], lCamera[i][1], 4.5);
		}
	}
	glEnd();

	glBegin( GL_LINE_LOOP );
	{
		for (i = 0; i < 10; i++)
		{
			glVertex3f(lCamera[i][0], lCamera[i][1], -4.5);
		}
	}
	glEnd();

	for (i = 0; i < 10; i++)
	{
		glBegin( GL_LINES );
		{
			glVertex3f(lCamera[i][0], lCamera[i][1], -4.5);
			glVertex3f(lCamera[i][0], lCamera[i][1], 4.5);
		}
		glEnd();
	}

	glPopMatrix();
}


void GlDrawCrossHair(FbxAMatrix& pGlobalPosition)
{
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(1.0);

	glPushMatrix();
	glMultMatrixd((double*) pGlobalPosition);

	double lCrossHair[6][3] = { { -3, 0, 0 }, { 3, 0, 0 },
	{ 0, -3, 0 }, { 0, 3, 0 },
	{ 0, 0, -3 }, { 0, 0, 3 } };

	glBegin(GL_LINES);

	glVertex3dv(lCrossHair[0]);
	glVertex3dv(lCrossHair[1]);

	glEnd();

	glBegin(GL_LINES);

	glVertex3dv(lCrossHair[2]);
	glVertex3dv(lCrossHair[3]);

	glEnd();

	glBegin(GL_LINES);

	glVertex3dv(lCrossHair[4]);
	glVertex3dv(lCrossHair[5]);

	glEnd();

	glPopMatrix();
}
