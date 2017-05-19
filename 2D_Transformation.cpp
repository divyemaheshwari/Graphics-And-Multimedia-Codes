#include <stdio.h>
#include <iostream>
#include<math.h>
#include <graphics.h>
using namespace std;
void figure(int x1,int y1,int x2,int y2,int x3,int y3)
{
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x1,y1); 
}

main()
{
 initwindow(400,680,"WinBGI");
 int x1,y1,x2,y2,x3,y3,tx,ty,theta,xr2,yr2,xr3,yr3,sx,sy,s_x1,s_y1,s_x2,s_y2,s_x3,s_y3;
 float ang;
 while(1)
    {
            while(1)
            {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
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
    figure(x1,y1,x2,y2,x3,y3);
    
    cout<<"Enter the translation factor x then y";
    cin>>tx>>ty;
    figure(x1+tx,y1+ty,x2+tx,y2+ty,x3+tx,y3+ty);
    
    cout<<"enter the rotation factor (theta)";
    cin>>theta;
    ang=(M_PI/180)*theta;
    cout<<ang;
    
    xr2=(x1+((x2-x1)*cos(ang))-((y2-y1)*sin(ang)));
    yr2=(y1+((x2-x1)*sin(ang))+((y2-y1)*cos(ang)));
    
    xr3=(x1+((x3-x1)*cos(ang))-((y3-y1)*sin(ang)));
    yr3=(y1+((x3-x1)*sin(ang))+((y3-y1)*cos(ang)));
    	    
    figure(x1,y1,xr2,yr2,xr3,yr3); 
    
    
    cout<<"enter the scaling factor x then y";
    cin>>sx>>sy;
    s_x1=(x1*sx+x1*(1-sx));
    s_y1=(y1*sy+y1*(1-sy));
    
    s_x2=(x2*sx+x1*(1-sx));
    s_y2=(y2*sy+y1*(1-sy));
    
    s_x3=(x3*sx+x1*(1-sx));
    s_y3=(y3*sy+y1*(1-sy));    
    
    figure(s_x1,s_y1,s_x2,s_y2,s_x3,s_y3);
 	getch();
 	closegraph();
}
