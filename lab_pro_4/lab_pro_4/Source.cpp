#include<glut.h>

GLfloat Cx=0, Cy=0, Cz=3;
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {
	glBegin(GL_POLYGON);
	glVertex3fv(A);
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

void Draw() {

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

	glLoadIdentity();
	gluLookAt(Cx, Cy, Cz, 0, 0, 0, 0, 1, 0);

	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
	theta[axis] += 30.0;
	if (theta[axis] > 360.0)
		theta[axis] = 0;
	Draw();
}

void MyInit() {
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 10);
	glMatrixMode(GL_MODELVIEW);
}

void Key(unsigned char ch, int x, int y) {
	switch (ch) {
	case 'd':
		Cx = Cx - 0.5;
		break;

	case 'a':
		Cx = Cx + 0.5;
		break;

	case 's':
		Cy = Cy - 0.5;
		break;

	case 'w':
		Cy = Cy + 0.54;
		break;

	case 'e':
		Cz = Cz - 0.5;
		break;

	case 'q':
		Cz = Cz + 0.5;
		break;
	}

	glutPostRedisplay();
}

int main(int c, char* v[]) {
	glutInit(&c, v);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("lab_pro_4");
	MyInit();
	glutDisplayFunc(Draw);
	glutMouseFunc(mouse);
	glutKeyboardFunc(Key);
	glutMainLoop();
	
}