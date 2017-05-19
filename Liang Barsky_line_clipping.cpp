#include <stdio.h>
#include <iostream>
#include <graphics.h>
using namespace std;
int main( )
{
	int x1,y1,x2,y2,Dx,Dy,x,y;
	int xx1,yy1,xx2,yy2;	
	
	float xmin,xmax,ymin,ymax;
	float p1,p2,p3,p4;
	float q1,q2,q3,q4;
	float u1,u2,u3,u4;
	float max,min;


	min=1000;
	max=0;
	
	initwindow( 640 , 480 , "WinBGIm" );
	xmin = 100;
	ymin = 100;
	xmax= 300;
	ymax = 300; //rectangular coordinates
	
	x1 = 50;
	y1 = 90;
	x2 = 400;
	y2 = 150;//line coordinates
	
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
	
	clearviewport();
	rectangle(xmin,ymin,xmax,ymax);

	Dx= x2-x1;
	Dy = y2-y1;	
	p1 = -Dx;
	p2 = Dx;
	p3 = -Dy;
	p4 = Dy;
	cout<<"p1="<<p1<<"p2="<<p2<<"p3="<<p3<<"p4="<<p4;
		

	q1 = x1 - xmin ;
	q2 = xmax - x1 ;
	q3 = y1 - ymin ;
	q4 = ymax - y1 ;

	if(p1==0 || p2==0 || p3==0 || p4==0)
	{
		if(q1<0 || q2<0 || q3 <0 || q4<0)
		{

			cout<<endl<<"The line is completely out of the boundary";
		}
		
		else
		{
			line(x1,y1,x2,y2);//line completly inside the rectangle
		}
	}
	
	else
	{
		if(p1<0 || p2<0 || p3<0 || p4<0)
		{
			cout<<endl<<"The line is from Inside to outside";
		}
		
		else if(p1>0 || p2>0 || p3>0 || p4>0)
		{
			cout<<endl<<"The line is from Outside to inside" ;
		}
		
		u1 = q1/p1;
		u2 = q2/p2;
		u3 = q3/p3;
		u4 = q4/p4;
		
		if(u1>1)
		{
			u1=1;
		}
		if(u1<0)
		{
			u1=0;
		}
		if(u2>1)
		{
			u2=1;
		}	
		if(u2<0)
		{
			u2=0;
		}
		if(u3>1)
		{
			u3=1;
		}
		if(u3<0)
		{
			u3=0;
		}
		if(u4>1)
		{
			u4=1;
		}
		if(u4<0)
		{
			u4=0;
		}

		cout<<"p2="<<p2;
		if(p1<0)
		{
			if(max<(u1))
			{
				max=u1;
				cout<<endl<<"p1<0";
			}
		}
		if(p2<0)
		{
			if(max<(u2))
			{
				max=u2;
				cout<<endl<<"p2<0";
			}
		}
		if(p3<0)
		{
			if(max<(u3))
			{
				max=u3;
				cout<<endl<<"p3<0";
			}
		}
		if(p4<0)
		{
			if(max<(u4))
			{max=u4;
			cout<<endl<<"p4<0";
			}
		}
		
		if(p1>0)
		{
			if(min>u1)
			{
			 min=u1;
			 cout<<endl<<"p1>0";
			}
		}
		
		if(p2>0)
		{
			if(min>u2)
			{
				min=u2;
				cout<<endl<<"p2>0";
			}
		}
		
		if(p3>0)
		{
			if(min>u3)
			{
				min=u3;
				cout<<endl<<"p3>0";
			}
		}
		if(p4>0)
		{
			if(min>u4)
			{
				min=u4;
				cout<<endl<<"p4>0";
			}
		}
		cout<<"p3="<<p3;
		u2 = min;         
		u1 = max;

		if(u1>u2)
		{	
			cout<<"Line is completely outside viewing window";
		}
		else
		{
			xx1 = x1+ Dx*u1;
			yy1 = y1+ Dy*u1;
		
        	xx2  = x1 + Dx*u2;
			yy2  = y1 + Dy*u2;
					  cout<<"xx1 "<< xx1 << "yy1 " <<yy1 <<"xx2 "<<xx2<<"yy2 "<<yy2;
	
			line(xx1,yy1,xx2,yy2);
		}
	}
	while( !kbhit() ); 
	closegraph( );
	return( 0 );
}

