#include"iGraphics.h"
#include<math.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// complete alhamdulillah


// bfs things
int E=-1,N=-1,adj=-1;
int toss=0;
int set_kormu;
int node1,node2 , get2nd =-1 , nodeCount, edgeCount , source ;
int nodes1[21] , nodes2[21] ;
int secDone , thirDone ;
int bfsMode ;

double a[16][2]=
{	{0,0},
	{500 , 650} , /// 1
	{100,550} , 
	{ 600 , 480} , /// 3
	{1000, 550} , 
	{200,350} ,  //5
	{500 , 250} ,
	{900 , 300} ,  //7
	{100 , 150 } ,
	{ 550 , 50} , //9
	{ 350, 560} ,
	{ 350 , 100} , //11
	{ 200 , 50} ,
    { 800,480 } , //13
	{ 700 , 150}, 
	{ 1100,180 }, //15
	
};


int visit[17], level[17] ;
char s[16][11]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
int edgeColor1[17] , edgeColor2[17], edge=0;
int permitLineE1[17] , permitLineE2[17] , special , permit[17], permitLine[120] ,allready[17], permitFlagN , pause = 0 , flagN=0 , doneBFS[17]; 
int fileMode ;


//// graph drawing wonderfully
int directGraphMode;
int inputNode , inputEdge;

// bfs in c  parameters

int graph[17][17];
int qgraph[17],fgraph=0,rgraph=-1; 


int permitArray[20][20];




//dfs 
int color[17] , dfsMode,calldfs ,flagDFS , listPrint ,siz[17] ;

// rest of the things
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

