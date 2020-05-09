# include "iGraphics.h"
#include<math.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int mode,i,j,k , pushf=-1 ;
int qpopvalue=-1 , stpopvalue=-1;
#define screen_x 1300
#define screen_y 700

#define qposx 80
#define qposy 600

#define stposx 80
#define stposy 80

//queue array 
int qu[20] , st[20],  stsize=0, qsize=0;

void qpush(int x)
{
	qu[qsize++]=x;
}



void qpop()
{
	qpopvalue=qu[0]; 
	for(i=0;i<qsize-1;i++)
	{
		qu[i]=qu[i+1];
	}
	qsize--;
}

void iDrawpush(int xx, int yy)
{
	if(pushf==-1) iShowBMP(xx,yy, "push.bmp");
	else if(pushf==1){ iShowBMP(xx,yy, "push1.bmp"); }
	else if(pushf==2){ iShowBMP(xx,yy, "push2.bmp"); }
	else if(pushf==3){ iShowBMP(xx,yy, "push3.bmp"); }
	else if(pushf==4){ iShowBMP(xx,yy, "push4.bmp"); }
	else if(pushf==5){ iShowBMP(xx,yy, "push5.bmp"); }
	else if(pushf==6){ iShowBMP(xx,yy, "push6.bmp"); }
	else if(pushf==7){ iShowBMP(xx,yy, "push7.bmp"); }
	else if(pushf==8){ iShowBMP(xx,yy, "push8.bmp"); }
	else if(pushf==9){ iShowBMP(xx,yy, "push9.bmp"); }
	else if(pushf==0){ iShowBMP(xx,yy, "push0.bmp"); }
}

void iDrawqueue()
{	int xx , yy ;
	for(i=0 , xx = qposx , yy = qposy ;i<qsize; i++ , xx+= 80 )
	{
		// if(pushf==-1) iShowBMP(xx,yy, "push.bmp");
		if(qu[i]==1){ iShowBMP(xx,yy, "1.bmp"); }
		else if(qu[i]==2){ iShowBMP(xx,yy, "2.bmp"); }
		else if(qu[i]==3){ iShowBMP(xx,yy, "3.bmp"); }
		else if(qu[i]==4){ iShowBMP(xx,yy, "4.bmp"); }
		else if(qu[i]==5){ iShowBMP(xx,yy, "5.bmp"); }
		else if(qu[i]==6){ iShowBMP(xx,yy, "6.bmp"); }
		else if(qu[i]==7){ iShowBMP(xx,yy, "7.bmp"); }
		else if(qu[i]==8){ iShowBMP(xx,yy, "8.bmp"); }
		else if(qu[i]==9){ iShowBMP(xx,yy, "9.bmp"); }
		else if(qu[i]==0){ iShowBMP(xx,yy, "0.bmp"); }
	}
}


void iShowdialpad(int x , int y)
{
	
	iShowBMP(x ,y ,"1.bmp");
	iShowBMP(x+80 ,y ,"2.bmp");
	iShowBMP(x+80+80 ,y ,"3.bmp");
	iShowBMP(x,y-80 ,"4.bmp");
	iShowBMP(x+80 ,y-80,"5.bmp");
	iShowBMP(x+80+80 ,y-80 ,"6.bmp");
	iShowBMP(x ,y-160 ,"7.bmp");
	iShowBMP(x+80 ,y-160 ,"8.bmp");
	iShowBMP(x+80+80 ,y-160 ,"9.bmp");
	iShowBMP(x+80 ,y-240 ,"0.bmp");
	
}

/*void iPadinput(int x, int y,int mx ,int my )
{
	if(x<=mx && mx<=x+75 && y<=my && my<=y+73)          pushf=1;
	if(x+80<=mx && mx<=x+80+75 && y<=my && my<=y+73)    pushf=2;
	if(x+160<=mx && mx<=x+160+75 && y<=my && my<=y+73)  pushf=3;
	if(x<=mx && mx<=x+75 && y-80<=my && my-80<=y+73)          pushf=4;
	if(x+80<=mx && mx<=x+80+75 && y-80<=my && my-80<=y+73)  pushf=5;
	if(x+160<=mx && mx<=x+160+75 && y-80<=my && my-80<=y+73)  pushf=6;
	if(x<=mx && mx<=x+75 && y-160<=my && my-160<=y+73)  pushf=7;
	if(x+80<=mx && mx<=x+80+75 && y-160<=my && my-160<=y+73)  pushf=8;
	if(x+160<=mx && mx<=x+160+75 && y-160<=my && my-160<=y+73)  pushf=9;
	if(x+80<=mx && mx<=x+80+75 && y-240<=my && my-240<=y+73)  pushf=0;
	if(x<=mx && mx<=x+75 && y<=my && my<=y+73)  pushf=1;
}*/





