/*
car and traffic light program
assignment
--------------how to use-----------
press r or y to stop car
press g to turn signal green

*/
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
using namespace std;
struct obj{
        double mt[50][2];
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
           line(0,my/3-20,mx,my/3-20);
           setcolor(8);
           line(mx/2-50,my/3-20,mx/2-400,my);
           line(mx/2+50,my/3-20,mx/2+400,my);
        }
void drawlight(int mx,int my)
        { //getch();
          setcolor(14);
          setfillstyle(1,5);
          circle(870,my-580,15);
          circle(870,my-545,15);
          circle(870,my-510,15);
          rectangle(850,my-600,890,my-490);
          rectangle(860,my-490,880,my-350);
          floodfill(852,(my-598),14);
          floodfill(862,my-488,14);
          setcolor(15);
        }
void fillcolor(int mx,int my,int state)
{
    if (state== 0)
        {setfillstyle(1,4);
        floodfill(870,my-580,14);
        setfillstyle(1,0);
        floodfill(870,my-545,14);
        floodfill(870,my-510,14);
        }
    else if(state==1)
        {setfillstyle(1,14);
        floodfill(870,my-545,14);
        setfillstyle(1,0);
        floodfill(870,my-580,14);
        floodfill(870,my-510,14);
        }
    else if(state==2)
        {setfillstyle(1,2);
        floodfill(870,my-510,14);
        setfillstyle(1,0);
        floodfill(870,my-580,14);
        floodfill(870,my-545,14);
        }
}
int main()
{   int mx=GetSystemMetrics(SM_CXFULLSCREEN)-3;
    int my=GetSystemMetrics(SM_CYFULLSCREEN);
     initwindow(mx,my,"x");
     obj test;
     int vertices=32;
    double mat[32][2]={20,20,40,20,40,40,20,40,100,20,120,20,120,40,
                   100,40,10,40, 10,90, 130,90,130,40,90,130,50,130,
                   50,120,90,120,20,90, 120,90,40,80, 20,80, 20,60,
                   40,60,100,80, 120,80,120,60,100,60,50,75,90,75,
                   50,60,90,60,35,50,105,50
                   };
       test.points=vertices;
    int adj[32][32]=
                  {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                   };

    for (int i=0;i<vertices;i++)
    {
        test.mt[i][0]=mat[i][0];
        test.mt[i][1]=mat[i][1];
        for(int j=0;j<vertices;j++)
          test.adj[i][j]=adj[i][j];
    }

    test=scale(test,2,0,0);
    test=translate(test,400,0);
     for(int k=0;k<440;k++)
     {
      drawscene(mx,my);
      drawlight(mx,my);
      fillcolor(mx,my,2);
     //setcolor(k%14);
     draw(test);
     //getch();
     test=translate(test,5,3);
     test=scale(test,0.99,200,200);
     delay(100);
     if(GetKeyState(82)&0x8000)
     { fillcolor(mx,my,0);
         l1:
      while(!kbhit());
      if(GetKeyState(89)&0x8000)
        fillcolor(mx,my,1);
        while(!kbhit());
     if(GetKeyState(71)&0x8000)
        fillcolor(mx,my,2);
        else
        goto l1;
     }
     if((GetKeyState(89)&0x8000))
     { fillcolor(mx,my,1);
         l2:
      while(!kbhit());
      if(GetKeyState(82)&0x8000)
        fillcolor(mx,my,2);
        while(!kbhit());
     if(GetKeyState(71)&0x8000)
        fillcolor(mx,my,2);
        else
        goto l2;
     }

     cleardevice();
     }
     getch();
}
