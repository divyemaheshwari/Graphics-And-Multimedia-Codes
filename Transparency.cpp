#include <stdio.h>
#include <iostream>
#include <graphics.h>
using namespace std;

void colorize(int lx,int ly,int rx,int ry, int current) //current is the current color in the original image.
{
     int i,j;
     float t=0.5;
     int k[3];
     
     for(i=lx+1;i<rx;i++)
     {//start from the next to the boundary
              
                       for(j=ly+1;j<ry;j++)
                       {// start below the boundary
                       
                                           int previous = getpixel(i,j);
                                           if(previous!=BLACK)
                                           {
                                                k[0]=(int)((1-t)*RED_VALUE(previous)+t*RED_VALUE(current));
                                                k[1]=(int)((1-t)*BLUE_VALUE(previous)+t*BLUE_VALUE(current));
                                                k[2]=(int)((1-t)*GREEN_VALUE(previous)+t*GREEN_VALUE(current));
                                                putpixel(i,j,COLOR(k[0],k[2],k[1]));
                                           }
                                           else{putpixel(i,j,current);}
                       }
     }
}

int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
	int lx,ly,rx,ry,choice;
	loop:
    while(1){
    if(ismouseclick(WM_LBUTTONDOWN))
    {
                                   getmouseclick(WM_LBUTTONDOWN, lx, ly);
    }
    if(ismouseclick(WM_RBUTTONDOWN))
    {
                                   getmouseclick(WM_RBUTTONDOWN, rx, ry);
                                   break;
    }
    }
	rectangle(lx,ly,rx,ry);
	//make two rectabgles.
    cout<<"Enter a value between 0 and 15: ";
	cin>>choice;
	colorize(lx,ly,rx,ry,choice);
    goto loop;
	closegraph( );
	return( 0 );
}