void allClear()
{
	
	iPauseTimer(0);

	
	
	a[1][0]= 500 ; a[1][1]=650 ; 
	a[2][0]=100; a[2][1]=550; 
	a[3][0]= 600 ;a[3][1]= 480; /// 3
	a[4][0]=1000; a[4][1]=550; 
	a[5][0]=200;a[5][1]=350;  //5
	a[6][0]=500 ; a[6][1]=250;
	a[7][0]=900 ; a[7][1]=300;  //7
	a[8][0]=100 ; a[8][1]=150 ;
	a[9][0]= 550 ; a[9][1]=50; //9
	a[10][0]= 350;a[10][1]= 560;
	a[11][0]= 350 ; a[11][1]=100; //11
	a[12][0]=200 ; a[12][1]=50;
    a[13][0]=800;a[13][1]=480 ; //13
	a[14][0]=700 ;a[14][1]= 150; 
	a[15][0]=1100;a[15][1]=180 ; //15
	

	flagN=0 ;
	directGraphMode=0;
	inputNode=0 ; inputEdge=0 ;

	memset(permitLine,0 , sizeof permitLine);
	memset(permitArray,0 , sizeof permitArray);
	bfsMode=0;
	permitFlagN=0 ;
	fileMode=0 ;
	mode=0  ;
	 
	toss =0 ;
				pushf=-1;
				stpopvalue =-1 ;
				qpopvalue=-1;
				stsize=0;
				qsize=0;
				//////////////////// bfs clear
				node1=0; node2=0 ; get2nd =-1 ; nodeCount=0, edgeCount=0; source=0 ;
				N=-1;
				E=-1;
				adj=-1 ;
				
				memset(nodes1,0,sizeof(nodes1));
				memset(nodes2,0,sizeof(nodes2));

				bfsMode=0 ;
				secDone=0; thirDone=0 ;
				

				memset(visit,0,sizeof visit);
				memset(level,0,sizeof level);
				
				source =-1 ;

				permitFlagN=0; pause = 0 ; flagN=0 ;  
				
			memset(permit,0,sizeof(permit)) ;
			memset(permitLine,0,sizeof(permitLine));
				memset(allready,0,sizeof(allready));
				memset(doneBFS,0,sizeof(doneBFS));

				memset(graph,0,sizeof(graph)) ;
				fgraph=0;
				rgraph=-1;
				memset(qgraph,0,sizeof(qgraph)) ;
				
				
				
				
				
				node1=0; node2 =0 ; get2nd =-1 ; nodeCount=0 ; edgeCount=0 ;  source=0 ;
				// dfs clearing
				memset(color,0,sizeof(color)); dfsMode=0;calldfs=0;flagDFS=0; listPrint=0;memset(siz,0,sizeof(siz));
}



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
int iPadinput(int x, int y,int mx ,int my )
{
	if(x<=mx && mx<=x+75 && y<=my && my<=y+73)                     return 1;
	else if(x+80<=mx && mx<=x+80+75 && y<=my && my<=y+73)          return 2;
	else if(x+160<=mx && mx<=x+160+75 && y<=my && my<=y+73)        return 3;
	else if(x<=mx && mx<=x+75 && y-80<=my && my-80<=y+73)          return 4;
	else if(x+80<=mx && mx<=x+80+75 && y-80<=my && my-80<=y+73)    return 5;
	else if(x+160<=mx && mx<=x+160+75 && y-80<=my && my-80<=y+73)  return 6;
	else if(x<=mx && mx<=x+75 && y-160<=my && my-160<=y+73)        return 7;
	else if(x+80<=mx && mx<=x+80+75 && y-160<=my && my-160<=y+73)  return 8;
	else if(x+160<=mx && mx<=x+160+75 && y-160<=my && my-160<=y+73)return 9;
	else if(x+80<=mx && mx<=x+80+75 && y-240<=my && my-240<=y+73)  return 0;
}
void iDrawNum(int xx, int yy , int num)
{
	
	if(num==1){ iShowBMP(xx,yy, "1.bmp"); }
	else if(num==2){ iShowBMP(xx,yy, "2.bmp"); }
	else if(num==3){ iShowBMP(xx,yy, "3.bmp"); }
	else if(num==4){ iShowBMP(xx,yy, "4.bmp"); }
	else if(num==5){ iShowBMP(xx,yy, "5.bmp"); }
	else if(num==6){ iShowBMP(xx,yy, "6.bmp"); }
	else if(num==7){ iShowBMP(xx,yy, "7.bmp"); }
	else if(num==8){ iShowBMP(xx,yy, "8.bmp"); }
	else if(num==9){ iShowBMP(xx,yy, "9.bmp"); }
	else if(num==0){ iShowBMP(xx,yy, "0.bmp"); }
}
void first_page(void)
{	
	iClear();
	iShowBMP(220 ,600 ,"TITLE.bmp");
	iShowBMP(280+80,100,"BFS.bmp");
	iShowBMP(280+80,200 ,"DFS.bmp");
	iShowBMP(280+80,300 ,"QUEUE.bmp");
	iShowBMP(280+80,400 ,"PRIORITY QUEUE.bmp");
	iShowBMP(280+80,500 ,"STACK.bmp");
	
	iShowBMP(900+80,25 ,"EXIT.bmp");
}
void fqueue(void)
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen green
	iShowdialpad(900,350);

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

	iDrawpush(900+30, 350 + 160) ;
	iShowBMP(900+80,25 ,"BACK.bmp");
	iDrawqueue();
	iShowBMP(qposx+80, qposy-80 ,"pop.bmp");
	iShowBMP(qposx+7, qposy-80*4 ,"arrow.bmp");

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
//////////extra

void createNode(int mx, int my)
{
	printf("%d %d %d\n",N , mx ,my);
	if(N==-1) N=0;
	N++ ;
	a[N][0]=mx;
	a[N][1]=my;
}

int detectNode(int mx, int my)
{
	for(i=1; i<=N;i++)
	{
		if( ( mx-a[i][0] )*( mx-a[i][0] ) + ( my-a[i][1] )*( my-a[i][1] ) <= 30*30 ) return i;
	}
	return 0;
}


/////////////////////////
void hihi(void)
{

	FILE *fp=fopen("input.txt","r");
	fscanf(fp,"%d %d",&N,&E);
	for(i=0;i<E;i++)
	{
		int x,y;
		fscanf(fp,"%d %d",&x,&y);
		graph[x][y]=graph[y][x]=1;
	}

	fscanf(fp,"%d",&source);
	fclose(fp);

}

void bairho(char *arr)
{
	strrev(arr);
	arr[--toss]=NULL;
	strrev(arr);
}

