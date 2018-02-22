 #include<iostream.h>
 #include<conio.h>
 #include<graphics.h>

 void drawgraph(int ox,int oy,int col)
 { //this function plots the base graph according to the origin point provided
   setcolor(col);
   int xx=getmaxx();
   int yy=getmaxy();
   line(0,oy,xx,oy);
   line(ox,0,ox,yy);

 };
 void symp(int ox,int oy,int h,int k,int x,int y,int col)
 {//this function plots the other seven dots symmetricaly to form circle
  setcolor(col);
  putpixel(ox+h+x,oy-(k-y),col);
  putpixel(ox+h-x,oy-(k-y),col);
  putpixel(ox+h-x,oy-(k+y),col);
  putpixel(ox+h+y,oy-(k+x),col);
  putpixel(ox+h+y,oy-(k-x),col);
  putpixel(ox+h-y,oy-(k+x),col);
  putpixel(ox+h-y,oy-(k-x),col);
 }
 void mycircle(int ox,int oy,int h,int k,int rad,int col)
 { //this function applys midpoint circle algorithm
   setcolor(col);
   int p;
   int x=0,y;
   y=rad;
   putpixel(ox+h+0,oy-(k+rad),col);
   p=1-rad;
   do
   {

   if(p<0)
    { x=x+1;
     putpixel(ox+h+x,oy-(k+y),col);
     symp(ox,oy,h,k,x,y,col);
     p=p+2*x+3;}
   else
     {
      x=x+1;
      y=y-1;
      putpixel(ox+h+x,oy-(k+y),col);
      symp(ox,oy,h,k,x,y,col);
      p=p+2*(x-y)+5;
     }
     }while(x<=y);

 };
 void main()
 {
  int gd=DETECT,gm;
  int ox,oy,h,k,rad;
  initgraph(&gd,&gd,"c:\\turboc3\\bgi") ;
  //cout<<"Enter coordinates of origin : ";
 // cin>>ox>>oy;  // comments to be removed if user wants to give graph origin by him/herself
  ox=getmaxx()/2; //   <--|these two lines to be removed if user wants to input graph origin
  oy=getmaxy()/2; //   <--|
  drawgraph(ox,oy,1);
  cout<<"Enter cordinates of center of circle : ";
  cin>>h>>k;
  cout<<"Enter radius of circle : ";
  cin>>rad;
  mycircle(ox,oy,h,k,rad,2);
  getch();
 }