#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2,int col )
 {
  float m;
  m=(y2-y1)/(x2-x1);
  if(m<0)
   m=(-m);
  while(x1<=x2)
  {
  if(m<1)
 { x1=x1+1;
  y1=y1+m;
  putpixel(x1,y1,col);
  }
  else
 {
 x1=x1+(1/m);
  y1=y1+1;
  putpixel(x1,y1,col);
  }
   };
   getch();
 };
void main()
{ int x1,x2,y1,y2,gd=DETECT,gm,col;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  cout<<"Enter points for line : ";
  cin>>x1>>y1>>x2>>y2;
  dda(x1,y1,x2,y2,2);
  getch();

}