void bfs(int src)
{
	
	int flagPL=0;
	char CvsCpp[10];
	memset(CvsCpp,0,sizeof( CvsCpp));
	CvsCpp[toss++]=(char)src ;

	visit[src]=1 ;
	level[src]=0 ;
	permitLine[flagPL++]=src ;
	
	while(toss!=0)
	{
		int top = (int) CvsCpp[0];
		permitLine[flagPL++]=top ;
		bairho(CvsCpp) ;
		for(int i=1 ; i<=N ; i++)
		{
			int x1= graph[top][i] ;
			
			if(visit[i]!=1 && x1 )
			{
				permitLine[flagPL++]=i ;
				visit[i]=1;
				permitArray[top][i]=1;
				permitArray[i][top]=1;
				
				
				level[i]=level[top]+1 ;
				CvsCpp[toss++]=(char)i;
			}
		}
	}
	memset(CvsCpp,0,sizeof (CvsCpp) );
	toss=0;
}



void dfs(int src)
{

	visit[src]=1;
	color[src]=1 ;
	
	permitLine[flagDFS++]=src ;


	for(int i=1;i<=N;i++)
	{
		int x=graph[src][i];

		if(!visit[i]&&x )
		{
			permitArray[src][i]=1;
			permitArray[i][src]=1;
			dfs(i);
		}
		
	}
	color[src]=2 ;
	permitLine[flagDFS++]=src ;

}



void permitSetter()
{
	if(mode==4)
	{
		if(pause==1) return ;
		/*if(permit[permitLine[flagN]]==1) permit[permitLine[flagN]]=2;
		else*/ permit[permitLine[flagN]]++;
		flagN++;
	}
	else if(mode==5)
	{
		if(pause==1) return ;
	
		if(permit[permitLine[flagN]]==1) allready[permitLine[flagN]]=1 ; 
		permit[permitLine[flagN]]=1;
		doneBFS[permitLine[flagN]]=1 ;
		flagN++;
	
		for(i=0;i<=10;i++)
			printf("%d ",permit[i]);
		printf("\n");
	}
}







void iPrintlevel(int i,int level)
{
	if(level==0) iText( a[i][0]-2+30, a[i][1]-2+30, "level=0");
	else if(level==1) iText( a[i][0]-2+30, a[i][1]-2+30, "level=1");
	else if(level==2) iText( a[i][0]-2+30, a[i][1]-2+30, "level=2");
	else if(level==3) iText( a[i][0]-2+30, a[i][1]-2+30, "level=3");
	else if(level==4) iText( a[i][0]-2+30, a[i][1]-2+30, "level=4");
	else if(level==5) iText( a[i][0]-2+30, a[i][1]-2+30, "level=5");
	else if(level==6) iText( a[i][0]-2+30, a[i][1]-2+30, "level=6");
	else if(level==7) iText( a[i][0]-2+30, a[i][1]-2+30, "level=7");
	else if(level==8) iText( a[i][0]-2+30, a[i][1]-2+30, "level=8");
	else if(level==9) iText( a[i][0]-2+30, a[i][1]-2+30, "level=9");
}

void iDrawNodesBFS(int E , int N)
{
	for(i=1 ; i<= N ;i ++)
	{
		if(visit[i]==1 && permit[i]==1 )
		{	iSetColor(255,0,0); }
		else iSetColor(65,0,250 );
		
		iFilledCircle(a[i][0] , a[i][1] , 30   );
		iSetColor(0,0,0 );
		iText( a[i][0]-2 , a[i][1]-2, s[i]);
		iSetColor(0,0,0);
		

		if(bfsMode==4 && permitFlagN==0 ){ flagN=0; iResumeTimer(0) ;permitFlagN=1 ;}

		if(visit[i]==0) iText( a[i][0]-2+40 , a[i][1]-2+40, "not visited");
		else if(visit[i]==1 && permit[i]==1 ) iText( a[i][0]-2+40 , a[i][1]-2+40, "visited");
		if(permit[i]==1) iPrintlevel(i,level[i]);
	}
}

