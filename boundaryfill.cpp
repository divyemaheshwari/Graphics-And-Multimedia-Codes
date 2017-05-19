#include<graphics.h>
#include<iostream>
using namespace std;
void boundaryfill(int x,int y,int fillcolor,int boundarycolor)
{
     int a=getpixel(x,y);
     cout<<a;
     if((a!=fillcolor)&&(a!=boundarycolor))
     {
      putpixel(x,y,fillcolor);
      boundaryfill(x+1,y,fillcolor,boundarycolor);
      boundaryfill(x-1,y,fillcolor,boundarycolor);
      boundaryfill(x,y+1,fillcolor,boundarycolor);
      boundaryfill(x,y-1,fillcolor,boundarycolor);
     }
}
main()
{
      initwindow(500,500,"WinBGI");
      circle(50,40,10);
      line(0,0,90,90);
      int x,y;
      while(1)
      {
       if(ismouseclick(WM_LBUTTONDOWN))
       {
        getmouseclick(WM_LBUTTONDOWN,x,y);
        break;
       }
      }
      boundaryfill(x,y,12,15);
      
      getch();
}
