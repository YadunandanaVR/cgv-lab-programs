#include<glut.h>
int LE[500], RE[500];

void Intersection(GLint x1, GLint y1, GLint x2, GLint y2) {

	int y, temp;
	GLfloat M, x;

	if (y1 > y2) {
		temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	if (y2 - y1 == 0) {
		M = (x2 - x1);              //slope
	}
	else {
		M = (x2 - x1) / (y2 - y1);     //slope
	}

	x = x1;
	for (y = y1; y < y2; y++) {
		if (x < LE[y]) {
			LE[y] = x;
		}
		if (x > RE[y]) {
			RE[y] = x;
		}

		x = x + M;
	}

}

void Draw() {
	int x, y, i;
	GLint p1[2] = { 125,250 }, p2[2] = { 250,125 }, p3[2] = { 375,250 }, p4[2] = { 250,375 };
	glClear(GL_COLOR_BUFFER_BIT);

	for (i = 0; i < 500; i++) {
		LE[i] = 500;
		RE[i] = 0;
	}

	glBegin(GL_LINE_LOOP);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glEnd();


	
	Intersection(p1[0], p1[1], p2[0], p2[1]);
	Intersection(p2[0], p2[1], p3[0], p3[1]);
	Intersection(p3[0], p3[1], p4[0], p4[1]);
	Intersection(p4[0], p4[1], p1[0], p1[1]);
		
	for (y = 0; y < 500; y++) {
		for ( x = LE[y]; x < RE[y]; x++)
		{
			glColor3f(1,0,0);
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
			glFlush();
		}
	}
	glFlush();
}

void MyInit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}


int main(int c, char* v[]) {
	glutInit(&c, v);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Scan Lines");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}