#include "GL/glut.h"
#include "GL/freeglut.h"

GLfloat angel = 0;
GLfloat angel2 = 0;

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void bodyPersegi()
{
    glBegin(GL_QUADS);
        glVertex3f(-2, 0, 2);
        glVertex3f(2, 0, 2);
        glVertex3f(2, 0, -2);
        glVertex3f(-2, 0, -2);
    glEnd();
}

void Sayap()
{
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0.5);
        glVertex3f(1, 0, -0.5);
        glVertex3f(0, 0, 0);
        glVertex3f(-1, 0, 0.5);
        glVertex3f(-1, 0, -0.5);
    glEnd();
}

void Sayap()
{
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0.5);
        glVertex3f(1, 0, -0.5);
        glVertex3f(0, 0, 0);
        glVertex3f(-1, 0, 0.5);
        glVertex3f(-1, 0, -0.5);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, -2, -10);
    glRotatef(angel2, 0, 1, 0);
    glRotatef(5, 1, 0, 0);
    glColor3d(1,1,1);
    bodyPersegi();
    for(int i = 1; i <= 4; i++){
        glPushMatrix();
    }

    for(int x = -2; x < 4; x+=4)
    {
        for(int z = -2; z < 4; z+=4)
        {
            glPopMatrix();
            glTranslatef(x, 0.2, z);
            glRotatef(angel, 0, 1, 0);
            glColor3d(1,0,0);
            Sayap();
        }
    }


    angel += 10;
    angel2 -= 0.5;
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Kuliah");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
