#include <GL/glut.h>

void init() {
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.7f, -0.3f);
    glEnd();

    glPointSize(11.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINES);
        glVertex2f(-0.8f, -0.5f);
        glVertex2f(-0.8f, 0.3f);
    glEnd();

    glBegin(GL_POINTS);
        glVertex2f(-0.8f, -0.5f);
        glVertex2f(-0.8f, 0.3f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]) {
    //glutInitWindowPosition(200,0);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGB);
    glutInit(&argc, argv);

    glutCreateWindow("Okno OpenGL");

    init();
    glutDisplayFunc(display);


    glutMainLoop();
    return 0;
}