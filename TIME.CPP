#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
inline void play(int hr,int in);
void play(int hr, int in)
{
long double x[200],y[200], a=0,xhr,yhr, x_center =getmaxx()/2, y_center=getmaxy()/2, xmin, ymin, rad = 65, xsec, ysec;
long int min, tmin=in*60+2700, thr,t,t1,t3,t4;
for(int l=10;l<22;l++)
		{
		x[l] =  x_center + 80 *  cos(30*l*3.14/180);
		y[l] =  y_center + 80 *  sin(30*l*3.14/180);
		}
int x1[200], y1[200];
	     for(int u=0, r=10;r<22;r++,u++)
		{
		x1[u]=x[r];
		y1[u]=y[r];
		}
t=hr*3600;
t1=hr-12;
t3=t1*3600;
t4=in*60;
min=hr;
  if(hr==10)
	thr=68400+t4;
  else if(hr==11)
	thr=72000+t4;
  else if(hr<12)
	thr=t+t4+32400;
  else if(hr>12&&hr<24)
	thr=t3+t4+32400;
  else
	thr=t4+32400;
     for(long int i=45, j=tmin, k=thr; k<75601;i++,j++,k++)
     {
     if(!kbhit())
	     {
	     cleardevice();
	     xsec =  x_center + rad *  cos(6*i*3.14/180);
	     ysec =  y_center + rad *  sin(6*i*3.14/180);
	     xmin =  x_center + 75  *  cos(0.1*j*3.14/180);
	     ymin =  y_center + 75  *  sin(0.1*j*3.14/180);
	     xhr  =  x_center + 50  *  cos(0.0083333*k*3.14/180);
	     yhr  =  y_center + 50  *  sin(0.0083333*k*3.14/180);
	     setcolor(15);
	     line(xsec,ysec,x_center,y_center);
	     line(xmin,ymin,x_center,y_center);
	     line(xhr,yhr,x_center,y_center);
	     setcolor(4);
	     circle(x_center,y_center,90);
	     setcolor(14);
	     outtextxy(x1[0]-2,y1[0]-2,"1");
	     outtextxy(x1[1]-2,y1[1]-2,"2");
	     outtextxy(x1[2]-2,y1[2]-2,"3");
	     outtextxy(x1[3]-2,y1[3]-2,"4");
	     outtextxy(x1[4]-2,y1[4]-2,"5");
	     outtextxy(x1[5]-2,y1[5]-2,"6");
	     outtextxy(x1[6]-2,y1[6]-2,"7");
	     outtextxy(x1[7]-2,y1[7]-2,"8");
	     outtextxy(x1[8]-2,y1[8]-2,"9");
	     outtextxy(x1[9]-2,y1[9]-2,"10");
	     outtextxy(x1[10]-2,y1[10]-2,"11");
	     outtextxy(x1[11]-2,y1[11]-2,"12");
	     setcolor(5);
	     outtextxy(x_center-80,y_center+180,"Press Any Key To Exit");
	     if(k==75600)
	     k=32400;
	     if(j==6300)
	     j=2700;
	     if(i==105)
	     i=45;
	     if(i==45)
		{    if(a==59)
			min++;
		     a=(j-2700)/60;
		     gotoxy(35,5);
		     cout<<"Min:"<<a;
		}
	     else
		  {
		     gotoxy(35,5);
		     cout<<"Min:"<<a;
		  }
	     gotoxy(20,5);
	     if(min<=23)
		cout<<"Hr:"<<min;
	     else
		{
		min=0;
		cout<<"Hr:"<<min;
		}
	     gotoxy(50,5);
	     cout<<"Sec:"<<i-45;
	     if(j==2700)
	     {
	     sound(4000);
	     delay(150);
	     nosound();
	     delay(100);
	     sound(4000);
	     delay(150);
	     nosound();
	     sound(30000);
	     delay(50);
	     nosound();
	     delay(550);
	     }
	     else
	      {
	     sound(30000);
	     delay(50);
	     nosound();
	     delay(950);
	      }
	     }
     }
}
void main()
{
	clrscr();
	int hr,min;
	char ch;
	cout<<"\n\n\n\t\t\tPress:\n\n\t\t1. Enter Time\n\t\t2. Get time from System   ";
	Z:
	ch=getch();
	switch(ch)
	{
	case '1':
		cout<<"\n\n\n\n\t\tEnter time:\n\t\t\tHr: ";
		cin>>hr;
		cout<<"\n\t\t\tmin: ";
		cin>>min;
		break;
	case '2':
		struct time t;
		gettime(&t);
		hr=(int)t.ti_hour;
		min=(int)t.ti_min;
		break;
	default:
		cout<<"\n\n\t\t\tWrong entry!!!!";
		goto Z;
	}
    int   driver = DETECT,mode;
    initgraph(&driver,&mode,"c:\\turboc3\\bgi");
     play(hr,min);
     getch();
     closegraph();
    }