#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
float x1,x2,y1,y2;

void simpleline();
void DashedLine();
void DottedLine();

float dy,dx,x,y,e;
int i;
void display()
{
    cout<<"\nSimple Line\n";
    simpleline();
    cout<<"\nDashed Line\n";
    DashedLine();
    cout<<"\nDotted Line\n";
    DottedLine();
}
void simpleline()
{
    cout<<"Enter the value of x1:";
    cin>>x1;
    cout<<"Enter the value of y1:";
    cin>>y1;
    cout<<"Enter the value of x2:";
    cin>>x2;
    cout<<"Enter the value of y2:";
    cin>>y2;
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
e=2*dy-dx;
glBegin(GL_POINTS);
glColor3f(1.0,0.0,0.0);
glVertex2i(x,y);
for(i=1;i<=dx;i++)
{
   if(e>=0)
   {
      y=y+1;
      e=e-2*dx;
      }
     else
     {
        x=x+1;
        e=e+2*dy;
        }
        glVertex2i(x,y);
}
glEnd();
glFlush();
}
void DashedLine()
{
   cout<<"Enter the value of x1:";
    cin>>x1;
    cout<<"Enter the value of y1:";
    cin>>y1;
    cout<<"Enter the value of x2:";
    cin>>x2;
    cout<<"Enter the value of y2:";
    cin>>y2;
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
e=2*dy-dx;
glBegin(GL_POINTS);
glColor3f(0.0,1.0,0.0);
glVertex2i(x,y);
for(i=1;i<=dx;i++)
{
   if(e>=0)
   {
      y=y+1;
      e=e-2*dx;
      }
     else
     {
        x=x+1;
        e=e+2*dy;
        }
        if(i % 5==0)
    {
        glVertex2i(x,y);
        }
}
glEnd();
glFlush();
}

void DottedLine()
{
cout<<"Enter the value of x1:";
    cin>>x1;
    cout<<"Enter the value of y1:";
    cin>>y1;
    cout<<"Enter the value of x2:";
    cin>>x2;
    cout<<"Enter the value of y2:";
    cin>>y2;
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
e=2*dy-dx;
glBegin(GL_POINTS);
glColor3f(0.0,0.0,1.0);
glVertex2i(x,y);
for(i=1;i<=dx;i++)
{
   if(e>=0)
   {
      y=y+1;
      e=e-2*dx;
      }
     else
     {
        x=x+1;
        e=e+2*dy;
        }
        if(i % 2==0)
    {
        glVertex2i(x,y);
        }
}

glEnd();
glFlush();
}
void init(void)
{
    gluOrtho2D(0,499,0,499);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenhams Algo");
    init();	
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
