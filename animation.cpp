#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;
void circle1(int xc,int yc,int r)
{

            int x0=0;
            int y0=r;
            int p0=1-r; int pk=p0;
            int x=x0;int y=y0;
            int x1=x+xc;int y1=y+yc;
            putpixel(x1,y1,BLUE);
            //putpixel(x1,y1,BLUE);
            putpixel(y+xc,x+yc,BLUE);
            putpixel(x1,(-y+yc),BLUE);
            putpixel(y+xc,(-x+yc),BLUE);
            putpixel((-x+xc),(-y+yc),BLUE);
            putpixel((-y+xc),(-x+yc),BLUE);
            putpixel((-x+xc),y1,BLUE);
            putpixel((-y+xc),x+yc,BLUE);
            while(x<y){
            if(pk<0){
            x=x+1;
            y=y;
            pk=pk+2*x+1;
            x1=x+xc; y1=y+yc;
            putpixel(x1,y1,BLUE);
            putpixel(y+xc,x+yc,BLUE);
            putpixel(x1,(-y+yc),BLUE);
            putpixel(y+xc,(-x+yc),BLUE);
            putpixel((-x+xc),(-y+yc),BLUE);
            putpixel((-y+xc),(-x+yc),BLUE);
            putpixel((-x+xc),y1,BLUE);
            putpixel((-y+xc),x+yc,BLUE);
             }
             
            else{

                x=x+1;
                y=y-1;
                pk=pk+2*x+1-2*y;
                x1=x+xc; y1=y+yc;
                putpixel(x1,y1,BLUE);
                putpixel(y+xc,x+yc,BLUE);
                putpixel(x1,(-y+yc),BLUE);
                putpixel(y+xc,(-x+yc),BLUE);
                putpixel((-x+xc),(-y+yc),BLUE);
                putpixel((-y+xc),(-x+yc),BLUE);
                putpixel((-x+xc),y1,BLUE);
                putpixel((-y+xc),x+yc,BLUE);
                }
             }//while

}            

void draw_hill(int x1,int x2,int x3,int y1,int y2){
setcolor(RED);
line(x1,y1,x1+60,y2);
line(x1+60,y2,x2,y1);
line(x1,y1,x2,y1);
line(x2,y1,x2+60,y2);
line(x2+60,y2,x3,y1);
line(x2,y1,x3,y1);
setcolor(RED);  
setfillstyle(SOLID_FILL,RED);
floodfill(x1+20,y1-20,RED);

floodfill(x2+20,y1-20,RED);


}
void decasteCubic(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd){

for(float t=0;t<=1;t=t+0.001)
{
	float xx=(1-t)*(1-t)*(1-t)*xa+ 3*(1-t)*(1-t)*t*xb+3*(1-t)*t*t*xc+ t*t*t*xd;
	int fx=(int)(xx);
	float yy=(1-t)*(1-t)*(1-t)*ya+ 3*(1-t)*(1-t)*t*yb+3*(1-t)*t*t*yc+ t*t*t*yd;
	int fy=(int)(yy);
	putpixel(fx,fy,WHITE);
}
}

