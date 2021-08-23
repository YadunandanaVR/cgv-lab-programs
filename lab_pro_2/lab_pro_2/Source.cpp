#include<glut.h>
#include<iostream>
using namespace std;

GLfloat xa, ya, R;

void Draw() {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.6, 0.4);
	glVertex2f(0.4, 0.8);
	glEnd();

	glLoadIdentity();

	glTranslatef(xa, ya, 0);
	glRotatef(R, 0, 0, 1);
	glTranslatef(-xa, -ya, 0);

	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.6, 0.4);
	glVertex2f(0.4, 0.8);
	glEnd();


	glFlush();
}

int main(int c, char* v[]) {

	char ch;

	cout << "1.Rotate about origin\n2.Rotate about fixed point\n";
	cin >> ch;

	switch(ch){
		case '1':
			cout << "Enter the angle to rotate:" << endl;
			cin >> R;

			xa = 0.0;
			ya = 0.0;
			break;

		case '2':

			cout << "Enter the angle to rotate:" << endl;
			cin >> R;

			cout << "Enter the coordinates:" << endl;
			cin >> xa >> ya;
			break;
	}

	glutInit(&c, v);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Triangle");
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;

	
}