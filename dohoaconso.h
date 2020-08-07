#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include<iostream>
using namespace std;

#define DEL 83
#define INS 82
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define Enter 13
#define ESC 27
#define BSP 8
#define SP 32

//const int WHITE=15;
struct Date{
	int ngay;
	int thang;
	int nam;
	int sgiay;
};
#define PASSWORD "abcdef"
//169-59 kich thuoc man hinh
//const int WHITE=15;
int MID[180][70];
char* Pwd () {
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
	system("cls");
}
void outtextxy1(int x, int y, char str[])
{
	gotoxy(x,y);
	std::cout<<str;	
	return;
}
void outtextxy(int x, int y, char c)
{
	gotoxy(x,y);
	std::cout<<c;	
	return;
}

void trodichuyen( int &X, int &Y, int &key, int MID[][70], char hd)
{
	if(hd==27)
	{
		key=9999;
		return;
		
	}

	else if(hd==80)
	{
	for(int i=Y;i<80;i++)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
//			cout<<X<<"  "<<Y<<" "<<key;
		return;
		}
	
	}
	for(int i=0;i<80;i++)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
//			cout<<X<<"  "<<Y<<" "<<key;
		return;
		}
	}
	
	}
	else if(hd==72)
	{
		for(int i=Y;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
//			cout<<X<<"  "<<Y<<" "<<key;
		return;
		}
	
	}
		for(int i=70;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
//			cout<<X<<"  "<<Y<<" "<<key;
		return;
		}
	
	}
	}
    else if(hd==77)
	{
	for(int i=X;i<170;i++)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	for(int i=0;i<170;i++)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	}
	else if(hd==75)
	{
		for(int i=X;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	for(int i=170;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	}
	else
	return;
	

}
void trodichuyentraiphai( int &X, int &Y, int &key, int MID[][70], char hd)
{
	if(hd==27)
	{
		key=27;
		return;
		
	}
	  if(hd==77)
	{
	for(int i=X;i<170;i++)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	for(int i=0;i<170;i++)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	}
	if(hd==75)
	{
		for(int i=X;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	for(int i=170;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[i][Y]&&MID[i][Y]!=0)
		{
			key=MID[i][Y];
			X=i;
		return;
		}
	
	}
	}
}
void trodichuyenlenxuong( int &X, int &Y, int &key, int MID[][70], char hd)
{
	if(hd==80)
	{
	for(int i=Y;i<80;i++)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
		return;
		}
	
	}
	for(int i=0;i<80;i++)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
		return;
		}
	}
	
	}
	else if(hd==72)
	{
		for(int i=Y;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
		return;
		}
	
	}
		for(int i=80;i>0;i--)
	{
		SetColor(5);
		if(key!=MID[X][i]&&MID[X][i]!=0)
		{
			key=MID[X][i];
			Y=i;
		return;
		}
	
	}
	}
	else
	return;
}
void DelScreeen(int x, int y, int cd, int cr) {
	ShowCur(0);
	SetColor(7);
	for (int i = y; i < cr + y; i++) {
		for (int j = x; j < x + cd; j++) {
			gotoxy(j, i);
			cout << " ";
		}
	}
}

void rectangle(int x, int y, int m, int n, int mau,int kieu) {
	int i, j;
	if(kieu%2==1)
	{
	SetColor(mau);
	for (i = x; i <= x + m; i++) {
		for (j = y; j <= y + n; j++) {
			if (i == x || i == x + m) {
				if (j == y && i != x + m)
					outtextxy(i, j, 201); //||-
				else if (j == y && i != x)
					outtextxy(i, j, 187); // -||
				else if (j == y + n && i != x + m)
					outtextxy(i, j, 200);// l
				else if (j == y + n && i != x)
					outtextxy(i, j, 188);// l nguoc
				else outtextxy(i, j, 186); // ||
			}
			else if (j == y || j == y + n)
				outtextxy(i, j, 205);
		}
	}	
	}
	else
	{
		SetColor(mau);
	for (i = x; i <= x + m; i++) {
		for (j = y; j <= y + n; j++) {
			if (i == x || i == x + m) {
				if (j == y && i != x + m)
					outtextxy(i, j, 218); //||-
				else if (j == y && i != x)
					outtextxy(i, j, 191); // -||
				else if (j == y + n && i != x + m)
					outtextxy(i, j, 192);// l
				else if (j == y + n && i != x)
					outtextxy(i, j, 217);// l nguoc
				else outtextxy(i, j, 179); // ||
			}
			else if (j == y || j == y + n)
				outtextxy(i, j,196);
		}
	}	
	}
	SetBGColor(0);
	SetColor(15);
}

