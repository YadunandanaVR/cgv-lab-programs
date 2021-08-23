#include<glut.h>
#include<math.h>

GLfloat ya = 50, xa = 10;
int yflag = 1, xflag = 1;

void Animate() {
	//ya
	if (ya > -50 && yflag == 1) {
		ya = ya - 0.02;
	}

	if(ya <= -50 && yflag == 1) {
		yflag = 0;
	}

	if (ya < 50 && yflag == 0) {
		ya = ya + 0.02;
	}

	if (ya >= 50 && yflag == 0) {
		yflag = 1;
	}

	//xa
	if (xa > -10 && xflag == 1) {
		xa = xa - 0.02;
	}

	if (xa <= -10 && xflag == 1) {
		xflag = 0;
	}

	if (xa < 10 && xflag == 0) {
		xa = xa + 0.02;
	}

	if (xa >= 10 && xflag == 0) {
		xflag = 1;
	}

	glutPostRedisplay();
}

void Draw() {

	GLfloat x[4], y[4], y1[4], y2[4], y3[4];
	GLdouble  xt[200], yt[200], y1t[200], y2t[200], y3t[200], t;

	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	
	x[0] = 100; x[1] = 200; x[2] = 200; x[3] = 300-xa;

	y[0] = 450; y[1] = 450+ya; y[2] = 450-ya; y[3] = 450;
	y1[0] = 400; y1[1] = 400+ya; y1[2] = 400-ya; y1[3] = 400;
	
	y2[0] = 350; y2[1] = 350+ya; y2[2] = 350-ya; y2[3] = 350;
	y3[0] = 300; y3[1] = 300+ya; y3[2] = 300-ya; y3[3] = 300;

	for (i = 0, t = 0; t <= 1; i++, t = t+0.005) {

		xt[i] = pow(1- t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
		yt[i] = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
		y1t[i] = pow(1 - t, 3) * y1[0] + 3 * t * pow(1 - t, 2) * y1[1] + 3 * pow(t, 2) * (1 - t) * y1[2] + pow(t, 3) * y1[3];		
		
		y2t[i] = pow(1 - t, 3) * y2[0] + 3 * t * pow(1 - t, 2) * y2[1] + 3 * pow(t, 2) * (1 - t) * y2[2] + pow(t, 3) * y2[3];
		y3t[i] = pow(1 - t, 3) * y3[0] + 3 * t * pow(1 - t, 2) * y3[1] + 3 * pow(t, 2) * (1 - t) * y3[2] + pow(t, 3) * y3[3];
	}

	glColor3f(0.9, 0.5, 0.2);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 200; i++) {
		glVertex2d(xt[i], yt[i]);
		glVertex2d(xt[i], y1t[i]);
	}
	glEnd();	
	
	glColor3f(1, 1, 1);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 200; i++) {
		glVertex2d(xt[i], y1t[i]);
		glVertex2d(xt[i], y2t[i]);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 200; i++) {
		glVertex2d(xt[i], y2t[i]);
		glVertex2d(xt[i], y3t[i]);
	}
	glEnd();

	glColor3f(1, 1, 1);
	glRecti(90, 50, 100, 470);

	glFlush();
}

void MyInit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void menu(int id)
{
	switch (id)
	{
	case 1:glutIdleFunc(Animate);
		break;

	case 2:glutIdleFunc(NULL);
		break;
	}
	glutPostRedisplay();
}


int main(int c, char *v[]) {
	glutInit(&c, v);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Animated Flag");
	MyInit();
	glutDisplayFunc(Draw);
	glutCreateMenu(menu);
	glutAddMenuEntry("Draw and animate", 1);
	glutAddMenuEntry("Stop animation", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}