void iDrawNodesDFS(int E , int N)
{

	for(i=1 ; i<= N ;i ++)
	{
		if(permit[i])
		{
			if(permit[i]==1)
			iSetColor(250,0,0);
			
			else if(permit[i]==2 )
				iSetColor(0,0,0);

		}
		else iSetColor(65,0,250 );
		
		iFilledCircle(a[i][0] , a[i][1] , 30   );
		iSetColor(0,255,0 );
		iText( a[i][0]-2 , a[i][1]-2, s[i]);
		iSetColor(0,0,0);
		

		if(bfsMode==4 && permitFlagN==0 ){ flagN=0; iResumeTimer(0) ;permitFlagN=1 ;}

		if(permit[i]==0) iText( a[i][0]-2+40 , a[i][1]-2+40, "not dicovered");
		else if(permit[i]==1 ) iText( a[i][0]-2+40 , a[i][1]-2+40, "discovered");
		else if(permit[i]==2 ) iText( a[i][0]-2+40 , a[i][1]-2+40, "discovered and explored");

	}
}

void iDrawEdgeBFS(int E,int N) // for C++ not C
{
	for(i=1 ; i<= N ; i++)
	{

		for(j=1 ; j<=N ; j++)
		{
			int x1 = graph[i][j] ;

			if(permit[i]==1 && permit[j]==1 && level[i]!=level[j] && x1 &&(permitArray[i][j] || permitArray[i][j]) )  
			{
				
				iSetColor(255,0,0) ;
			}
			else iSetColor(0,255,0); 
			
				for(k=-5;k<=5 && x1; k++)
				{
					iLine(a[i][0]+k,a[i][1]+k,a[j][0]+k,a[j][1]+k );
			
				}
		}
	}

}

void iDrawEdgeDFS(int E,int N) 
{
	for(i=1 ; i<= N ; i++)
	{

		for(j=1 ; j<=N ; j++)
		{
			int x1 = graph[i][j] ;

			if(permit[i] && permit[j] && x1 && (permitArray[i][j] || permitArray[j][i]) ) 
			{

				iSetColor(255,0,0) ;
			}
			else iSetColor(0,255,0); 
			
				for(k=-5;k<=5 && x1; k++)
				{
					iLine(a[i][0]+k,a[i][1]+k,a[j][0]+k,a[j][1]+k );
			
				}
		}
	}
}

void iDrawGraphBFS(int E , int N )
{
	iDrawEdgeBFS(E ,N);
	iDrawNodesBFS(E ,N) ;
	if(bfsMode==3) iShowBMP(900+80,25 ,"START.bmp");
	if(bfsMode==4) 
	{
		iShowBMP(900+80,25 ,"main menu.bmp");
		if(pause==0) iShowBMP(1000,350,"pause.bmp");
		else iShowBMP(1000,350,"resume.bmp");
	}
}

void iDrawGraphDFS(int E , int N )
{
	iDrawEdgeDFS(E ,N);
	iDrawNodesDFS(E ,N) ;
	if(bfsMode==3) iShowBMP(900+80,25 ,"START.bmp");
	if(bfsMode==4) 
	{
		iShowBMP(900+80,25 ,"main menu.bmp");
		if(pause==0) iShowBMP(1000,350,"pause.bmp");
		else iShowBMP(1000,350,"resume.bmp");
	}
}

void bfsThirdPage( void )
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen white
	iDrawGraphBFS(E,N) ;
	if( bfsMode==4 ) {if(calldfs==0) { bfs(source ) ; calldfs=1 ;}}
}

void dfsThirdPage( void )
{
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen white
	iDrawGraphDFS(E,N) ;
	if( bfsMode==4 ) { if(calldfs==0){ dfs(source ) ; calldfs=1 ;  for(i=0 ; permitLine[i] ;i++) ; }  }

}




