#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

 void drawgraph(int ox,int oy,int col)
 { //this function plots the base graph according to the origin point provided
   setcolor(col);
   int xx=getmaxx();
   int yy=getmaxy();
   line(0,oy,xx,oy);
   line(ox,0,ox,yy);

 };
 void symp(int ox,int oy,int a,int b,int col)
 {//this function plots the other seven dots symmetricaly to form ellipse
  setcolor(col);
  putpixel(ox+a,oy-b,col);
  putpixel(ox-a,oy-b,col);
  putpixel(ox+a,oy+b,col);
  putpixel(ox-a,oy+b,col);
 };
 void myellipse(int ox,int oy,int a,int b,int col)
 {
   double p;
   int x=0,y=b;
   p=((a*a)*0.25)+b*b-(a*a*b);
   symp(ox,oy,x,y,col);
   while(a*a*(y-(0.5))>b*b*(x+1))
   { delay(50);
    if(p<0)
     {
      p=p+b*b*(2*x+3);
     }
    else
     {
      p=p+b*b*(2*x+3)+a*a*(-2*y+2);
      y--;
     }
     x++;
     symp(ox,oy,x,y,col);
    } ;

    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
   cout<<"region 2  ";
   getch();
   while(y>0)
   {
    delay(50);
    if(p<0)

     {
       p=p+b*b*(2*x+2)+a*a*(-2*y+3);
       x++;
     }
    else
     {
      p=p+a*a*(-2*y+3);
      }
      y--;
     symp(ox,oy,x,y,col);
    };
  };
 void main()
 {
  int gd=DETECT,gm;
  int ox,oy,a,b;
  initgraph(&gd,&gd,"c:\\turboc3\\bgi") ;
  //cout<<"Enter coordinates of origin : ";
 // cin>>ox>>oy;  // comments to be removed if user wants to give graph origin by him/herself
  ox=getmaxx()/2; //   <--|these two lines to be removed if user wants to input graph origin
  oy=getmaxy()/2; //   <--|
  drawgraph(ox,oy,1);
  cout<<"Enter minor and major(a,b) ";
  cin>>a>>b;

  myellipse(ox,oy,a,b,2);
  getch();
 }