void first_page(void)
{	
	iClear();
	//iSetColor(200,200,200);
	//iFilledRectangle(0,0,1200,700);//full screen color
	//iShowBMP(0 ,0 ,"BUET.bmp");
	iShowBMP(220 ,600 ,"TITLE.bmp");
	iShowBMP(280+80,100,"BFS.bmp");
	iShowBMP(280+80,200 ,"DFS.bmp");
	iShowBMP(280+80,300 ,"QUEUE.bmp");
	iShowBMP(280+80,400 ,"PRIORITY QUEUE.bmp");
	iShowBMP(280+80,500 ,"STACK.bmp");
	
	iShowBMP(900+80,25 ,"EXIT.bmp");
}
void queue(void)
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowdialpad(900,350);
	//pushf=-1;
	iDrawpush(900+30, 350 + 160) ;
	iShowBMP(900+80,25 ,"BACK.bmp");
	iDrawqueue();
	iShowBMP(qposx+80, qposy-80 ,"pop.bmp");
	iShowBMP(qposx+7, qposy-80*4 ,"arrow.bmp");
	// printing pop value
	if(qpopvalue!=-1)
	{
		int xx= qposx , yy= qposy -80*5 ; 
		if(qpopvalue==1){ iShowBMP(xx,yy, "1.bmp"); }
		else if(qpopvalue==2){ iShowBMP(xx,yy, "2.bmp"); }
		else if(qpopvalue==3){ iShowBMP(xx,yy, "3.bmp"); }
		else if(qpopvalue==4){ iShowBMP(xx,yy, "4.bmp"); }
		else if(qpopvalue==5){ iShowBMP(xx,yy, "5.bmp"); }
		else if(qpopvalue==6){ iShowBMP(xx,yy, "6.bmp"); }
		else if(qpopvalue==7){ iShowBMP(xx,yy, "7.bmp"); }
		else if(qpopvalue==8){ iShowBMP(xx,yy, "8.bmp"); }
		else if(qpopvalue==9){ iShowBMP(xx,yy, "9.bmp"); }
		else if(qpopvalue==0){ iShowBMP(xx,yy, "0.bmp"); }
	}
	if(qsize==0) iShowBMP(qposx+80+240, qposy-80 , "isempty.bmp");
	else iShowBMP(qposx+80 +240 , qposy-80 , "isemptynot.bmp");
}


void stpush(int x)
{
	st[stsize++]=x;
}

void stpop()
{
	stpopvalue=st[stsize-1];
	stsize-- ;
}

void iDrawstack()
{	int xx , yy ;
	for(i=0 , xx = stposx , yy = stposy ;i<stsize; i++ , yy+= 80 )
	{
		// if(pushf==-1) iShowBMP(xx,yy, "push.bmp");
		if(st[i]==1){ iShowBMP(xx,yy, "1.bmp"); }
		else if(st[i]==2){ iShowBMP(xx,yy, "2.bmp"); }
		else if(st[i]==3){ iShowBMP(xx,yy, "3.bmp"); }
		else if(st[i]==4){ iShowBMP(xx,yy, "4.bmp"); }
		else if(st[i]==5){ iShowBMP(xx,yy, "5.bmp"); }
		else if(st[i]==6){ iShowBMP(xx,yy, "6.bmp"); }
		else if(st[i]==7){ iShowBMP(xx,yy, "7.bmp"); }
		else if(st[i]==8){ iShowBMP(xx,yy, "8.bmp"); }
		else if(st[i]==9){ iShowBMP(xx,yy, "9.bmp"); }
		else if(st[i]==0){ iShowBMP(xx,yy, "0.bmp"); }
	}
}

void stack(void)
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowdialpad(900,350);
	//pushf=-1;
	iDrawpush(900+30, 350 + 160) ;
	iDrawstack();
	if(stsize>0) iShowBMP(80+80, 80 + 80*(stsize-1) ,"pop.bmp");
	if(stpopvalue!=-1)
	{
		int xx=80+80+160 , yy = 80 + 80*stsize ;
		if(stpopvalue==1){ iShowBMP(xx,yy, "1.bmp"); }
		else if(stpopvalue==2){ iShowBMP(xx,yy, "2.bmp"); }
		else if(stpopvalue==3){ iShowBMP(xx,yy, "3.bmp"); }
		else if(stpopvalue==4){ iShowBMP(xx,yy, "4.bmp"); }
		else if(stpopvalue==5){ iShowBMP(xx,yy, "5.bmp"); }
		else if(stpopvalue==6){ iShowBMP(xx,yy, "6.bmp"); }
		else if(stpopvalue==7){ iShowBMP(xx,yy, "7.bmp"); }
		else if(stpopvalue==8){ iShowBMP(xx,yy, "8.bmp"); }
		else if(stpopvalue==9){ iShowBMP(xx,yy, "9.bmp"); }
		else if(stpopvalue==0){ iShowBMP(xx,yy, "0.bmp"); }

	}
	iShowBMP(80 , 10 ,"clear.bmp");

	if(stsize==0) iShowBMP(80 +160+80 , 10 ,"isempty.bmp");
	else iShowBMP(80 +160+80 , 10 ,"isemptynot.bmp");

	iShowBMP(900+80,25 ,"BACK.bmp");


}

