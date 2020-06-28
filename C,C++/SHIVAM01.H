#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void Intro()
{
	char ch[] = {"WELCOME TO DATA THEORY"};
	randomize();
	for(int i = 0; i < 1; i++)
	{
		int sp = 0;

		for(int j = 0; j < 78-strlen(ch)-1; j++)
		{
			for(int k = sp; k > 0; k--)
				cout << " ";
			sp++;
			int randcolor = random(15) + 1;
			textcolor(randcolor);
			puts(ch);
			delay(100);
			clrscr();
		}
		clrscr();
		sp = 0;
		for(j = 0; j < 50-strlen(ch)-1; j++)
		{
			clrscr();
			for(int k = sp; k > 0; k--)
				cout << " ";
			sp++;
			int randcolor = random(15) + 1;
			textcolor(randcolor);
			puts(ch);
			delay(100);
		}
	}
}