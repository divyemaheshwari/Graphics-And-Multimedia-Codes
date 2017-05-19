#include<graphics.h>
void bresenham(int x1,int y1,int x2,int y2)
{
     putpixel(x1,y1,15);
     int dx,dy,p,steps,x,y;
     dx=x2-x1;
     dy=y2-y1;
     
     p=2*dy-dx;
     
     steps=dx;
     
     x=x1;
     y=y1;
     while(steps)
     {
              if(p<0)
              {
                     x=x+1;
                     putpixel(x,y,15);
                     p=p+2*dy;
              }   
              else
              {
                     x=x+1;
                     y=y+1;
                     p=p+2*(dy-dx);
                     putpixel(x,y,15);
              }
              steps=steps-1;
     }
}
main()
{
      initwindow(700,480,"WinBGI");
      bresenham(0,0,550,600);
      getch();
      closegraph();
}