void sort(int* number, int n)
{

     

    int temp=0,j,i;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(number[j] >number[j+1])
                {
                    temp=number[j];
                    number[j]=number[j+1];
                    number[j+1]=temp;
                }
            }
        }
}


void pqpush(int x)
{
	qu[qsize++]=x;
	sort(qu,qsize);
}

void p_queue(void)
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowdialpad(900,350);
	//pushf=-1;
	iDrawpush(900+30, 350 + 160) ;
	iShowBMP(900+80,25 ,"BACK.bmp");
	iDrawqueue();
	iShowBMP(qposx+80, qposy-80 ,"pop.bmp");
	iShowBMP(qposx+7, qposy-80*4 ,"arrow.bmp");
	// printing pop value
	if(qpopvalue!=-1)
	{
		int xx= qposx , yy= qposy -80*5 ; 
		if(qpopvalue==1){ iShowBMP(xx,yy, "1.bmp"); }
		else if(qpopvalue==2){ iShowBMP(xx,yy, "2.bmp"); }
		else if(qpopvalue==3){ iShowBMP(xx,yy, "3.bmp"); }
		else if(qpopvalue==4){ iShowBMP(xx,yy, "4.bmp"); }
		else if(qpopvalue==5){ iShowBMP(xx,yy, "5.bmp"); }
		else if(qpopvalue==6){ iShowBMP(xx,yy, "6.bmp"); }
		else if(qpopvalue==7){ iShowBMP(xx,yy, "7.bmp"); }
		else if(qpopvalue==8){ iShowBMP(xx,yy, "8.bmp"); }
		else if(qpopvalue==9){ iShowBMP(xx,yy, "9.bmp"); }
		else if(qpopvalue==0){ iShowBMP(xx,yy, "0.bmp"); }
	}
	if(qsize==0) iShowBMP(qposx+80+240, qposy-80 , "isempty.bmp");
	else iShowBMP(qposx+80 +240 , qposy-80 , "isemptynot.bmp");
}



void bfs(void)
{
	iSetColor(0,255,0);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowBMP(900+80,25 ,"BACK.bmp");
}

void dfs(void)
{
	iSetColor(0,255,255);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowBMP(900+80,25 ,"BACK.bmp");

}







