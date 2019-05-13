#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
GLfloat tri[3][3]={{200,200,0},{400,200,0},{300,400,0}};
GLfloat arb_x=200;
GLfloat arb_y=200;
GLfloat rot_angle;
void drawtri()
{
glBegin(GL_LINE_LOOP);
glVertex3fv(tri[0]);
glVertex3fv(tri[1]);
glVertex3fv(tri[2]);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(arb_x,arb_y,0.0);
glRotatef(rot_angle,0.0,0.0,1.0);
glTranslatef(-arb_x,-arb_y,0.0);
glColor3f(0,1,0);
drawtri();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glColor3f(1,0,0);
drawtri();
glFlush();
}
void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}
int main(int argc, char **argv)
{
printf("\n enter the rotation angle\n");
scanf("%f",&rot_angle);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("triangle rotation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

