#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
float x1,x2,yy1,yy2;

void simpleline();
void DashedLine();
void DottedLine();

float dy,dx,length,x,y,k,xin,yin;
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
  cout<<"Enter the value of yy1:";
  cin>>yy1;
  cout<<"Enter the value of x2:";
  cin>>x2;
  cout<<"Enter the value of yy2:";
  cin>>yy2;
  
  dx=x2-x1;
  dy=yy2-yy1;
  
  if (abs(dx)>abs(dy))
  {
      length  = abs(dx);
  }
  else
      length = abs(dy);
     
  xin =dx/length;
  yin =dy/length;
  
  x=x1;
  y-yy1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  
  for(k=1 ; k<=length; k++)
 
  {

      x=x+xin;
      y=y+yin;
      
      glBegin(GL_POINTS);
      glVertex2i(x, y);
      glEnd();
  }
  glFlush();
  
}
void DashedLine()
{
  cout<<"Enter the value of x1:";
  cin>>x1;
  cout<<"Enter the value of yy1:";
  cin>>yy1;
  cout<<"Enter the value of x2:";
  cin>>x2;
  cout<<"Enter the value of yy2:";
  cin>>yy2;
  
  dx=x2-x1;
  dy=yy2-yy1;
  
  if (abs(dx)>abs(dy))
  {
      length  = abs(dx);
  }
  else
      length = abs(dy);
     
  xin =dx/length;
  yin =dy/length;
  
  x=x1;
  y-yy1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  
  for(int i = 0; i<=length; i++)
  {
     x=x+xin;
     y=y+yin;
     if (i%5 ==0)
     {
     glVertex2i(x, y);
     }
  }
  glEnd();
  glFlush();
}
void DottedLine()
{
   cout<<"Enter the value of x1:";
  cin>>x1;
  cout<<"Enter the value of yy1:";
  cin>>yy1;
  cout<<"Enter the value of x2:";
  cin>>x2;
  cout<<"Enter the value of yy2:";
  cin>>yy2;
  
  dx=x2-x1;
  dy=yy2-yy1;
  
  if (abs(dx)>abs(dy))
  {
      length  = abs(dx);
  }
  else
      length = abs(dy);
     
  xin =dx/length;
  yin =dy/length;
  
  x=x1;
  y-yy1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  
  for(int i = 0; i<=length; i++)
  {
     x=x+xin;
     y=y+yin;
     if (i%2 ==0)
     {
     glVertex2i(x, y);
     }
  }
  glEnd();
  glFlush();
}

void init(void)
{
    gluOrtho2D(0, 499, 0, 499);
}

int main(int argc,char** argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize (500, 500);
     glutInitWindowPosition(400,10);
     glutCreateWindow("DDA Line Algo");
     init();
     glutDisplayFunc(display);
     glutMainLoop();
     
     return 0;
}
