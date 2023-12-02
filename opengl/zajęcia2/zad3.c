#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    float r = 0.3f;
    float x = 0.0f, y = 0.0f;
    int n = 40;
    double deg = 2 * 3.1415 / n;

    glRotatef(30.0f, 1.0f, 0.3f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
        for(int i = 0; i < n; i++) {
            glVertex3f(0, 0, 0);
            y = sin(deg * i) * r;
            x = cos(deg * i) * r;
            glVertex3f(x, 0, y);
        }

        glVertex3f(0, 0, 0);
        glVertex3f(r, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        for(int i = 0; i < n; i++) {
            glVertex3f(0, 0.6, 0);
            y = sin(deg * i) * r;
            x = cos(deg * i) * r;
            glVertex3f(x, 0.6, y);
        }

        glVertex3f(0, 0.6f, 0);
        glVertex3f(r, 0.6f, 0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i < n; i++) {
            y = sin(deg * i) * r;
            x = cos(deg * i) * r;
            glVertex3f(x, 0.0, y);
            glVertex3f(x, 0.6, y);
        }
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