# include "iGraphics.h"
# include <stdio.h>
#include "gl.h"

int	z = 1, l = 1, e = 1, E = 0, i = 0, S = -1, I = -1, temp = 0, t, t2 = 1, c = 0, d = 0, M = 0, al = 1,res = 0, M1 = 0, M2 = 0, or = 1, op = 0, opr = 0;
int Ara[16], Ara2[120][16];


void iShowNumber(double x1, double y1, double l, double w, int number)
{

	int n1 = 1, n2 = 1, n3 = 1, n4 = 1, n5 = 1, n6 = 1, n7 = 1;

	if (number == 1) n1 = 0, n2 = 0, n3 = 0, n4 = 0, n6 = 0;
	else if (number == 2)  n4 = 0, n7 = 0;
	else if (number == 3)  n4 = 0, n6 = 0;
	else if (number == 4)  n1 = 0, n3 = 0, n6 = 0;
	else if (number == 5)  n5 = 0, n6 = 0;
	else if (number == 6)  n5 = 0;
	else if (number == 7)  n2 = 0, n3 = 0, n4 = 0, n6 = 0;
	else if (number == 8)  n1 = 1;
	else if (number == 9)  n6 = 0;
	else if (number == 0)  n2 = 0;


	if (n1) iLine(x1 + l / 2 - w / 4, y1 + w - 20, x1 + l / 2 + w / 4, y1 + w - 20);
	if (n2) iLine(x1 + l / 2 - w / 4, y1 + w / 2, x1 + l / 2 + w / 4, y1 + w / 2);
	if (n3) iLine(x1 + l / 2 - w / 4, y1 + 20, x1 + l / 2 + w / 4, y1 + 20);
	if (n4) iLine(x1 + l / 2 - w / 4, y1 + w - 20, x1 + l / 2 - w / 4, y1 + w / 2);
	if (n5) iLine(x1 + l / 2 + w / 4, y1 + w - 20, x1 + l / 2 + w / 4, y1 + w / 2);
	if (n6) iLine(x1 + l / 2 - w / 4, y1 + 20, x1 + l / 2 - w / 4, y1 + w / 2);
	if (n7) iLine(x1 + l / 2 + w / 4, y1 + 20, x1 + l / 2 + w / 4, y1 + w / 2);

}
void iShowNumber2(double x, double y, double l, double w, int number){

	if (number / 10 == 0) {
		iSetColor(255-number * 2.5, 255, 255);
		iFilledRectangle(x-w/2 +l/2-8, y, w+17, w);
		iSetColor(0, 0, 0);
		iShowNumber(x, y, l, w, number);
	}
	else if (number / 10 <= 9) {
		iSetColor(255 - number * 2, 255, 255);
		iFilledRectangle(x - w / 4 - w / 16 + l / 2 - w / 2 +12, y, 13 * w / 8 - 22, w);
		iSetColor(0, 0, 0);
		iShowNumber(x - w / 4 - w / 16, y, l, w, number / 10);
		iShowNumber(x + w / 4 + w / 16, y, l, w, number % 10);

	}



}
void iShowNumber3(double x, double y, double l, double w, int number, int clr){
	if (number / 10 == 0) {
		if (clr == 1) iSetColor(200 - number * 2.5, 150 - number * 2.5, 200 - number * 2.5);
		iFilledRectangle(x - w / 2 + l / 2 - 8, y, w + 17, w);
		iSetColor(0, 0, 0);
		iShowNumber(x, y, l, w, number);
	}
	else if (number / 10 <= 9) {
		if (clr == 1)iSetColor(200 - number * 2, 255 - number * 2.5, 255 - number * 2.5);
		iFilledRectangle(x - w / 4 - w / 16 + l / 2 - w / 2 + 12, y, 13 * w / 8 - 22, w);
		iSetColor(0, 0, 0);
		iShowNumber(x - w / 4 - w / 16, y, l, w, number / 10);
		iShowNumber(x + w / 4 + w / 16, y, l, w, number % 10);

	}
}
void iDrawInputBox(void)
{

	iSetColor(15,15,15);
	iFilledRectangle(435, 50, 480, 480);


	iSetColor(100, 255, 255);
	iFilledRectangle(455, 70, 133.33, 95);
	iFilledRectangle(628.33, 70, 247, 95);
	iFilledRectangle(455, 185, 133.33, 95);
	iFilledRectangle(608.33, 185, 133.33, 95);
	iFilledRectangle(608.33, 300, 133.33, 95);
	iFilledRectangle(608.33, 415, 133.33, 95);
	iFilledRectangle(761.66, 300, 133.33, 95);
	iFilledRectangle(761.66, 415, 133.33, 95);
	iFilledRectangle(761.66, 185, 133.33, 95);
	iFilledRectangle(455, 300, 133.33, 95);
	iFilledRectangle(455, 415, 133.33, 95);

	iSetColor(13, 45, 67);
	iShowNumber(455, 70, 133.33, 95, 0);
	iShowNumber(650.33, 70, 133.33, 95, 0);
	iShowNumber(678.33, 70, 133.33, 95, 1);
	iLine(768.745, 117.5, 788.245, 145);
	iLine(768.745, 117.5, 788.245, 90);
	iShowNumber(455, 185, 133.33, 95, 1);
	iShowNumber(608.33, 185, 133.33, 95, 2);
	iShowNumber(608.33, 300, 133.33, 95, 5);
	iShowNumber(608.33, 415, 133.33, 95, 8);
	iShowNumber(761.66, 300, 133.33, 95, 6);
	iShowNumber(761.66, 415, 133.33, 95, 9);
	iShowNumber(761.66, 185, 133.33, 95, 3);
	iShowNumber(455, 300, 133.33, 95, 4);
	iShowNumber(455, 415, 133.33, 95, 7);




}
void iDrawInputBoxBar()
{
	iSetColor(30, 30, 30);
	iFilledRectangle(1245, 630, 100, 50);
	iSetColor(200, 200, 200);
	iText(1246, 650, " Input Box");

}
void iDrawElementBoxBar()
{
	iSetColor(45, 45, 45);
	iFilledRectangle(1245, 580, 100, 50);
	iSetColor(200, 200, 200);
	iText(1246, 600, " Element No");
	

}
void iDrawAlgorithmBoxBar()
{
	iSetColor(50, 50, 50);
	iFilledRectangle(1245, 530, 100, 50);
	iSetColor(200, 200, 200);
	iText(1246, 550, " Algorithm");


}
void iDrawOrderBox(){
	iSetColor(0, 0, 15);
	iFilledRectangle(495, 380, 230, 250);
	iSetColor(100, 250, 250);
	if (M2 == 2) iSetColor(0, 0, 70);
	iFilledRectangle(515, 400, 210, 95);
	iSetColor(5, 0, 0);
	if (M2 == 2) iSetColor(100, 255, 255);
	iText(550, 445, "Ascending Order");
	iSetColor(50, 95, 175);
	if (M2 == 1) iSetColor(0, 0, 70);
	iFilledRectangle(515, 515, 210, 95);
	iSetColor(5, 0, 0);
	if (M2 == 1) iSetColor(100, 255, 255);
	iText(550, 560, "Descending Order");
}
void iDrawAlgorithmBox()
{
	iSetColor(0, 0, 15);
	iFilledRectangle(725, 380, 500, 250);
	iSetColor(50, 10, 175);
	if (M1 == 4 || M1 == 2 || M1 == 3) iSetColor(0, 0, 40);
	iFilledRectangle(745, 400, 210, 210);
	iSetColor(0, 0, 20);
	if (M1 == 4 || M1 == 2 || M1 == 3) iSetColor(100, 255, 255);
	iText(800, 500, "Bubble Sort");
	iSetColor(120, 255, 255);
	if (M1 == 4 || M1 == 1 || M1 == 3) iSetColor(0, 0, 40);
	iFilledRectangle(975, 400, 230, 95);
	iSetColor(0, 0, 20);
	if (M1 == 4 || M1 == 1 || M1 == 3) iSetColor(100, 255, 255);
	iText(1030, 440, "Selection Sort");
	iSetColor(100, 255, 255);
	if (M1 == 4 || M1 == 2 || M1 == 1) iSetColor(0, 0, 40);
	iFilledRectangle(975, 515, 105, 95);
	iSetColor(0, 0, 20);
	if (M1 == 4 || M1 == 2 || M1 == 1) iSetColor(100, 255, 255);
	iText(1000, 570, "Quick");
	iText(1000, 550, "Sort");
	iSetColor(50, 95, 175);
	if (M1 == 1 || M1 == 2 || M1 == 3) iSetColor(0, 0, 40);
	iFilledRectangle(1100, 515, 105, 95);
	iSetColor(0, 0, 20);
	if (M1 == 1 || M1 == 2 || M1 == 3) iSetColor(100, 255, 255);
	iText(1115, 570, "Marge");
	iText(1115, 550, "Sort");



}
void iDrawSettingBar()
{
	iSetColor(20, 20, 20);
	iFilledRectangle(1245, 680, 100, 50);
	iSetColor(255, 255, 255);
	iText(1260, 700, "Settings");

}
void iDrawElementBox(){

	iSetColor(45, 45, 45);
	if (E == 16) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 17, 100, 46);
	iSetColor(55, 55, 55);
	if (E == 15) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 62.66, 100, 46.66);
	iSetColor(60, 60, 60);
	if (E == 14) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 109.32, 100, 46.66);
	iSetColor(65, 65, 65);
	if (E == 13) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 155.98, 100, 46.66);
	iSetColor(70, 70, 70);
	if (E == 12) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 202.64, 100, 46.66);
	iSetColor(75,75,75);
	if (E == 11) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 249.30, 100, 46.66);
	iSetColor(80,80,80);
	if (E == 10) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 295.96, 100, 46.66);
	iSetColor(82,82,82);
	if (E == 9) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 342.62, 100, 46.66);
	iSetColor(85,85,85);
	if (E == 8) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 389.28, 100, 46.66);
	iSetColor(88,88,88);
	if (E == 7) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 435.94, 100, 46.66);
	iSetColor(90,90,90);
	if (E == 6) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 482.60, 100, 46.66);
	iSetColor(93,93,93);
	if (E == 5) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 529.26, 100, 46.66);
	iSetColor(95,95,95);
	if (E == 4) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 575.92, 100, 46.66);
	iSetColor(100,100,100);
	if (E == 3) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 622.58, 100, 46.66);
	iSetColor(103,103,103);
	if (E == 2) iSetColor(35, 35, 35);
	iFilledRectangle(1145, 669.24, 100, 46.66);
	

	iSetColor(0, 0, 0);
	iText(1185, 690, " 2");
	iText(1185, 643, " 3");
	iText(1185, 596.68, " 4");
	iText(1185, 550, " 5");
	iText(1185, 503.36, " 6");
	iText(1185, 456.7, " 7");
	iText(1185, 410.04, " 8");
	iText(1185, 363.38, " 9");
	iText(1185, 316.72, "10");
	iText(1185, 270.06, "11");
	iText(1185, 223.4, "12");
	iText(1185, 176.74, "13");
	iText(1185, 130.08, "14");
	iText(1185, 83.42, "15");
	iText(1185, 37.00, "16");
}
void iDrawDisplayBox()
{
	if (z == -1){
		iSetColor(15, 15, 15);
		iFilledRectangle(435, 550, 480, 95);
	}
}
void iDisplayBox()
{
	iDrawDisplayBox();
	if (I != -1)
	{
		iSetColor(234, 240, 250);
		iShowNumber2(435, 550, 480, 95, temp);
	}


}
void iSettingBox()
{
	iDrawSettingBar();
	if (z == -1) iDrawInputBox();
	if (e == -1) iDrawElementBox();
	if (al == -1) iDrawAlgorithmBox();
	if (or == -1) iDrawOrderBox();
	if (l == -1) {
		iDrawInputBoxBar();
		iDrawElementBoxBar();
		iDrawAlgorithmBoxBar();
	}
	iDisplayBox();


}
void iAlgorithmBox(double mx, double my){

	if (al == -1 && mx > 745 && mx<955 && my>400 && my<610) M1 = 1, or = -1, M2 = 0;
	else if (al == -1 && mx>975 && mx<1205 && my>400 && my<495) M1 = 2, or = -1, M2 = 0;
	else if (al == -1 && mx>975 && mx<1080 && my>515 && my<610) M1 = 3, or = -1, M2 = 0;
	else if (al == -1 && mx>1100 && mx<1205 && my>515 && my<610) M1 = 4, or = -1, M2 = 0;

}
void iOrderBox(double mx, double my){
	if (or == -1 && mx>515 && mx<725 && my>400 && my<495) M2 = 1, or = 1, al = 1;
	else if (or == -1 && mx>515 && mx<725 && my>515 && my<610) M2 = 2, or = 1, al = 1;
}
void iGetElement(double mx,double my)
{
	if (e == -1 && mx > 1145 && mx< 1245 && my>17 && my < 62.66) E = 16,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>62.66 && my < 109.32) E = 15,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>109.32 && my < 155.98) E = 14,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>155.98 && my < 202.64) E = 13,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>202.64 && my < 249.30) E = 12,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>249.30 && my < 295.96) E = 11,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>295.96 && my < 342.62) E = 10,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>342.62 && my < 389.28) E = 9,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>389.28 && my < 435.94) E = 8,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>435.94 && my < 482.60) E = 7,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>482.60 && my < 529.26) E = 6,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>529.26 && my < 575.92) E = 5,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>575.92 && my < 622.58) E = 4,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>622.58 && my < 669.24) E = 3,i=0;
	else if (e == -1 && mx > 1145 && mx< 1245 && my>669.24 && my < 715) E = 2,i=0;

	S = 0, c = 0, d = 0;
}
void iShowElements(double x2,double y2)
{
		for (t = 0; t < i; t++){
			if (M == 1 || M == 2){
				if ((t == d || t == d+1) && z == 1 && c != E - 1){
					iSetColor(25, 150, 255);
					iShowNumber3(x2 + 1200 / 15 * t, y2, 100, 60, Ara[t], 2);
				}

				else{
					iSetColor(255, 255, 255);
					iShowNumber3(x2 + 1200 / 15 * t, y2, 100, 60, Ara[t],1);
				}
			}
			else if (M == 3 || M == 4){
				if ((t == d || t == c) && z == 1 && c != E - 1){
					iSetColor(25, 150, 255);
					iShowNumber3(x2 + 1200 / 15 * t, y2, 100, 60, Ara[t],2);
				}

				else{
					iSetColor(255, 255, 255);
					iShowNumber3(x2 + 1200 / 15 * t, y2, 100, 60, Ara[t],1);
				}
			}
			else {
				iSetColor(255, 255, 255);
				iShowNumber2(x2 + 1200 / 15 * t, y2, 100, 60, Ara[t]);

			}


		}
}
void iGetInput(double mx, double my){

	if (z == -1 && mx > 455 && mx<588 && my>185 && my<275) I = 1, temp = temp * 10 + I;
	else if (z == -1 && mx>608.33 && mx<746 && my>185 && my<275) I = 2, temp = temp * 10 + I;
	else if (z == -1 && mx>761.66 && mx<900 && my>185 && my<275) I = 3, temp = temp * 10 + I;
	else if (z == -1 && mx>455 && mx<588 && my>300 && my<400) I = 4, temp = temp * 10 + I;
	else if (z == -1 && mx>608.33 && mx<742 && my>300 && my<400) I = 5, temp = temp * 10 + I;
	else if (z == -1 && mx>761.66 && mx<900 && my>300 && my<400) I = 6, temp = temp * 10 + I;
	else if (z == -1 && mx>455 && mx<588 && my>415 && my<505) I = 7, temp = temp * 10 + I;
	else if (z == -1 && mx>608.33 && mx<742 && my>415 && my<505) I = 8, temp = temp * 10 + I;
	else if (z == -1 && mx>761.66 && mx<900 && my>415 && my<505) I = 9, temp = temp * 10 + I;
	else if (z == -1 && mx>455 && mx<588.33 && my>70 && my<170) I = 0, temp = temp * 10 + I;
	else if (z == -1 && mx>588.33 && mx<875 && my>70 && my < 170) {
		Ara[i++] = temp;
		temp = 0;
		I = -1;
	}

	if (i >= E) z = 1, l = 1;//S=1;




}
void iStartSimulation(){
	if (M1 == 1 && M2 == 1) M = 1;
	else if (M1 == 1 && M2 == 2) M = 2;
	else if (M1 == 2 && M2 == 1) M = 3, d = 1;
	else if (M1 == 2 && M2 == 2) M = 4, d = 1;
}
void iBubbleSortD(){


	int swap;

	if (t2 == -1){
		iSetColor(255, 255, 255);
		while (c < (E))
		{
			while (d < E - c - 1)
			{
				if (Ara[d] < Ara[d + 1])
				{
					swap = Ara[d];
					Ara[d] = Ara[d + 1];
					Ara[d + 1] = swap;
				}
				t2 = t2*-1;

				if (d + 1 == E - c - 1) {
					c++;
					d = 0;
					break;
				}
				else{
					d = (d + 1);
					break;
				}

			}
			if (t2 == 1) break;
		}

	}




}
void iBubbleSortI(){


	int swap;

	if (t2 == -1){
		iSetColor(255, 255, 255);
		while (c < (E))
		{
			while (d < E -c-1)
			{
				if (Ara[d] > Ara[d+1])
				{
					swap = Ara[d];
					Ara[d] = Ara[d+1];
					Ara[d+1] = swap;
				}
				t2 = t2*-1;

				if (d + 1 == E-c-1) {
					c++;
					d = 0;
					break;
				}
				else{
					d = (d + 1);
					break;
				}

			}
			if (t2 == 1) break;
			//break;
		}

	}
}
void iSelectionSortI(){


	int swap;

	if (t2 == -1){
		iSetColor(255, 255, 255);
		while (c < (E))
		{
			while (d < E)
			{
				if (Ara[c] > Ara[d])
				{
					swap = Ara[c];
					Ara[c] = Ara[d];
					Ara[d] = swap;
				}
				t2 = t2*-1;

				if (d + 1 == E ) {
					c++;
					d = c+1;
					break;
				}
				else{
					d = (d + 1);
					break;
				}

			}
			if (t2 == 1) break;
			//break;
		}

	}
}
void iSelectionSortD(){


	int swap;

	if (t2 == -1){
		iSetColor(255, 255, 255);
		while (c < (E))
		{
			while (d < E )
			{
				if (Ara[c] < Ara[d])
				{
					swap = Ara[c];
					Ara[c] = Ara[d];
					Ara[d] = swap;
				}
				t2 = t2*-1;

				if (d + 1 == E) {
					c++;
					d = c+1;
					break;
				}
				else{
					d = (d + 1);
					break;
				}

			}
			if (t2 == 1) break;
			//break;
		}

	}
}
void iSelectionSort() {

	int i, j, temp2, j2 = 0, h;


	for (i = 0; i < E; i++) {
		for (j = i + 1; j < E; j++) {
			if (Ara[i] < Ara[j]) {
				temp2 = Ara[i];
				Ara[i] = Ara[j];
				Ara[j] = temp2;
			}

			for (h = 0; h < E; h++){
				Ara2[j2][h] = Ara[h];
			}
			j2++;
		}

	}
}
void iOperationBox(double mx, double my){
	if (opr == 1 && op == 0 && mx>80 && mx<320 && my>80 && my < 200) {
		iStartSimulation();
		if (res == 1) iResumeTimer(0);
		op = 1;
	}
	else if (opr == 1 && op == 1 && mx>80 && mx<320 && my>80 && my < 200){
		op = -1;
		iPauseTimer(0);
	}
	else if (opr == 1 && op == -1 && mx>80 && mx<320 && my>80 && my < 200){
	
		iResumeTimer(0);
		op = 1;
	}
}
void iDrawOperationBox(){
	iSetColor(0,0,20);
	iFilledRectangle(50, 50, 300, 180);
	if (op == 0){
		iSetColor(13, 130, 146);
		iFilledRectangle(80, 80, 240, 120);
		iSetColor(0, 0, 40);
		iText(170, 135, "START");
	}
	if (op == 1){
		iSetColor(13, 133, 246);
		iFilledRectangle(80, 80, 240, 120);
		iSetColor(0, 0, 40);
		iText(170, 135, "PAUSE");
	}
	if (op == -1){
		iSetColor(65, 84, 250);
		iFilledRectangle(80, 80, 240, 120);
		iSetColor(0, 0, 40);
		iText(165, 135, "RESUME");
	}



}
void iDraw()
{	
	iClear();
	iSettingBox();
	if (z == -1) iShowElements(650 - 40 * t, 660);
	else iShowElements(665 - 40 * E, 350);
	if (M1 != 0 && M2 != 0 && E != 0 && i == E) opr = 1;
	if (opr == 1) iDrawOperationBox();
	if (M == 2) iBubbleSortD();
	else if (M == 1) iBubbleSortI();
	else if (M == 3) iSelectionSortI();
	else if (M == 4) iSelectionSortD();

}
/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes 
	
}
/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//printf("x = %d, y= %d\n",mx,my);
		if (mx > 1245 && my > 680) l =  l* ( - 1 );
		if (l == -1 && mx > 1245 && my > 630 && my < 680) z = z * (- 1);
		if (l == -1 && mx >1245 && my > 580 && my < 630) e = e * (-1);
		if (l == -1 && mx>1245 && my > 530 && my < 580) al = al*(-1);
		if (e == -1) iGetElement(mx, my);
		if (z == -1) { iGetInput(mx, my); e = 1; }
		if (al == -1) iAlgorithmBox(mx, my);
		if (or == -1) iOrderBox(mx, my);
		if (opr == 1) iOperationBox(mx,my);

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	

	}
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if (key == 'q'&&(c!=E-1))
	{
		//exit(0);
		t2 = t2*-1;

	}
	if (key == 'i')
	{
		//exit(0);
		M=1;

	}
	if (key == 'd')
	{
		//exit(0);
		M = 2;

	}
	if (key == 'I')
	{
		//exit(0);
		M = 3;
		d = 1;

	}
	if (key == 'D')
	{
		//exit(0);
		M = 4;
		d = 1;
	}

	if (key == 'p')
		{
			//exit(0);
			iPauseTimer(0);

		}
	if (key == 'r')
	{
		//exit(0);
		iResumeTimer(0);

	}

	//place your codes for other keys here
}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}

}
void f(){
	if (M==2) iBubbleSortD();
	else if (M == 1) iBubbleSortI();
	else if (M == 3) iSelectionSortI();
	else if (M == 4) iSelectionSortD();
	t2 = t2*-1;
	if (c == E - 1) {
		opr = 0;
		op = 0;
		M1 = 0;
		M2 = 0;
		t2 = 1;
		M = 0;
		res = 1;
		iSetColor(255, 255, 255);
		iText(500, 300, "The elements are now sorted");
		iPauseTimer(0);
	}

}
void g(){
	iSetTimer(1000, f);
	
}
int main()
{
	//place your own initialization codes here. 	
	g();
	iInitialize(1349, 732, " ");
	return 0;
}