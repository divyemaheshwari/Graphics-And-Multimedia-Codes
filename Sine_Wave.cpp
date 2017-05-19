#include <conio.h>
#include <math.h>
#include <graphics.h>
 
int main() {
	int angle = 0;
    double x, y;
 	initwindow( 640 , 480 , "WinBGIm" );
 	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
 	for(x = 0; x < getmaxx(); x+=3) 
	 {
      y = 50*sin(angle*3.141/180);
      y = getmaxy()/2 - y;
  	  putpixel(x, y, 15);
  	  delay(100);
	  angle+=5;
 	  }
 getch();
 
 closegraph();
 
 return 0;
}
