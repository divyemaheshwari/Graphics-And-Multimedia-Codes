#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

main()
{
 initwindow(400,500,"WInBGI");
 int xp0,yp0,xp1,yp1,xp2,yp2,xp3,yp3;
 int cx=0,cy=0;
 
    while(1){ 
    while(1)
    {       if(ismouseclick(WM_LBUTTONDOWN))
            {
             cout<<"mouse click ";
             getmouseclick(WM_LBUTTONDOWN,xp0,yp0);
             break; 
            }
    }
    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,xp1,yp1);
             break;
             }
    }

    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,xp2,yp2);

      break;
             }       
    }

    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN,xp3,yp3);

      break;
             }
    }
    break;
}
 
 line(xp0,yp0,xp1,yp1);
 line(xp1,yp1,xp2,yp2);
 line(xp2,yp2,xp3,yp3);
 
 for(float t=0;t<=1;t=t+.01)
 {
  cx=int( ((1-t)*(1-t)*(1-t))*xp0 + 3*t*xp1*((1-t)*(1-t)) + 3*(t*t)*(1-t)*xp2 + (t*t*t)*xp3);
  cy=int( ((1-t)*(1-t)*(1-t))*yp0 + 3*t*yp1*((1-t)*(1-t)) + 3*(t*t)*(1-t)*yp2 + (t*t*t)*yp3);
  putpixel(cx,cy,15);
      
 } 
 getch();
}
