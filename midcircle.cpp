#include<iostream>
#include<GL/glut.h>
using namespace std;


int x1,Y1,r;

void plot(int x, int Y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+x1,Y+Y1);
	glEnd();
}

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
}


void midcircle()
{
	int x=0;
	int Y=r;
	
	float d=1.25-r;
	plot(x,Y);
	
	while(x<Y){
	if (d<0)
	{
	x=x+1;
	Y=Y;
	d=d+2*x+1;
	}
	else{
	Y=Y-1;
	x=x+1;
	d=d+2*x-2*Y+1;
	}
	
	glColor3f(0.894,0.012,0.012);
	plot(x,Y);
	glColor3f(1.000,0.549,0.000);
	plot(x,-Y);
	glColor3f(1.000,0.929,0.000);
	plot(-x,Y);
	glColor3f(0.000,0.502,0.149);
	plot(-x,-Y);
	glColor3f(0.000,0.302,1.000);
	plot(Y,x);
	glColor3f(0.451,0.161,0.510);
	plot(-Y,x);
	glColor3f(0.894,0.012,0.012);
	plot(Y,-x);
	glColor3f(1.000,0.549,0.000);
	plot(-Y,-x);
	}
}



void myDisplay()
{	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	midcircle();
	glFlush(); }


int main(int argc,char** argv)
{
cout<<"Enter the Co-ordinates of the Center:\n"<< endl;

cout<<"\nX-Coordinate:";
cin>>x1;
cout<<"\nY-Coordinate:";
cin>>Y1;
cout<<"\nEnter Radius:";
cin>>r;


glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,150);
glutCreateWindow("Circle Drawing Algorithm");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();

}
