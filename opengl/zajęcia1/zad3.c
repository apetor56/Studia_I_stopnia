#include <GL/glut.h>

void init() {
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f( 0.0, 0.0, 0.0);
        glVertex3f( 0.2, 0.8, 0.0);
        glVertex3f( 0.3, 0.75, 0.0);

        glVertex3f( 0.0, 0.0, 0.0);
        glVertex3f( 0.3, 0.75, 0.0);
        glVertex3f( 0.6, 0.9, 0.0);

        glVertex3f( 0.0, 0.0, 0.0);
        glVertex3f( 0.6, 0.9, 0.0);
        glVertex3f( 0.95, 0.7, 0.0);
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