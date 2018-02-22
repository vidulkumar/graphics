#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{  int gd=DETECT,gm;
   int x1,y1,x2,y2,p,k=0;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   cout<<"\nEnter coordinates of line : ";
  cin>>x1>>y1>>x2>>y2;
  // dx=x2-x1;
   setcolor(2);
   line(x1,y1+1,x2,y2+1);
   putpixel(x1,y1,1);
   p=2*(y2-y1)-(x2-x1);
   do{
   //cout<<x1<<" "<<y1<<" "<<p<<endl;
   if (p<0)
    {
     x1=x1+1;
     putpixel(x1,y1,1);
     p=p+2*(y2-y1);

     }
   else
    {
     x1=x1+1;
     y1=y1+1;
     putpixel(x1,y1,1);
     p=p+2*(y2-y1)-2*(x2-x1);
     }
     //k=k+1 ;
     }while(x1<=x2);
   getch();
}