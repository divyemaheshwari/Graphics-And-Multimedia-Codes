#include<iostream>
#include<graphics.h>
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
      int b;
      int x=10,y=20,bxselected,byselected,blue_selected,rgbxselected,rgbyselected,fill_color;
      initwindow(640,400,"WinBGI");
      for (int i=0;i<=255;i++)
      {
          b=COLOR(0,0,i);
          putpixel(x,y,b);
          putpixel(x+1,y,b);
          putpixel(x+2,y,b);
          putpixel(x+3,y,b);
          putpixel(x+4,y,b);
          putpixel(x+5,y,b);
          putpixel(x+6,y,b);
          putpixel(x+7,y,b);
          
          y=y+1;
      }
      x=20;
      y=20;
      for(int r=0;r<=255;r++)
      {    
           for(int g=0;g<=255;g++)
           {
                   int rgband=COLOR(r,g,0);
                   putpixel(x,y,rgband);
                   y=y+1;
           }
           y=20;
           x=x+1;
      }
      
 loop:     
      while(1)
      {
              if(ismouseclick(WM_LBUTTONDOWN))
              {
                getmouseclick(WM_LBUTTONDOWN,bxselected,byselected);
                break;
              } 
      }
      
      cout<<bxselected<<"\n"<<byselected;
      
      blue_selected=BLUE_VALUE(getpixel(bxselected,byselected));
      
      cleardevice();
      x=10;
      y=20;
      for (int i=0;i<=255;i++)
      {
          b=COLOR(0,0,i);
          putpixel(x,y,b);
          putpixel(x+1,y,b);
          putpixel(x+2,y,b);
          putpixel(x+3,y,b);
          putpixel(x+4,y,b);
          putpixel(x+5,y,b);
          putpixel(x+6,y,b);
          putpixel(x+7,y,b);
          
          y=y+1;
      }
      x=20;
      y=20;
      for(int r=0;r<=255;r++)
      {    
           for(int g=0;g<=255;g++)
           {
                   int rgband=COLOR(r,g,blue_selected);
                   putpixel(x,y,rgband);
                   y=y+1;
           }
           y=20;
           x=x+1;
      }
      circle(400,90,20);
      
      while(1)
      {
              if(ismouseclick(WM_LBUTTONDOWN))
              {
                getmouseclick(WM_LBUTTONDOWN,rgbxselected,rgbyselected);
                break;
              } 
      }
      fill_color=getpixel(rgbxselected,rgbyselected);
      boundaryfill(400,90,fill_color,15);
      goto loop;
      getch();
}
