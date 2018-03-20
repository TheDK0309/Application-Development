// function definition for screen functions
#include<stdio.h>
#include "screen.h"

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void gotoxy(short x, short y){
	printf("\033[%d;%dH",y,x);
	fflush(stdout);
}

void setColors(short fg, short bg){
	printf("\033[%d;%dm",fg, bg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[m");
	fflush(stdout);
}
void setXYColor(short x, short y, short fg, short bg){
	gotoxy(x, y);
	setColors(fg,bg);

}
void displayBar(short x,short y,short bottom){
	int i;
	for(i=y;i<bottom;i++){
		gotoxy(x,i);
		printf("%s",BAR);
	}
}
