#include "GL/glut.h"
#include "GL/freeglut.h"

GLfloat angel = 0;
bool putar = true;

void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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

void Persegi()
{
    glLoadIdentity();
    glTranslatef(0, 0, -30);
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
        glVertex3f(-3, 3, 0);
        glVertex3f(3, 3, 0);
        glVertex3f(3, -3, 0);
        glVertex3f(-3, -3, 0);
    glEnd();
}

void SegitigaKanan()
{
    glLoadIdentity();
    glTranslatef(2, 0, -20);
    glRotatef(angel, 0, 0, 1);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(4, 0, 0);
        glVertex3f(4, 2, 0);
    glEnd();
}

void SegitigaKiri()
{
    glLoadIdentity();
    glTranslatef(-2, 0, -20);
    glRotatef(180, 0, 1, 0);
    glRotatef(angel, 0, 0, 1);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(4, 0, 0);
        glVertex3f(4, 2, 0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    Persegi();
    SegitigaKanan();
    SegitigaKiri();
    if(putar == true){
        angel++;
    } else{
        angel--;
    }

    if(angel == 45){
        putar = false;
    }else if(angel == -45){
        putar = true;
    }
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
