#include<glut.h>

void MyInit() {
	glClearColor(255, 255, 255,1);
	glColor3f(1, 0, 0);
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	//glPointSize(5);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.5);
	glVertex2f( 0.5, 0.5);
	glVertex2f( 0.5,-0.5);
	glVertex2f(-0.5,-0.5);
	glEnd();

	glFlush();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);

	glutInitWindowPosition(200,100);
	glutInitWindowSize(1280,720);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Rectangle");

	MyInit();

	glutDisplayFunc(Draw);

	glutMainLoop();
}