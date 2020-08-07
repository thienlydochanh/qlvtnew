#include "CT_HoaDon.h"
#include <ctime>
//#include "VatTu.h"
using namespace std;

struct HOADON{
	char SoHD[20];
	Date NgayLap;
	char Loai;
	DS_CTHoaDon ct;
};
struct NODE_HD{
	HOADON data;
	NODE_HD *pnext;
};
struct DS_HD{
	NODE_HD *pHead;
	NODE_HD *pTail;
	int n=0;
};
void init_DSHD(DS_HD &ds)
{
	ds.pHead=ds.pTail=NULL;
}
HOADON newdata_HD(char SoHD[],Date NgayLap, char Loai)
{
	HOADON temp;
	strcpy(temp.SoHD,SoHD);
	temp.NgayLap=NgayLap;
    temp.Loai=Loai;
    init_Cthoadon(temp.ct);
    return temp;
}
NODE_HD *newNODE_HD(HOADON data)
{
	NODE_HD *p =new NODE_HD;
	p->data=data;
	p->pnext=NULL;
	return p;
}
void insert_HD(DS_HD &ds, HOADON data)
{
	NODE_HD *p=newNODE_HD(data);
	if(ds.pHead==NULL)
	{
		ds.pHead=p;
		ds.pTail=p;
	}
	else
	{
		ds.pTail->pnext=p;
		ds.pTail=p;
	}
	ds.n++;
}
void del_HD(DS_HD &ds, char SoHD[])
{
	if(ds.pHead==NULL)
	return;
	if(strcmp(ds.pHead->data.SoHD,SoHD)==0)
	{
			NODE_HD *t=ds.pHead;
			ds.pHead=t->pnext;
			delete t;
			ds.n--;
			return;
	}
	if(strcmp(ds.pTail->data.SoHD,SoHD)==0)
	{
			NODE_HD *t=ds.pTail;
			for(NODE_HD *k=ds.pHead;k!=NULL;k=k->pnext)
			{
		       if(k->pnext->pnext==NULL)
		       {
		       	ds.pTail=k;
		       	delete t;
		       	ds.n--;
		       	return;
			   }
	    	}
	}
			
			
	for(NODE_HD *k=ds.pHead;k!=NULL;k=k->pnext)
	{
		if(strcmp(k->data.SoHD,SoHD)==0)
		{
			NODE_HD *t=k->pnext;
			k->data=k->pnext->data;
			k->pnext=k->pnext->pnext;
			delete t;
			ds.n--;
			return;
		}
	}
	return;
}

NODE_HD *TimHoaDon(DS_HD &list, char SOHD[]){
	NODE_HD *tmp = list.pHead;
	while(tmp!=NULL){
		if(strcmp(tmp->data.SoHD, SOHD)) return tmp;
		tmp=tmp->pnext;
	}
	return NULL;
}

void DoDSLKVaoMang(DS_HD &list, HOADON *&hoaDon){
	hoaDon = new HOADON[list.n];
	NODE_HD *tmp = list.pHead;
	int i=0;
	while(tmp!=NULL){
		hoaDon[i] = tmp->data;
		tmp=tmp->pnext;
	}
}

Date GetNow(char chrDate[]){
	Date dNow;
	time_t now = time(0);
	dNow.sgiay = now;
 	tm *ltm = localtime(&now);
 	dNow.nam = 1900 + ltm->tm_year;
 	dNow.thang = 1 + ltm->tm_mon;
 	dNow.ngay = ltm->tm_mday;
 	
 	strcpy(chrDate,"");
 	char tmpString[13]="";
 	itoa(dNow.ngay, tmpString, 10);
 	strcpy(chrDate,tmpString);
 	strcat(chrDate,"-");
 	strcpy(tmpString,"");
 	itoa(dNow.thang, tmpString, 10);
 	strcat(chrDate,tmpString);
 	strcat(chrDate,"-");
 	strcpy(tmpString,"");
 	itoa(dNow.nam, tmpString, 10);
 	strcat(chrDate,tmpString);
 	
 	return dNow;
}
Date chuyenchuoithoigian(char s[])
{
	Date time;
	int l= strlen(s);
	time.ngay=(s[0]-48)*10+s[1]-48;
	time.thang=(s[3]-48)*10+s[4]-48;
	time.nam=(s[6]-48)*1000+(s[7]-48)*100+(s[8]-48)*10+s[9]-48;
	time.sgiay=0;
	return time;

}
void print_CT_HD(HOADON data,CayVatTu t,int &x, int &y,int &dem)
{
	dem=dem+data.ct.num;
//	ds=data.ct;
	
	for(int i=0;i<data.ct.num;i++)
	{
	NodeVatTu *node=TimKiemVatTu(t,data.ct.list_CT[i].MAVT);
	outtextxy1(x,y,data.SoHD);
	char ngay[15]="", ng[10]="";
	itoa(data.NgayLap.ngay,ngay,10);
	strcat(ngay,"/");
	itoa(data.NgayLap.thang,ng,10);
	strcat(ngay,ng);
	strcat(ngay,"/");
	itoa(data.NgayLap.nam,ng,10);
	strcat(ngay,ng);
	outtextxy1(x+10,y,ngay);
	outtextxy(x+10+20,y,data.Loai);
	outtextxy1(x+10+20+10,y,data.ct.list_CT[i].MAVT);
	outtextxy1(x+10+20+10+20,y,node->vatTu.TENVT);
	FloatToChar(ng, data.ct.list_CT[i].SL);
//	ftoa(data.ct.list_CT[i].SL,ng,10);
	outtextxy1(x+10+20+10+20+30,y,ng);
	FloatToChar(ng, data.ct.list_CT[i].DonGia);
//	ftoa(data.ct.list_CT[i].DonGia,ng,2);
	outtextxy1(x+10+20+10+20+30+20,y,ng);
   	FloatToChar(ng, data.ct.list_CT[i].VAT);
//	ftoa(data.ct.list_CT[i].VAT,ng,2);
	outtextxy1(x+10+20+10+20+30+20+10,y,ng);
	float tong=data.ct.list_CT[i].SL*data.ct.list_CT[i].DonGia*(1+data.ct.list_CT[i].VAT/100);
//	ftoa(tong,ng,2);
	FloatToChar(ng,tong);
	outtextxy1(x+10+20+10+20+30+20+10+20,y,ng);
     y=y+2;
	}
}