void bfsSecondPage(void)
{
	
	
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen white
	iShowdialpad(500,350);
	if(E==-1 && N==-1 && adj ==-1){ iShowBMP(400,565,"nodes.bmp"); iDrawNum(500+80+80,350+60+80,pushf); }
	if(E==-1 && N!=-1 && adj ==-1 ){ iShowBMP(400,565 ,"edges.bmp");iDrawNum(500+80+80,350+60+80,pushf); }
	if(E!=-1 && N!=-1 && adj ==-1 && E>0)
	{
		iShowBMP(400,565 ,"adjacency.bmp");
		if(pushf!=-1 && get2nd==-1) iDrawNum(500+80+80,350+60+80,pushf);
		else if(pushf==-1 && get2nd == 1)
		{
			iDrawNum(500      ,350+60+80, node1);
			iDrawNum(500+80+80,350+60+80,pushf);
		}
		else if(pushf!=-1 && get2nd == 1)
		{
			iDrawNum(500      ,350+60+80, node1);
			iDrawNum(500+80+80,350+60+80,pushf);
		}
		
	}
	if(E==0) adj=1;
	if(E!=-1 && N!=-1 && adj !=-1){ iShowBMP(400,565 ,"source.bmp"); iDrawNum(500+80+80,350+60+80,pushf); }

	if(N!=-1) iDrawNum(800,350,N) ;
	if(E!=-1) iDrawNum(900,350,E) ;
	
	
	iShowBMP(500+80+80,350+80,"OK.bmp");
	
	iShowBMP(900+80,25 ,"BACK.bmp");

}

void dfsSecondPage(void)
{
	
	
	iSetColor(250,250,250);
	iFilledRectangle(0,0,screen_x,screen_y);//full screen white
	iShowdialpad(500,350);
	if(E==-1 && N==-1 && adj ==-1){ iShowBMP(400,565,"nodes.bmp"); iDrawNum(500+80+80,350+60+80,pushf); }
	if(E==-1 && N!=-1 && adj ==-1){ iShowBMP(400,565 ,"edges.bmp");iDrawNum(500+80+80,350+60+80,pushf); }
	if(E!=-1 && N!=-1 && adj ==-1 && E>0)
	{
		iShowBMP(400,565 ,"adjacency.bmp");
		if(pushf!=-1 && get2nd==-1) iDrawNum(500+80+80,350+60+80,pushf);
		else if(pushf==-1 && get2nd == 1)
		{
			iDrawNum(500      ,350+60+80, node1);
			iDrawNum(500+80+80,350+60+80,pushf);
		}
		else if(pushf!=-1 && get2nd == 1)
		{
			iDrawNum(500      ,350+60+80, node1);
			iDrawNum(500+80+80,350+60+80,pushf);
		}
		
	}
	if(E==0) adj=1 ;
	if(E!=-1 && N!=-1 && adj !=-1){ iShowBMP(400,565 ,"source.bmp"); iDrawNum(500+80+80,350+60+80,pushf); }

	if(N!=-1) iDrawNum(800,350,N) ;
	if(E!=-1) iDrawNum(900,350,E) ;
	
	
	iShowBMP(500+80+80,350+80,"OK.bmp");
	
	iShowBMP(900+80,25 ,"BACK.bmp");

}

void bfsFirstPage()
{
	iSetColor(0,0,0);
	iFilledRectangle(0,0,1300,700);
	iShowBMP(300,200,"instructions.bmp");
	iShowBMP(900+80,25 ,"BACK.bmp");

}

void Bfs(void)
{
	if(bfsMode==0) bfsFirstPage();
	if(bfsMode==1) bfsSecondPage();
	if(bfsMode==3 || bfsMode==4) bfsThirdPage();
}





void Dfs(void)
{
	if(bfsMode==0) bfsFirstPage();
	if(bfsMode==1) dfsSecondPage();
	if(bfsMode==3 || bfsMode==4) dfsThirdPage();
}







