#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
    int xc,yc,xr,yr,r,p,x,y;
    while(1)
    {
            while(1)
            {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                     getmouseclick(WM_LBUTTONDOWN,xc,yc);
                     break;
                    }
            } 
            while(1)
            {
                    if(ismouseclick(WM_RBUTTONDOWN))
                    {
                     getmouseclick(WM_RBUTTONDOWN,xr,yr);
                     break;
                    }
            }      
     break;
    }
    r=sqrt((xr-xc)*(xr-xc)+(yr-yc)*(yr-yc));
    cout<<r;
    putpixel(xc,yc+r,15);
    p=1-r;
    x=0;
    y=r;
    
    do
    {
          if(p<0)
          {
                 x=x+1;
                 p=p + 2*x +3;
          }
          else
          {
                 x=x+1;
                 y=y-1;
                 p=p + 2*(x-y) +1;
          }
          putpixel(x+xc,y+yc,15);
          putpixel(-x+xc,y+yc,15);
          putpixel(x+xc,-y+yc,15);
          putpixel(-x+xc,-y+yc,15);
          
          putpixel(y+xc,x+yc,15);
          putpixel(-y+xc,x+yc,15);
          putpixel(y+xc,-x+yc,15);
          putpixel(-y+xc,-x+yc,15);        
        }while(x<=y);   
getch();
closegraph();
}
