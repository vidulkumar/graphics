#include<iostream>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
using namespace std;
struct obj{
        int mt[50][2];
        int adj[50][50];
        int points;
        };
 void display(obj test)
 {   cout<<"\nnumber of vertices "<<test.points;
     cout<<"\n matrix";
     for(int i=0;i<test.points;i++)
     {
         cout<<test.mt[i][0]<<" "<<test.mt[i][1]<<"\n";

     }
     cout<<"\nadjacency matrix ";
     for(int i=0;i<test.points;i++)
     {   cout<<endl;
         for(int j=0;j<test.points;j++)
            cout<<test.adj[i][j]<<" ";
     }

 }
void draw(obj obj1)//to draw objects
        {
             for(int i=0;i<obj1.points;i++)
                { //setcolor(++col);
                  //cout<<i;
                    for(int j=i;j<obj1.points;j++)
                 if(obj1.adj[i][j]==1)
                     {line(obj1.mt[i][0],GetSystemMetrics(SM_CYFULLSCREEN)-obj1.mt[i][1],obj1.mt[j][0],GetSystemMetrics(SM_CYFULLSCREEN)-obj1.mt[j][1]);
                      //cout<<obj1.mt[i][0]<<" "<<obj1.mt[i][1]<<"and"<<obj1.mt[j][0]<<" "<<obj1.mt[j][1];                     }
                }}
        };
obj translate(obj obj1,int numx,int numy)
{  obj tlt;
    tlt.points=obj1.points;
     for (int i=0;i<obj1.points;i++)
     {
        tlt.mt[i][0]=obj1.mt[i][0];
        tlt.mt[i][1]=obj1.mt[i][1];
        for(int j=0;j<obj1.points;j++)
          tlt.adj[i][j]=obj1.adj[i][j];
      }
    for(int j=0;j<obj1.points;j++)
    {
       tlt.mt[j][0]=tlt.mt[j][0]+numx;
       tlt.mt[j][1]=tlt.mt[j][1]+numy;

    }
    return tlt;
}

obj scale(obj obj1,double s,int x,int y)
       {   obj scaled;
           scaled.points=obj1.points;
           for(int i=0;i<obj1.points;i++ )
           {
               scaled.mt[i][0]=s*(obj1.mt[i][0]-x)+x;
               scaled.mt[i][1]=s*(obj1.mt[i][1]-y)+y;
           }
           for (int i=0;i<obj1.points;i++)
           {
             for(int j=0;j<obj1.points;j++)
              scaled.adj[i][j]=obj1.adj[i][j];
            }
            return scaled;
       }

void drawscene(int mx,int my)
        {  setcolor(2);
           line(0,my/3+50,mx,my/3+50);
           setcolor(8);
           line(mx/2-100,my/3+50,mx/2-400,my+50);
           line(mx/2+100,my/3+50,mx/2+400,my+50);
        }
void drawlight(int mx,int my,int col)
        { setcolor(14);
          setfillstyle(3,col);
          circle(870,my-580,15);
          circle(870,my-545,15);

          circle(870,my-510,15);
          if(col==4)
            floodfill(870,my-580,15);
          else if(col==6)
            floodfill(870,my-545,15);
          else
            floodfill(870,my-510,15);

          rectangle(850,my-600,890,my-490);
          rectangle(860,my-490,880,my-350);
          setcolor(15);
        }

int main()
{   int mx=GetSystemMetrics(SM_CXFULLSCREEN)-3;
    int my=GetSystemMetrics(SM_CYFULLSCREEN);
     initwindow(mx,my,"x");
     obj test;
     int vertices=4;
    int mat[4][2]={500,100,
                   800,100,
                   700,220,
                   600,220};
       test.points=vertices;
    int adj[4][4]={0,1,0,1,
                   0,0,1,0,
                   0,0,0,1,
                   0,0,0,0};
    for (int i=0;i<vertices;i++)
    {
        test.mt[i][0]=mat[i][0];
        test.mt[i][1]=mat[i][1];
        for(int j=0;j<vertices;j++)
          test.adj[i][j]=adj[i][j];
    }
     for(int k=0;k<440;k++)
     {
      drawscene(mx,my);
      drawlight(mx,my,10);
     //setcolor(k%14);
     draw(test);
     test=translate(test,5,3);
     test=scale(test,0.99,200,200);
     delay(100);
     if(GetKeyState(82)&0x8000)
     { drawlight(mx,my,4);
         l1:
      while(!kbhit());
      if(GetKeyState(71)&0x8000)
        drawlight(mx,my,10);
        else
        goto l1;
     }
     cleardevice();
     }
     getch();
}