void decasteQuadraticSun(int xa,int ya,int xb,int yb,int xc,int yc)
{
	int chance=0;
	int xaa=xa;
	int yaa=ya;
	int xbb=xa+40;
	int ybb=ya-6;
	int xcc=xa+94;
	int ycc=ya+12;
	int xdd=xa+120;
	int ydd=ya-2;
	
	for(float t=0.3;t<=1;t=t+0.01)
	{
		draw_hill(xa+160,xa+320,xa+430,ya,yb+190);
		float xx=(1-t)*(1-t)*xa+ 2*(1-t)*t*xb + t*t*xc;
		int fx=(int)(xx);
		float yy=(1-t)*(1-t)*ya+ 2*(1-t)*t*yb + t*t*yc;
		int fy=(int)(yy);
		// Draw blue water body
		setcolor(BLUE);
		rectangle(0,yaa+2,640,480);
		setcolor(11);
		setfillstyle(SOLID_FILL,11);
		floodfill(100,yaa+80,BLUE);
		//water body drawn
		circle1(fx,fy,30);
		setcolor(RED);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(fx,fy,BLUE);
		//sun drawn
		
		//now drawng ripples
		
		if(chance%2==0)
		{
			for(int p=3;p<640;p+=120)
			{
			decasteCubic(xaa+p,yaa,xbb+p,ybb,xcc+p,ycc,xdd+p,ydd);
			decasteCubic(xaa+70+p,yaa+20,xbb+70+p,ybb+20,xcc+70+p,ycc+20,xdd+70+p,ydd+20);
			decasteCubic(xaa+140+p,yaa+80,xbb+120+p,ybb+80,xcc+120+p,ycc+80,xdd+120+p,ydd+80);
			decasteCubic(xaa+p,yaa+p,xbb+p,ybb+p,xcc+p,ycc+p,xdd+p,ydd+p);
			decasteCubic(xaa+70+p,yaa+20+p,xbb+70+p,ybb+20+p,xcc+70+p,ycc+20+p,xdd+70+p,ydd+20+p);
			decasteCubic(xaa+140+p,yaa+80+p,xbb+120+p,ybb+80+p,xcc+120+p,ycc+80+p,xdd+120+p,ydd+80+p);
			}
		}
	 	else
			{
//Used to invert the points to get the moving ripple effect
			for(int p=3;p<640;p+=120){
			decasteCubic(xaa+p,yaa,xcc+p,ycc,xbb+p,ybb,xdd+p,ydd);
			decasteCubic(xaa+70+p,yaa+20,xcc+70+p,ycc+20,xbb+70+p,ybb+20,xdd+70+p,ydd+20);
			decasteCubic(xaa+140+p,yaa+80,xcc+120+p,ycc+80,xbb+120+p,ybb+80,xdd+120+p,ydd+80);
			decasteCubic(xaa+p,yaa+p,xcc+p,ycc+p,xbb+p,ybb+p,xdd+p,ydd+p);
			decasteCubic(xaa+70+p,yaa+20+p,xcc+70+p,ycc+20+p,xbb+70+p,ybb+20+p,xdd+70+p,ydd+20+p);
			decasteCubic(xaa+140+p,yaa+80+p,xcc+120+p,ycc+80+p,xbb+120+p,ybb+80+p,xdd+120+p,ydd+80+p);
			}
         }
		 chance=chance+1;
		 delay(3);
		 cleardevice();
		 }

}




void animate(int xa,int ya,int xb,int yb,int xc,int yc)
{
 	 			 while(1)
				 {          
				 			decasteQuadraticSun(xa,ya,xb,yb,xc,yc);
					}
}


int main( )
{
initwindow( 640 , 480 , "WinBGIm" );

outstreamxy( 0 , 15 ); 


int count=0;
int xa,xb,xc,xd,ya,yb,yc,yd;int stat=2;  // stat==1 cubic beizel curve, stat=2 is quadratic curve
while(1){
int x,y; 
if(ismouseclick(WM_LBUTTONDOWN) && (stat==1))
{
	getmouseclick(WM_LBUTTONDOWN, x, y);
	if(count==0)
	{
	 			xa=x;
	 	  		ya=y;
	 			count=1; 
	 }
else if(count==1)
	 {
		xb=x;
		yb=y;
		count=2; 
		}
		
else if(count==2)
{
	 xc=x;			
	 yc=y;
	 count=3; 
  }
else if(count>=3){

xd=x;
yd=y;
count=4; 

}
if(count>=4){

line(xa,ya,xb,yb); line(xb,yb,xc,yc); line(xc,yc,xd,yd); 
decasteCubic(xa,ya,xb,yb,xc,yc,xd,yd);
}

}
else if(ismouseclick(WM_LBUTTONDOWN) && (stat==2))
{
getmouseclick(WM_LBUTTONDOWN, x, y);
if(count==0){
xa=x;
ya=y;
count=1; 

}
else if(count==1){
xb=x;
yb=y;
count=2; 


}
else if(count>=2){
xc=x;
yc=y;
count=3; 



}

if(count>=3){

line(xa,ya,xb,yb); line(xb,yb,xc,yc); 
animate(xa,ya,xb,yb,xc,yc);
}

}              
}


while( !kbhit() ); 



closegraph( );

return( 0 );
}

