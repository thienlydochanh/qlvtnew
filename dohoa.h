#include "dohoaconso.h"
//int MID[10][76];
void init_MID(int MID[][70]) 
{
	for(int i=0;i<180;i++)
	{
		for(int j=0;j<70;j++)
		{
			MID[i][j]=0;
		}
	}
}
	
 void Manhinhchinh()
 {
 	clrscr();
 	init_MID(MID);
 	button(2,2,1,15,5,2,0,"VAT TU",MID);
 	button(2,8,2,15,5,2,0,"NHAN VIEN",MID);
 	button(2,14,3,15,5,2,0,"HOA DON",MID);
 	button(2,20,4,15,5,2,0,"THONG KE",MID);
 	
 }
 void gdnhapvattu()
 {
 	Manhinhchinh();
 	button(2,2,1,15,5,2,12,"VAT TU",MID);
 	rectangle(18,2,150,15,2,0);
 	
    outtextxy1(20,5,"MA VT:");
 	taoo(26,3,30,3,11,MID);
 	outtextxy1(61,5,"TEN VT:");
 	taoo(68,3,30,3,12,MID);
 	outtextxy1(100,5,"SO LUONG:");
 	taoo(109,3,20,3,13,MID);
 	outtextxy1(131,5,"DON VI:");
 	taoo(138,3,20,3,14,MID);
 	
 	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
 	
 	
 }
 void bangvattu(int trang)
 {
 	char td[][30]={"STT","MA VAT TU","TEN"," SO LUONG","DON VI"};
 	int m[]={20,30,40,30,20};
 	bangcoSTT(18,18,m,td,11,5,3,101,MID);
 }
 void gdnhapnhanvien()
 {
 	Manhinhchinh();
 	button(2,8,2,15,5,2,12,"NHAN VIEN",MID);
 	rectangle(18,2,150,15,2,0);
 	outtextxy1(20,5,"MA NV:");
 	taoo(26,3,30,3,21,MID);
 	outtextxy1(61,5,"HO :");
 	taoo(68,3,40,3,22,MID);
 	outtextxy1(109,5,"TEN:");
 	taoo(115,3,20,3,23,MID);
 	outtextxy1(20,10,"CMND:");
 	taoo(26,8,30,3,24,MID);
 	outtextxy1(61,10,"PHAI(Nam/Nu):");
 	taoo(75,8,30,3,25,MID);
 	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	button(160,8,1112,8,3,2,0,"HUY",MID);
 	button(160,13,1113,8,3,2,0,"NEW",MID);
 	
 }
 void bangnhanvien(int trang)
 {
 	char td[][30]={"STT","MA NV","HO TEN"," CMND","PHAI"};
 	int m[]={10,20,40,30,20};
 	bangcoSTT(18,18,m,td,11,5,3,200,MID);
 }

 void gdhoahon()
 {
    
 	Manhinhchinh();
 	button(2,14,3,15,5,2,12,"HOA DON",MID);
 	rectangle(18,2,150,15,2,0);
 	
 	outtextxy1(20,5,"LOAI HD(X/N):");
 	taoo(34,3,30,3,31,MID);
 	outtextxy1(65,5,"NGAY LAP:");
 	taoo(75,3,30,3,31,MID);
 	
 	outtextxy1(106,5,"SO HD:");
 	taoo(115,3,30,3,33,MID);
 	
 	outtextxy1(20,10,"MA NV:");
 	taoo(34,8,30,3,34,MID);
 	
 	outtextxy1(65,10,"TEN NV:");
 	taoo(75,8,50,3,34,MID);
 	button(160,3,1111,8,3,2,0,"SAVE",MID);
 	outtextxy1(20,15,"MAVT");
 	taoo(24,13,15,3,35,MID);
 	outtextxy1(40,15,"TEN VT");
 	taoo(48,13,25,3,35,MID);
 	outtextxy1(40+35,15,"SL");
 	taoo(43+35,13,15,3,36,MID);
 	outtextxy1(59+35,15,"DG");
 	taoo(63+35,13,15,3,37,MID);
 	outtextxy1(80+35,15,"VAT");
 	taoo(85+35,13,15,3,38,MID);
 	button(139,13,39,10,3,2,0,"NHAP VT",MID);
 	button(150,13,40,7,3,2,0,"XOA",MID);
 	
// 	button(160,8,1112,8,3,2,0,"HUY",MID);
// 	button(160,13,1113,8,3,2,0,"NEW",MID);
 	
 }
void banghoadon()
 {
 	char td[][30]={"STT","MA VT","TEN"," SL ","DON GIA","VAT"};
 	int m[]={10,20,30,30,20,20};
 	bangcoSTT(18,18,m,td,21,6,2,301,MID);
 }
 void gdthongke()
 {	
    Manhinhchinh();
 	button(2,20,4,15,5,2,12,"THONG KE",MID);
 	rectangle(18,2,150,15,2,0);
 	
 	button(19,3,41,15,3,2,0,"HD_NHANVIEN",MID);
 	button(35,3,42,15,3,2,0,"DOANH THU",MID);
 	
 	
 }
 void gdthongke_NV()
 {
 	gdthongke();
 	button(19,3,41,15,3,2,12,"HD_NHANVIEN",MID);
 	outtextxy1(20,9,"MA NV : ");
 	taoo(30,7,20,3,411,MID);
 	taoo(50,7,30,3,411,MID);
 	outtextxy1(82,9,"TU NGAY: ");
 	taoo(92,7,20,3,412,MID);
 	outtextxy1(123,9,"DEN NGAY: ");
 	taoo(133,7,20,3,413,MID);
 	button(70,13,414,25,3,2,0,"XUAT DS HD",MID);
 	for (int i =20; i < 155; i++) {
		for (int j = 13; j < 13+3 ; j++) {
			MID[i][j]=414;
		}
	}
 	
 }
 void bangthongke_hdnv(int trang)
 {
 	char td[][30]={"SHD","DATE","LOAI"," MA VT ","TEN VT","SL","DG","VAT","TONG"};
 	int m[]={10,20,10,20,30,20,10,20,10};
 	bangKcoSTT(18,18,m,td,21,9,2,101,MID);
 }
 void gdthongke_doanhthu()
 {
 	gdthongke();
 	button(35,3,42,15,3,2,12,"DOANH THU",MID);
 	outtextxy1(20,9,"NAM TK : ");
 	taoo(30,7,20,3,421,MID);
 	button(70,13,414,25,3,2,0,"XUAT THONG KE",MID);
 
 }
 void bangthongkedoanhthu()
 {
 	char td[][30]={"STT","THANG ","DOANH THU"};
 	int m[]={20,30,40};
 	bangcoSTT(18,18,m,td,13,3,3,101,MID);
 }

