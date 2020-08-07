#include<iostream>
#include<string.h>
const int maxct=20;
using namespace std;
struct CTHoaDon{
	char MAVT[10];
	float SL;
	float DonGia;
	float VAT;
	bool TrangThai;
};
struct DS_CTHoaDon{
	int num;
	CTHoaDon list_CT[maxct];
};
void init_Cthoadon(DS_CTHoaDon &ds)
{
	ds.num=0;
	for(int i=0;i<maxct;i++)
	{
		memset(ds.list_CT[i].MAVT,0,10);
		ds.list_CT[i].DonGia=0;
		ds.list_CT[i].SL=0;
		ds.list_CT[i].VAT=0;
		ds.list_CT[i].TrangThai=0;
	}
}
CTHoaDon newdataCTHD(char MAVT[],float SL,float DonGia,float VAT,bool TrangThai)
{
	CTHoaDon temp;
	strcpy(temp.MAVT,MAVT);
	temp.SL=SL;
	temp.DonGia=DonGia;
	temp.VAT=VAT;
	temp.TrangThai=TrangThai;
	return temp;
	
}
void insert_CTHD(DS_CTHoaDon &ds, CTHoaDon data)
{
	ds.list_CT[ds.num]=data;
	ds.num++;
	return;
}
void SuaTTCTHD(DS_CTHoaDon &ds,char MAVT[], bool TT)
{
	for(int i=0;i<ds.num;i++)
	{
		if(strcmp(ds.list_CT[i].MAVT,MAVT)==0)
		{
			ds.list_CT[i].TrangThai=TT;
			return;
		}
	}
}

void Xoa1CTHD(DS_CTHoaDon &ds, int vitri){
	for(int i=vitri;i<ds.num-1;i++)
	{
		ds.list_CT[i]=ds.list_CT[i+1];
	}
	ds.num--;
}

void print_CTHD(CTHoaDon data,char TenVatTu[], int x, int y)
{
   char chrSL[7]="", chrDonGia[20]="", chrVAT[7]="";
   FloatToChar(chrSL, data.SL);
   FloatToChar(chrDonGia, data.DonGia);
   FloatToChar(chrVAT, data.VAT);
//   cout<<"Float: "<<chrFloat;
   outtextxy1(x+10+1,y,data.MAVT);
   outtextxy1(x+10+20+1,y,TenVatTu);
   outtextxy1(x+10+20+30+1,y,chrSL);
   outtextxy1(x+10+20+30+30+1,y,chrDonGia);
   outtextxy1(x+10+20+30+30+20+1,y,chrVAT);
}

void print_DSCTHD(DS_CTHoaDon dsCTHD, CayVatTu root, int x, int y)
{
	if(dsCTHD.num==0)
	return;
	for(int i=0;i<10;i++)
	{
		if(i>=dsCTHD.num)
		return;
		NodeVatTu *tmp = TimKiemVatTu(root, dsCTHD.list_CT[i].MAVT);
		print_CTHD(dsCTHD.list_CT[i],tmp->vatTu.TENVT,x,y);
		y=y+2;
	}
}

float CharToFloat(char ch[]);
void FloatToChar(char soTon[], float nFloat);
//NodeVatTu *TimKiemVatTu(CayVatTu cayVatTu, char MaVT[]);
void LayThongTin1CTHD(DS_CTHoaDon dsCTHD, CayVatTu root, int vitri, int size, char MAVT[], char chrSL[], char chrDonGia[], char chrVAT[]){
	if(vitri>=size) return;
	strcpy(MAVT, dsCTHD.list_CT[vitri].MAVT);
	FloatToChar(chrSL, dsCTHD.list_CT[vitri].SL);
	FloatToChar(chrDonGia, dsCTHD.list_CT[vitri].DonGia);
	FloatToChar(chrVAT, dsCTHD.list_CT[vitri].VAT);
//	
	outtextxy1(25,14,MAVT);
	outtextxy1(49,14,TimKiemVatTu(root, MAVT)->vatTu.TENVT);
	outtextxy1(43+36,14,chrSL);
	outtextxy1(63+36,14,chrDonGia);
	outtextxy1(85+36,14,chrVAT);
}