void iDraw()
{
	iClear();
	if(mode==0)
    {
        first_page();
    }
	if(mode==1)
    {
        bfs();

    }
	if(mode==2)
    {
        dfs();
    }
	if(mode==3)
    {
        queue();
    }
	if(mode==4)
    {
        p_queue();
    }
	if(mode==5)
    {
        stack();
    }

}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mode==0)
		{
			if(360<=mx && mx<= 780 && 100<= my && my<=150 )
				mode=1;
			else if(360<=mx && mx<= 780 && 200<= my && my<=250  )
				mode=2;
			else if(360<=mx && mx<= 780 && 300<= my && my<=350)
				mode=3;
			else if(360<=mx && mx<= 780 && 400<= my && my<=450)
				mode=4;
			else if(360<=mx && mx<= 780 && 500<= my && my<=550)
				mode=5;
			else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58) //forexit button
				exit(0)  ;
			
		}
		else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && mode!=0)
		{                   // back button
				mode=0  ;
				pushf=-1;
				stpopvalue =-1 ;
				qpopvalue=-1;
				stsize=0;
				qsize=0;
		}
		else if(mode == 3)
		{
			int x = 900, y =350 ;
			if(900+30<=mx && mx<=900+30+160 && 350+160<=my && my<=350 + 160+80)
			{
				if(pushf!=-1){ qpush(pushf);}
				pushf=-1;

			}
			else if (qposx+80 <= mx && mx<= qposx+80+160 && qposy-80<=my && my <=qposy-15  )
			{
				if(qsize!= 0) qpop() ;
				else qpopvalue = -1 ;
			}
			else if(x<=mx && mx<=x+75 && y<=my && my<=y+73)          pushf=1;
			else if(x+80<=mx && mx<=x+80+75 && y<=my && my<=y+73)    pushf=2;
			else if(x+160<=mx && mx<=x+160+75 && y<=my && my<=y+73)  pushf=3;
			else if(x<=mx && mx<=x+75 && y-80<=my && my-80<=y+73)          pushf=4;
			else if(x+80<=mx && mx<=x+80+75 && y-80<=my && my-80<=y+73)  pushf=5;
			else if(x+160<=mx && mx<=x+160+75 && y-80<=my && my-80<=y+73)  pushf=6;
			else if(x<=mx && mx<=x+75 && y-160<=my && my-160<=y+73)  pushf=7;
			else if(x+80<=mx && mx<=x+80+75 && y-160<=my && my-160<=y+73)  pushf=8;
			else if(x+160<=mx && mx<=x+160+75 && y-160<=my && my-160<=y+73)  pushf=9;
			else if(x+80<=mx && mx<=x+80+75 && y-240<=my && my-240<=y+73)  pushf=0;
			

		}
		else if(mode == 5)
		{
			int x = 900, y =350 ;
			if(900+30<=mx && mx<=900+30+160 && 350+160<=my && my<=350 + 160+80)
			{
				if(pushf!=-1){ stpush(pushf);}
				pushf=-1;

			}
			else if (80<= mx && mx<= 80+160 && 10<=my && my <=10+75)
			{
				stsize=0;
				stpopvalue=-1;
			}
			else if (80+80 <= mx && mx<= 80+80+160 && 80+80*(stsize-1)<=my && my <=80+80*(stsize-1)+75  )
			{
				if(stsize!= 0) stpop() ;
				else stpopvalue = -1 ;
			}
			else if(x<=mx && mx<=x+75 && y<=my && my<=y+73)          pushf=1;
			else if(x+80<=mx && mx<=x+80+75 && y<=my && my<=y+73)    pushf=2;
			else if(x+160<=mx && mx<=x+160+75 && y<=my && my<=y+73)  pushf=3;
			else if(x<=mx && mx<=x+75 && y-80<=my && my-80<=y+73)          pushf=4;
			else if(x+80<=mx && mx<=x+80+75 && y-80<=my && my-80<=y+73)  pushf=5;
			else if(x+160<=mx && mx<=x+160+75 && y-80<=my && my-80<=y+73)  pushf=6;
			else if(x<=mx && mx<=x+75 && y-160<=my && my-160<=y+73)  pushf=7;
			else if(x+80<=mx && mx<=x+80+75 && y-160<=my && my-160<=y+73)  pushf=8;
			else if(x+160<=mx && mx<=x+160+75 && y-160<=my && my-160<=y+73)  pushf=9;
			else if(x+80<=mx && mx<=x+80+75 && y-240<=my && my-240<=y+73)  pushf=0;

		}
		else if(mode == 4)
		{
			int x = 900, y =350 ;
			if(900+30<=mx && mx<=900+30+160 && 350+160<=my && my<=350 + 160+80)
			{
				if(pushf!=-1){ pqpush(pushf);}
				pushf=-1;

			}
			else if (qposx+80 <= mx && mx<= qposx+80+160 && qposy-80<=my && my <=qposy-15  )
			{
				if(qsize!= 0) qpop() ;
				else qpopvalue = -1 ;
			}
			else if(x<=mx && mx<=x+75 && y<=my && my<=y+73)          pushf=1;
			else if(x+80<=mx && mx<=x+80+75 && y<=my && my<=y+73)    pushf=2;
			else if(x+160<=mx && mx<=x+160+75 && y<=my && my<=y+73)  pushf=3;
			else if(x<=mx && mx<=x+75 && y-80<=my && my-80<=y+73)          pushf=4;
			else if(x+80<=mx && mx<=x+80+75 && y-80<=my && my-80<=y+73)  pushf=5;
			else if(x+160<=mx && mx<=x+160+75 && y-80<=my && my-80<=y+73)  pushf=6;
			else if(x<=mx && mx<=x+75 && y-160<=my && my-160<=y+73)  pushf=7;
			else if(x+80<=mx && mx<=x+80+75 && y-160<=my && my-160<=y+73)  pushf=8;
			else if(x+160<=mx && mx<=x+160+75 && y-160<=my && my-160<=y+73)  pushf=9;
			else if(x+80<=mx && mx<=x+80+75 && y-240<=my && my-240<=y+73)  pushf=0;
			

		}
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}


int main()
{
	
	iInitialize(screen_x, screen_y, "algorithm simulation");
	return 0;
}