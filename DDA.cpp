#include<graphics.h>
#include<iostream>
using namespace std;
#define round(a)((int)a+.5)
void dda(int x1,int y1,int x2,int y2)
{
     int dx,dy,steps;
     float xincrement,yincrement,x,y;
     
     dx=x2-x1;
     dy=y2-y1;
     if(abs(dx)>abs(dy))
     {
        steps=abs(dx);
     }
     else
     {
      steps=abs(dy);
     }
     
     xincrement=float(dx)/float(steps);
     yincrement=float(dy)/float(steps);
     x=x1;
     y=y1;
     putpixel(round(x),round(y),15);
     
     for(int k=0;k<steps;k++)
     {
             x+=xincrement;
             y+=yincrement;
             putpixel(round(x),round(y),10);
     }
     
}
int main( )
{   int xa,ya,xb,yb;
    initwindow( 640 , 480 , "WinBGIm" );
    while(1){
    if(ismouseclick(WM_LBUTTONDOWN))
     {
        getmouseclick(WM_LBUTTONDOWN,xa,ya);  
        break;
     }       
     }
    while(1){
   if(ismouseclick(WM_RBUTTONDOWN))
     {
        getmouseclick(WM_RBUTTONDOWN,xb,yb); 
        break;
     }   
     }	
    dda (xa, ya,xb,yb);
    getch();
	return( 0 );
}

