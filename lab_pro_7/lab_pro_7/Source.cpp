#include<glut.h>
#include<iostream>

using namespace std;

int N;

void triangle(GLfloat A[], GLfloat B[], GLfloat C[]) {

	glBegin(GL_TRIANGLES);
	glVertex3fv(A);
	glVertex3fv(B);
	glVertex3fv(C);
	glEnd();
}

void tetra(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[]) {

	glColor3f( 1,0,0 );
	triangle(V1, V2, V3);

	glColor3f(0, 1, 0);
	triangle(V1, V3, V4);

	glColor3f(0, 0, 1);
	triangle(V2, V3, V4);

	glColor3f(1, 1, 0);
	triangle(V1, V2, V4);

}

void Div(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], int n) {

	GLfloat V12[3], V23[3], V31[3], V14[3], V24[3], V34[3];

	if (n > 0) {
		V12[0] = (V1[0] + V2[0]) / 2;
		V12[1] = (V1[1] + V2[1]) / 2;
		V12[2] = (V1[2] + V2[2]) / 2;

		V23[0] = (V2[0] + V3[0]) / 2;
		V23[1] = (V2[1] + V3[1]) / 2;
		V23[2] = (V2[2] + V3[2]) / 2;

		V31[0] = (V3[0] + V1[0]) / 2;
		V31[1] = (V3[1] + V1[1]) / 2;
		V31[2] = (V3[2] + V1[2]) / 2;

		V14[0] = (V1[0] + V4[0]) / 2;
		V14[1] = (V1[1] + V4[1]) / 2;
		V14[2] = (V1[2] + V4[2]) / 2;

		V24[0] = (V2[0] + V4[0]) / 2;
		V24[1] = (V2[1] + V4[1]) / 2;
		V24[2] = (V2[2] + V4[2]) / 2;

		V34[0] = (V3[0] + V4[0]) / 2;
		V34[1] = (V3[1] + V4[1]) / 2;
		V34[2] = (V3[2] + V4[2]) / 2;

		Div(V1, V12, V31, V14, (n-1));    //Left
		Div(V12, V2, V23, V24, (n-1));    //Right
		Div(V31, V23, V3, V34, (n-1));    //Top
		Div(V14, V24, V34, V4, (n-1));    //Mid Top
	}

	else {
		tetra(V1, V2, V3, V4);
	}
}

void Draw() {
	
	GLfloat P[4][3] = {
						{-0.5,-0.5, 0.5},
						{ 0.5,-0.5, 0.5},
						{   0, 0.5, 0.5},
						{   0,-0.1,-0.5}
					  };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Div(P[0], P[1], P[2], P[3], N);
	
	glutSwapBuffers();
}


int main(int c, char* v[]) {

	cout << "Enter the Number of Division: " << endl;
	cin >> N;
	glutInit(&c, v);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	//MyInit();
	glutCreateWindow("Tertrahedron");
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}