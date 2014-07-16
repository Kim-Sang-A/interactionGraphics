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
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();  //단위행렬로 만든다
	////투영평면을 만든다, 공간을 넓히고 좁히는 개념? Near Far
	//glOrtho(pLeftPlane, pRightPlane, pBottomPlane, pTopPlane, pNearPlane, pFarPlane); 
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////카메라 시점과 관련있는 함수 
	////카메라의 위치와 카메라가 바라보는 곳의 위치등을 설정한다
	//gluLookAt(pEye[0], pEye[1], pEye[2],pCenter[0], pCenter[1], pCenter[2],pUp[0], pUp[1], pUp[2]);
}

//무슨역할?
void GlDrawMarker(FbxAMatrix& pGlobalPosition)
{
	//glColor3f(0.0, 1.0, 1.0);
	//glLineWidth(3.0);

	//glPushMatrix();
	//glMultMatrixd((double*) pGlobalPosition);

	//glBegin(GL_LINE_LOOP);
	//glVertex3f(+10.0f, -10.0f, +10.0f);
	//glVertex3f(+10.0f, -10.0f, -10.0f);
	//glVertex3f(+10.0f, +10.0f, -10.0f);
	//glVertex3f(+10.0f, +10.0f, +10.0f);

	//glVertex3f(+10.0f, +10.0f, +10.0f);
	//glVertex3f(+10.0f, +10.0f, -10.0f);
	//glVertex3f(-10.0f, +10.0f, -10.0f);
	//glVertex3f(-10.0f, +10.0f, +10.0f);

	//glVertex3f(+10.0f, +10.0f, +10.0f);
	//glVertex3f(-10.0f, +10.0f, +10.0f);
	//glVertex3f(-10.0f, -10.0f, +10.0f);
	//glVertex3f(+10.0f, -10.0f, +10.0f);

	//glVertex3f(-10.0f, -10.0f, +10.0f);
	//glVertex3f(-10.0f, +10.0f, +10.0f);
	//glVertex3f(-10.0f, +10.0f, -10.0f);
	//glVertex3f(-10.0f, -10.0f, -10.0f);

	//glVertex3f(-10.0f, -10.0f, +10.0f);
	//glVertex3f(-10.0f, -10.0f, -10.0f);
	//glVertex3f(+10.0f, -10.0f, -10.0f);
	//glVertex3f(+10.0f, -10.0f, +10.0f);

	//glVertex3f(-10.0f, -10.0f, -10.0f);
	//glVertex3f(-10.0f, +10.0f, -10.0f);
	//glVertex3f(+10.0f, +10.0f, -10.0f);
	//glVertex3f(+10.0f, -10.0f, -10.0f);
	//glEnd();

	//glPopMatrix();
}
//Sanga Modify
//Skeleton View Joint 정보 보기 
void GlDrawLimbNode(FbxAMatrix& pGlobalBasePosition, FbxAMatrix& pGlobalEndPosition)
{
	glColor3f(1.0, 1.0, 1.0);

	/*원래 예제에 있던 코드 
		glLineWidth(30.0);
		glBegin(GL_LINES);
		glVertex3d(pGlobalBasePosition.GetT()[0],pGlobalBasePosition.GetT()[1],pGlobalBasePosition.GetT()[2]);
		glVertex3d(pGlobalEndPosition.GetT()[0],pGlobalEndPosition.GetT()[1],pGlobalEndPosition.GetT()[2]);

		glEnd();
	*/

	//glLineWidth(30.0);
	//glTranslated(pGlobalBasePosition.GetT()[0],pGlobalBasePosition.GetT()[1],pGlobalBasePosition.GetT()[2]);
	//glRotated(10.0f,pGlobalBasePosition.GetR()[0],pGlobalBasePosition.GetR()[1],pGlobalBasePosition.GetR()[2]);

	//glutSolidCube(0.2);
	/* GetR 은 회전 x y z뽑고, GetT는 변환행렬 뽑는다 */
	//glTranslated(pGlobalEndPosition.GetT()[0],pGlobalEndPosition.GetT()[1],pGlobalEndPosition.GetT()[2]);
	//glRotated(10.0f,pGlobalEndPosition.GetR()[0],pGlobalEndPosition.GetR()[1],pGlobalEndPosition.GetR()[2]);	
	//glutSolidCube(0.2);

	glPointSize(10.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	
	glVertex3d(pGlobalBasePosition.GetT()[0],pGlobalBasePosition.GetT()[1],pGlobalBasePosition.GetT()[2]);
	glVertex3d(pGlobalEndPosition.GetT()[0],pGlobalEndPosition.GetT()[1],pGlobalEndPosition.GetT()[2]);

	glEnd();

}

//무슨 역할? 다 지워도 달라진 것이 없음
void GlDrawCamera(FbxAMatrix& pGlobalPosition, double pRoll)
{
	//glColor3d(1.0, 1.0, 1.0);
	//glLineWidth(1.0);

	//glPushMatrix();
	//glMultMatrixd((double*) pGlobalPosition);
	//glRotated(pRoll, 1.0, 0.0, 0.0);

	//int i;
	//float lCamera[10][2] = {{ 0, 5.5 }, { -3, 4.5 },
	//{ -3, 7.5 }, { -6, 10.5 }, { -23, 10.5 },
	//{ -23, -4.5 }, { -20, -7.5 }, { -3, -7.5 },
	//{ -3, -4.5 }, { 0, -5.5 }   };

	//glBegin( GL_LINE_LOOP );
	//{
	//	for (i = 0; i < 10; i++)
	//	{
	//		glVertex3f(lCamera[i][0], lCamera[i][1], 4.5);
	//	}
	//}
	//glEnd();

	//glBegin( GL_LINE_LOOP );
	//{
	//	for (i = 0; i < 10; i++)
	//	{
	//		glVertex3f(lCamera[i][0], lCamera[i][1], -4.5);
	//	}
	//}
	//glEnd();

	//for (i = 0; i < 10; i++)
	//{
	//	glBegin( GL_LINES );
	//	{
	//		glVertex3f(lCamera[i][0], lCamera[i][1], -4.5);
	//		glVertex3f(lCamera[i][0], lCamera[i][1], 4.5);
	//	}
	//	glEnd();
	//}

	//glPopMatrix();
}


void GlDrawCrossHair(FbxAMatrix& pGlobalPosition)
{
	/*glColor3f(1.0, 1.0, 1.0);
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

	glPopMatrix();*/
}
