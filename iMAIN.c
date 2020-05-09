# include "iGraphics.h"
#include<math.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void first_page(void)
{	
	iClear();
	iSetColor(255,255,102);
	iFilledRectangle(0,0,1200,700);//full screen yellow
	iShowBMP(150,180,"BFS.bmp");
	iShowBMP(150 ,280 ,"DFS.bmp");
	iShowBMP(150 ,380 ,"QUEUE.bmp");
	iShowBMP(150 ,480 ,"PRORIT YQUEUE.bmp");
	iShowBMP(150 ,580 ,"STACK.bmp");
	
	iFilledRectangle(1100, 20, 80, 30);//exit er box
	iSetColor(0, 0, 0);
	iSetColor(255, 255, 102);//vul
	iText(1125, 31, "Exit");
}

void iDraw()
{
	iClear();
	if(1)
    {
        first_page();
    }
}



int main()
{
	//printf("\n\n%s\n%s", picture_i, exp_a);
	iInitialize(1200, 700, "ALGORITHM SIMULATION");

}