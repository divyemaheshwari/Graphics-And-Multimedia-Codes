#include <stdio.h>
#include <iostream>

#include <graphics.h>

using namespace std;

int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
//	100 400 200 200 300 200 400 400
  //int x1=100,y1=400,x2=200,y2=200,x3=300,y3=200,x4=400,y4=400;
  int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
   while(1){ 
    while(1)
    {       if(ismouseclick(WM_LBUTTONDOWN))
            {
             cout<<"mouse click ";
             getmouseclick(WM_LBUTTONDOWN,x1,y1);
             break; 
            }
    }
    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,x2,y2);
             break;
             }
    }

    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,x3,y3);

      break;
             }       
    }

    break;
}
    cout<<"outside";

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);  
    int cx=0,cy=0;//curve points


    for(float t=0;t<=1;t=t+.001)
    {
      cx=x1*(1-t)*(1-t)+2*x2*t*(1-t)+x3*t*t;

      cy=y1*(1-t)*(1-t)+2*y2*t*(1-t)+y3*t*t;
      putpixel(cx,cy,15);
    }


    getch();    
	closegraph( );

	return( 0 );
}