void button(int x, int y,int ID, int cd, int cr, int color,int colorw, char str[],int MID[][70])
{
	ShowCur(0);
//	SetbkColor(color);
	SetBGColor(color);
	for (int i = y; i < cr + y; i++) {
		for (int j = x; j < x + cd; j++) {
			MID[j][i]=ID;
			gotoxy(j, i);
			cout << " ";
		}
	}
	SetColor(colorw);
	outtextxy1(x+(cd-strlen(str))/2,y+cr/2,str);
	gotoxy(1,1);
	SetBGColor(0);
	SetColor(15);
}
void taoo(int x, int y, int cd, int cr, int ID,int MID[][70])
{
	rectangle(x,y,cd,cr,15,0);
	for(int i=x;i<x+cd;i++)
	for(int j=y;j<y+cr;j++)
	{
		MID[i][j]=ID;
	}
	
}
void taodong(int x, int y,int m[],int cr, int sc,int ID,int MID[][70])
{
	for(int i=0;i<sc;i++)
	{
		taoo(x,y ,m[i],cr,ID,MID);
		x=x+m[i];
	}
}
void bangcoSTT( int x, int y, int m[], char td[][30],int sh, int sc,int cr,int ID,int MID[][70])
{ 
    int t=y;
	for(int i=0;i<sh;i++)
	{
	
		taodong(x,y,m,cr,sc,ID+i,MID);
			if(i!=0)
		{
			char c[4];
			memset(c,0,4);
			itoa(i,c,10);
			outtextxy1(x+2,y+1,c);
		}
		y=y+cr;
		
	}
	for(int i=0;i<sc;i++)
	{
		outtextxy1(x+1,t+1,td[i]);
		x=x+m[i];
	}
}
void bangKcoSTT(int x, int y, int m[], char td[][30],int sh, int sc,int cr,int ID,int MID[][70])
{
	 int t=y;
	for(int i=0;i<sh;i++)
	{
	
		taodong(x,y,m,cr,sc,ID+i,MID);
			if(i!=0)
		{
			
		}
		y=y+cr;
		
	}
		for(int i=0;i<sc;i++)
	{
		outtextxy1(x+1,t+1,td[i]);
		x=x+m[i];
	}

}
void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext, int &xn, int &yn)
{
	
	unsigned int l = strlen(s);
	xn=px;
	yn=py;
	outtextxy1(px,py,s);
	ShowCur(1);
	while(1)
	{

		if(kbhit())
		{			
		char c = getch();
		if(c==75||c==77||c==80||c==72||c == ENTER||c==27)
			    {
			    	outtextxy1(px,py,s);
			    	trodichuyen(xn,yn,IDnext,MID,c);
			    	gotoxy(5,50);
			    	cout<<IDnext;
			    	return;
				}
		else if(l<max)
			{   
			    
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
			
				if(l>0) if(s[l-1]!=' ' && c ==32)
				{
					s[l] = c;
					l++;
					s[l]=0;
				}

				outtextxy1(px,py,s);	
			}
			if(c == BSP&&l>0)
			{
				outtextxy1(px,py,s);	
				s[l-1] =' ';
				s[l]=0;
				l--;
			}
			outtextxy1(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
//	if((mx!=-1)&&(my!=-1)) {
//	IDnext=MID[mx][my];
//	}
}
void Scannerdate(char s[],int max, int px ,int py,int ID,int &IDnext, int &xn, int &yn)
{
	
	unsigned int l = strlen(s);
	xn=px;
	yn=py;
	outtextxy1(px,py,s);
	ShowCur(1);
	while(1)
	{

		if(kbhit())
		{			
		char c = getch();
		if(c==75||c==77||c==80||c==72||c == ENTER||c==27)
			    {
			    	outtextxy1(px,py,s);
			    	trodichuyen(xn,yn,IDnext,MID,c);
			    	gotoxy(5,50);
			    	cout<<IDnext;
			    	return;
				}
		else if(l<max)
			{   
			    
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
					if(l==2||l==5)
			    {
			    	s[l]='/';
			    	l++;
			    	s[l]=0;
				}
				}
			
				outtextxy1(px,py,s);	
			}
			if(c == BSP&&l>0)
			{
				outtextxy1(px,py,s);	
				s[l-1] =' ';
				s[l]=0;
				l--;
			}
			outtextxy1(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
//	if((mx!=-1)&&(my!=-1)) {
//	IDnext=MID[mx][my];
//	}
}
 void nutchucnang(int loai)
 {
 	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
 	if(loai==0)
 	{
 	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
	}
	else if(loai==1)
	{
	button(160,3,1111,8,3,2,12,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
	}
	else if(loai==2)
	{
	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,12,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
	}
	else if(loai==3)
	{
	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,12,"NEW",MID);
	}
 }
bool buocdem(int &x, int &y, int &key, int cn)
{
    char c=0;
	 while(1)
	{
//		cout<<"1";
		if(kbhit())
		{
		c=getch();
		if(c==13)
	    {
	    	nutchucnang(cn);
			return true;	
		}
				
		else
		{
			trodichuyen(x,y,key,MID,c);
			nutchucnang(0);
			return false;
		}
	   }
	}
}
bool buocdem1(int &x, int &y, int &key, int cn)
{
    char c=0;
	 while(1)
	{
//		cout<<"1";
		if(kbhit())
		{
		c=getch();
		if(c==13)
	    {
//	    	nutchucnang(cn);
			return true;	
		}
				
		else
		{
			trodichuyen(x,y,key,MID,c);
//			nutchucnang(0);
			return false;
		}
	   }
	}
}
int trungay(Date t1, Date t2) {
        if (t1.thang < 3) {
            t1.nam--;
            t1.thang += 12;
        }
        if (t2.thang < 3) {
            t2.nam--;
            t2.thang += 12;
        }
        return 365*t1.nam + t1.nam/4 - t1.nam/100 + t1.nam/400 + (153*t1.thang - 457)/5 + t1.ngay - 306
		     -(365*t2.nam + t2.nam/4 - t2.nam/100 + t2.nam/400 + (153*t2.thang - 457)/5 + t2.ngay - 306);
    }
int ngay(int year, int month, int day) {
        if (month < 3) {
            year--;
            month += 12;
        }
        return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
    }
