#include <GL\glut.h>
#include <stdio.h>
void drawQuad(){

 glBegin(GL_POLYGON);
  glVertex2f(77.,70.);
  glVertex2f (80.,146.);
  glVertex2f(99.,90.);
  glVertex2f(157.,90.);
  glVertex2f (110.,55.);
  glVertex2f (128.,1.);
  glVertex2f (80.,34.);
  glVertex2f (32.,1.);
  glVertex2f (54.,55.);
  glVertex2f (3.,90.);
  glVertex2f (63.,90.);
  glVertex2f (80.,146.);
 glEnd();
 glFlush();
}
void renderScene(void){

 glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 glRotatef(0,0,0,1);
 glColor3f(1,1,1);//putih
 drawQuad();
 glPopMatrix();

 glFlush();
}
int main(int argc,char **argv){
 glutInit(&argc,argv);
 glutInitWindowPosition(200,200);
 glutInitWindowSize(480,480);
 glutCreateWindow("BINTANG BINTANG");
 gluOrtho2D(-500.,500.,-500.,500.);
 glutDisplayFunc(renderScene);
 glutMainLoop();
}
