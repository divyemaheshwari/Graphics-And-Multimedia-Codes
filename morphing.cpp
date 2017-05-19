#include<iostream>
#include<graphics.h>
using namespace std;
void animate(int tx1,int ty1,int tx2,int ty2,int tx3,int ty3,int rx1,int ry1,int rx2,int ry2,int rx3,int ry3,int rx4,int ry4)
{
int tcx1,tcy1,tcx2,tcy2,tcx3,tcy3,rcx1,rcy1,rcx2,rcy2,rcx3,rcy3,rcx4,rcy4,midcx,midcy,midx,midy;

		 tcx1=tx1;
 	 	 tcy1=ty1;
 	 	 tcx2=tx2;
 	 	 tcy2=ty2;
 	 	 tcx3=tx3;
 	 	 tcy3=ty3;
 	 	 
 	 	 rcx1=rx1;
 	 	 rcy1=ry1;
		 rcx2=rx2;
 	 	 rcy2=ry2;
 	 	 rcx3=rx3;
 	 	 rcy3=ry3;
 	 	 rcx4=rx4;
 	 	 rcy4=ry4;
 	 	 
 	 	 midx=tx1+0.5*(tx2-tx1);
 	 	 midy=ty1+0.5*(ty2-ty1);
 	 	 
 	 	 midcx=midx;
 	 	 midcy=midy;
 	 	 
 	 	 for(float t=0;t<=1;t+=.01)
 	 	 {
   		  		   cleardevice();
	    		   line(tx1,ty1,tx2,ty2);
				   line(tx2,ty2,tx3,ty3);
				   line(tx3,ty3,tx1,ty1);
				   
				   line(rx1,ry1,rx2,ry2);
				   line(rx2,ry2,rx3,ry3);
				   line(rx3,ry3,rx4,ry4);
				   line(rx4,ry4,rx1,ry1);
				  
				   tcx1=tx1+t*(rx1-tx1);
				   tcy1=ty1+t*(ry1-ty1);
				   
		  		   tcx2=tx2+t*(rx2-tx2);
				   tcy2=ty2+t*(ry2-ty2);
				   
				   tcx3=tx3+t*(rx3-tx3);
				   tcy3=ty3+t*(ry3-ty3);
				   
				   midcx=midx+t*(rx4-midx);
				   midcy=midy+t*(ry4-midy);
				   
				   line(tcx1,tcy1,tcx2,tcy2);
				   line(tcx2,tcy2,tcx3,tcy3);
				   line(tcx3,tcy3,midcx,midcy);
				   line(midcx,midcy,tcx1,tcy1); 
				   delay(10);
		 }

}

main()
{
 	  int tx1,ty1,tx2,ty2,tx3,ty3,rx1,ry1,rx2,ry2,rx3,ry3,rx4,ry4;
	  initwindow(700,450,"WinBGIm");
while(1)
    {       if(ismouseclick(WM_LBUTTONDOWN))
            {
             cout<<"mouse click ";
             getmouseclick(WM_LBUTTONDOWN,tx1,ty1);
             break; 
            }
    }
    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,tx2,ty2);
             break;
             }
    }

    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
             getmouseclick(WM_LBUTTONDOWN,tx3,ty3);

      break;
             }       
    }

    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN,rx1,ry1);

      break;
             }
    }
    while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN,rx2,ry2);

      break;
             }
    }while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN,rx3,ry3);

      break;
             }
    }while(1)
    {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN,rx4,ry4);

      break;
             }
    }
    animate(tx1,ty1,tx2,ty2,tx3,ty3,rx1,ry1,rx2,ry2,rx3,ry3,rx4,ry4);
    
}