void iDraw()
{
	iClear();
	if(mode==0)
    {
        first_page();
    }
	if(mode==5)
    {
        Bfs();

    }
	if(mode==4)
    {
        Dfs();
    }
	if(mode==3)
    {
        fqueue();
    }
	if(mode==2)
    {
        p_queue();
    }
	if(mode==1)
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
			a[1][0]= 500 ; a[1][1]=650 ; 
			a[2][0]=100; a[2][1]=550; 
			a[3][0]= 600 ;a[3][1]= 480; /// 3
			a[4][0]=1000; a[4][1]=550; 
			a[5][0]=200;a[5][1]=350;  //5
			a[6][0]=500 ; a[6][1]=250;
			a[7][0]=900 ; a[7][1]=300;  //7
			a[8][0]=100 ; a[8][1]=150 ;
			a[9][0]= 550 ; a[9][1]=50; //9
			a[10][0]= 350;a[10][1]= 560;
			a[11][0]= 350 ; a[11][1]=100; //11
			a[12][0]=200 ; a[12][1]=50;
			a[13][0]=800;a[13][1]=480 ; //13
			a[14][0]=700 ;a[14][1]= 150; 
			a[15][0]=1100;a[15][1]=180 ; //15
			if(360<=mx && mx<= 780 && 100<= my && my<=150 )
			{	mode=5; }
			else if(360<=mx && mx<= 780 && 200<= my && my<=250  )
				mode=4;
			else if(360<=mx && mx<= 780 && 300<= my && my<=350)
				mode=3;
			else if(360<=mx && mx<= 780 && 400<= my && my<=450)
				mode=2;
			else if(360<=mx && mx<= 780 && 500<= my && my<=550)
				mode=1;
			else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58) //forexit button
				exit(0)  ;
			
		}
		else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && mode!=0 && bfsMode!=3  )
		{                   // back button  // bfsMode == 4 main menu
				allClear();flagN=0;
		}
		else if(mode == 3)  // queue input
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
			
			else pushf = iPadinput(x,  y, mx , my );
			

		}
		else if(mode == 1) // stack input
		{
			int x = 900, y =350 ;
			if(900+30<=mx && mx<=900+30+160 && 350+160<=my && my<=350 + 160+80)
			{
				if(pushf!=-1){ stpush(pushf);}
				pushf=-1;
				stpopvalue=-1;

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
			
			else pushf = iPadinput(x,  y, mx , my );
		}







		else if(mode == 2) // p queue input
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
			
			else pushf = iPadinput(x,  y, mx , my );

		}




		else if(mode == 5) // bfs input 
		{
			int x = 500, y =350 ;
			
			
			if(directGraphMode==1)
			{
				if(inputNode==1)
				{
					printf("node e ashchi\n");
					if(N<15) createNode(mx,my);
				}
				else if(inputEdge==1)
				{
					int x=detectNode(mx,my);
					if(x && get2nd==-1 ){ node1=x ; get2nd=1 ;  nodeCount++ ; }
					else if(x && get2nd ==1){ node2=x ; get2nd=-1; nodeCount++ ;  }
					if(nodeCount==2)
					{
						edgeCount++;
						
						graph[node1][node2]=1;
						graph[node2][node1]=1;
						

						nodeCount=0 ;
					}
				}
				else if(inputNode==-1)
				{
					int x=detectNode(mx,my);
					if(x) source = x ;
					printf("source is %d", source);
					directGraphMode==0;
				}
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E==-1 && N==-1 && adj ==-1) // ok buutton for nodes input
			{
				if(pushf!=-1){ N=pushf; }
				pushf=-1;


			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E==-1 && N!=-1 && adj ==-1) // ok buutton for edge input
			{
				int x;
				if(pushf!=-1){ E=pushf;  }

				pushf=-1;
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E!=-1 && N!=-1 && adj ==-1) // ok buutton for list
			{
				
				
				for(i=0 ; i < E ; i++ )
				{
				
					if(pushf!=-1 && get2nd==-1 ){ node1=pushf ; get2nd=1 ; pushf=-1; nodeCount++ ; }
					else if(pushf!=-1 && get2nd ==1){ node2=pushf  ; pushf=-1; get2nd=-1; nodeCount++ ;  }
					if(nodeCount==2)
					{
						edgeCount++;

						graph[node1][node2]=1;
						graph[node2][node1]=1;

						nodeCount=0 ;
					}
					
				}
				if(edgeCount==E ){ adj = 1;} // bfsMode=3 ; 

				

				
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E!=-1 && N!=-1 && adj != -1) // ok buutton for source
			{
				if(pushf!=-1){ source=pushf; }
				pushf=-1; bfsMode=3 ;
			}
			else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && bfsMode==3 ) bfsMode=4; // start button
			else if(bfsMode==4 && 1000<=mx && mx<= 1000+187 && 350<=my && my<= 350+58 ) // pause button
			{
				if(pause==0) pause=1;
				else pause =0 ;
			}
			else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && bfsMode==4  )
			{                   // back button  // bfsMode == 4 main menu
					allClear();flagN=0;
			}
			else if( bfsMode!=3 && bfsMode!=4) pushf = iPadinput(x,  y, mx , my );

			if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && bfsMode==3 ) bfsMode=4; // start button
			

		}
		else if(mode == 4) // dfs input 
		{
			int x = 500, y =350 ;

			if(directGraphMode==1)
			{
				if(inputNode==1)
				{
					printf("node e ashchi\n");
					if(N<15) createNode(mx,my);
				}
				else if(inputEdge==1)
				{
					int x=detectNode(mx,my);
					if(x && get2nd==-1 ){ node1=x ; get2nd=1 ;  nodeCount++ ; }
					else if(x && get2nd ==1){ node2=x ; get2nd=-1; nodeCount++ ;  }
					if(nodeCount==2)
					{
						edgeCount++;
						
						graph[node1][node2]=1;
						graph[node2][node1]=1;
						

						nodeCount=0 ;
					}
				}
				else if(inputNode==-1)
				{
					int x=detectNode(mx,my);
					if(x) source = x ;
					printf("source is %d", source);
					directGraphMode==0;
				}
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E==-1 && N==-1 && adj ==-1) // ok buutton for nodes input
			{
				if(pushf!=-1){ N=pushf; }
				pushf=-1;


			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E==-1 && N!=-1 && adj ==-1) // ok buutton for edge input
			{
				int x;
				if(pushf!=-1){ E=pushf;  }

				pushf=-1;
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E!=-1 && N!=-1 && adj ==-1) // ok buutton for list
			{
				
				
				for(i=0 ; i < E ; i++ )
				{
				
					if(pushf!=-1 && get2nd==-1 ){ node1=pushf ; get2nd=1 ; pushf=-1; nodeCount++ ; }
					else if(pushf!=-1 && get2nd ==1){ node2=pushf  ; pushf=-1; get2nd=-1; nodeCount++ ;  }
					if(nodeCount==2)
					{
						edgeCount++;

						graph[node1][node2]=1;
						graph[node2][node1]=1;

						nodeCount=0 ;
					}
					
				}
				if(edgeCount==E ){ adj = 1;} // bfsMode=3 ; 

				

				
			}
			else if(x+80+80<=mx && mx<=x+80+80+160 && y+80<=my && my<=y + 80+80 && E!=-1 && N!=-1 && adj != -1) // ok buutton for source
			{
				if(pushf!=-1){ source=pushf; }
				pushf=-1; bfsMode=3 ;
			}
			
			else if(bfsMode==4 && 1000<=mx && mx<= 1000+187 && 350<=my && my<= 350+58 ) // pause button
			{
				if(pause==0) pause=1;
				else pause =0 ;
			}
			else if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && bfsMode==4  )
			{                   // back button  // bfsMode == 4 main menu
					allClear();flagN=0;
			}
			
			else if( bfsMode!=3 && bfsMode!=4) pushf = iPadinput(x,  y, mx , my );
			if(980<=mx && mx<= 980+187 && 25<=my && my<= 25+58 && bfsMode==3 ) bfsMode=4; // start button

		}
		
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if((key == 'f' || key == 'F') && mode>=4)
	{
		fileMode=1 ;
		hihi();
		bfsMode=3;
		directGraphMode=0;
	}
	if((key == 'g' || key == 'G') && mode>=4)
	{
		fileMode=0 ;
		
		directGraphMode=1;
		bfsMode=3;
	}
	if( (key == 'N' || key == 'n') && mode>=4 && directGraphMode==1 )
	{
		inputNode=1;
		inputEdge=0;
		printf("%d\n",N);
	}
	if( (key == 'E' || key == 'e') && mode>=4 && directGraphMode==1 )
	{
		inputNode=0;
		inputEdge=1;
	}
	if((key == 'S' || key == 's') && mode>=4 && directGraphMode==1 )
	{
		inputNode=-1 ;
		inputEdge=-1 ;
		printf("source nibo");
	}
	if(bfsMode==0 && mode>=4 && (key == 'P' || key == 'p') ) bfsMode=1;
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
	iSetTimer(1000,permitSetter);
	iPauseTimer(0);
	
	iInitialize(screen_x, screen_y, "algorithm simulation");
	
	return 0;
}