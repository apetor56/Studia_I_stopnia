#include <GL\glut.h>

void init()
{
    glClearColor(0.560784, 0.560784, 0.737255, 0.0);
}

void display(void)
{
   
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 0.0);
  
glRotatef(20,1.0f,0.0f,0.0f); //obr�t lokalnego uk�adu wok� osi x
glRotatef(20,0.0f,1.0f,0.0f); //obr�t lokalnego u�adu wok� osi y

// glEnable(GL_CULL_FACE);
// glCullFace(GL_BACK);
glPolygonMode(GL_BACK, GL_LINE);

glBegin(GL_QUADS);

//�ciana przednia - przeciwnie
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(-0.6f,-0.6f,0.6f);
glVertex3f(0.6f,-0.6f,0.6f);
glVertex3f(0.6f,0.6f,0.6f);
glVertex3f(-0.6f,0.6f,0.6f);

glCullFace(GL_BACK);
//sciana tylnia zgodnie
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(-0.6f,0.6f,-0.6f);
glVertex3f(0.6f,0.6f,-0.6f);
glVertex3f(0.6f,-0.6f,-0.6f);
glVertex3f(-0.6f,-0.6f,-0.6f);

//�ciana lewa
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(-0.6f,-0.6f,-0.6f);
glVertex3f(-0.6f,-0.6f,0.6f);
glVertex3f(-0.6f,0.6f,0.6f);
glVertex3f(-0.6f,0.6f,-0.6f);
//�ciana prawa
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(0.6f,0.6f,-0.6f);
glVertex3f(0.6f,0.6f,0.6f);
glVertex3f(0.6f,-0.6f,0.6f);
glVertex3f(0.6f,-0.6f,-0.6f);
//�ciana dolna
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(-0.6f,-0.6f,0.6f);
glVertex3f(-0.6f,-0.6f,-0.6f);
glVertex3f(0.6f,-0.6f,-0.6f);
glVertex3f(0.6f,-0.6f,0.6f);

glColor3f(0.0f,0.0f,0.0f);
glVertex3f(-0.6f,0.6f,-0.6f);
glVertex3f(-0.6f,0.6f,0.6f);
glVertex3f(0.6f,0.6f,0.6f);
glVertex3f(0.6f,0.6f,-0.6f);

glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInit(&argc, argv);

    glutCreateWindow("Okno OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}