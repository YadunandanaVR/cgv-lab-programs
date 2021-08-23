#include<iostream>
#include<glut.h>

using namespace std;

GLfloat d = 0;
int a=0;

void Spin() {
	d = d + 0.0005;
	if (d > 360) {
		d = 0;
	}
	glutPostRedisplay();
}


void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {

	glBegin(GL_POLYGON);
	glVertex3fv(A);       // or glVertex3f(A[0], A[1], A[2]);
	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);
	glEnd();
}

void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[]) {

	glColor3f(1, 0, 0);
	Face(V0, V1, V2, V3);

	glColor3f(0, 1, 0);
	Face(V4, V5, V6, V7);

	glColor3f(0, 0, 1);
	Face(V0, V3, V7, V4);

	glColor3f(1, 0, 1);
	Face(V1, V2, V6, V5);

	glColor3f(1, 1, 0);
	Face(V4, V5, V1, V0);

	glColor3f(1, 1, 1);
	Face(V2, V3, V7, V6);

}

void Draw()
{
	GLfloat rV[8][3];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat V[8][3] = {
						{-0.5, 0.5, 0.5},
						{ 0.5, 0.5, 0.5},
						{ 0.5,-0.5, 0.5},
						{-0.5,-0.5, 0.5},

						{-0.5, 0.5,-0.5},
						{ 0.5, 0.5,-0.5},
						{ 0.5,-0.5,-0.5},
						{-0.5,-0.5,-0.5}
	};

	//Rotation about X-axis
	if (a == 1) {
		for (int i = 0; i < 8; i++) {
			rV[i][0] = V[i][0];
			rV[i][1] = V[i][1] * cos(d) - V[i][2] * sin(d);
			rV[i][2] = V[i][1] * sin(d) + V[i][2] * cos(d);
		}
	}

	//Rotation about Y-axis
	if (a == 2) {
		for (int i = 0; i < 8; i++) {
			rV[i][0] = V[i][2] * sin(d) + V[i][0] * cos(d);
			rV[i][1] = V[i][1];
			rV[i][2] = V[i][2] * cos(d) - V[i][0] * sin(d);
		}
	}

	//Rotation about Z-axis
	if (a == 3) {
		for (int i = 0; i < 8; i++) {
			rV[i][0] = V[i][0] * cos(d) - V[i][1] * sin(d);
			rV[i][1] = V[i][0] * sin(d) + V[i][1] * cos(d);
			rV[i][2] = V[i][2];
		}
	}
	
	glLoadIdentity();
	//glRotatef(d, 1, 1, 0);
	//glRotatef(125, 1, 0, 0.5);

	if (a == 0) {
		Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	}

	Cube(rV[0], rV[1], rV[2], rV[3], rV[4], rV[5], rV[6], rV[7]);

	glutSwapBuffers();                                          
}

void MyInit() {
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		a = 1; //Rotation about X-axis
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		a = 2; //Rotation about Y-axis
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		a = 3; //Rotation about Z-axis

}

int main(int argc, char* argv[]) {

	//cout<<" 0. For No Ratation\n 1. For Rotation about X-axis\n 2. For Rotation about Y-axis\n 3. For Rotation about Z-axis\n" << endl;
	//cin>>a;

	glutInit(&argc, argv);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Cube in Spin using Transformation Matrices");
	MyInit();
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMouseFunc(mouse);
	glutMainLoop();
}