#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

void displayFunction();
void initialize();

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("openGL Learning");
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    initialize();

    glutDisplayFunc(displayFunction);
    glutMainLoop();
}

void mkDrawCircle() {
    double theta;
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            theta = i * M_PI / 180;
            glVertex2f(300 + 200 * cos(theta),300 + 1000 * sin(theta));
        }
    glEnd();
}

void displayFunction() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    mkDrawCircle();
    glFlush();
}

void initialize() {
    glClearColor(0.5, 1.0, 1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1280.0,720.0,0.0);
}