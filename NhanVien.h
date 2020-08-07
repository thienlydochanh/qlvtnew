#include "HoaDon.h"
#include <fstream>
const int MaxNV =500;
using namespace std;
struct NhanVien{
	int MANV;
	char Ho[30];
	char Ten[20];
	char Phai[4];
	char CMND[13];
	DS_HD list_HD;
};
struct DS_NhanVien{
	int num;
	NhanVien *DS[MaxNV];
};
void init_DSNV(DS_NhanVien &ds)
{
	ds.num =0;
	for(int i=0;i<MaxNV;i++)
	{
		ds.DS[i]=NULL;
	}
}
NhanVien newdata_NV(int MANV,char Ho[],char Ten[],char Phai[],char CMND[])
{
	NhanVien temp;
	temp.MANV=MANV;
	strcpy(temp.Ho,Ho);
	strcpy(temp.Ten,Ten);
	strcpy(temp.Phai,Phai);
	strcpy(temp.CMND,CMND);
	init_DSHD(temp.list_HD);
	return temp;
}
void insert_NV(DS_NhanVien &ds, NhanVien data)
{
	ds.DS[ds.num]=new NhanVien;
	*ds.DS[ds.num]=data;
	ds.num++;
	return;
}
void sua_NV(DS_NhanVien &ds, NhanVien data, int vt)
{
	*ds.DS[vt]=data;
	return;
}
int timkiem_NV_vt(DS_NhanVien &ds, int MaNV)
{ 
//cout<<" mnv "<<MaNV;
	if(ds.num==0) return -1;
	for(int i=0;i<ds.num;i++)
	{
//		cout<<" duyet r";
		if(ds.DS[i]->MANV==MaNV)
		return i;
	}
	return -1;
}
void del_NV(DS_NhanVien &ds, int vt)
{
	if(ds.num==0||vt==-1||vt>=ds.num) return;
	for(int i=vt;i<ds.num-1;i++)
	{
		ds.DS[i]=ds.DS[i+1];
	}
	ds.DS[ds.num-1]=NULL;
	delete ds.DS[ds.num-1];
	ds.num--;
	return;
}
bool kiemtratrungnhanvien(DS_NhanVien ds, char CMND[13],int MANV)
{
	for(int i=0;i<ds.num;i++)
	{
		if(strcmp(ds.DS[i]->CMND,CMND)==0||ds.DS[i]->MANV==MANV)
		{
			return true;
		}
	}
	return false;
}
void print_NV(NhanVien data,int x, int y)
{
   char  cMNV[16]="";
   char HoTen[40]="";
   strcpy(HoTen,data.Ho);
   strcat(HoTen," ");
   strcat(HoTen,data.Ten);
   itoa(data.MANV,cMNV,10);
   outtextxy1(x+10+1,y,cMNV);
   outtextxy1(x+10+20+1,y,HoTen);
   outtextxy1(x+10+20+40+1,y,data.CMND);
   outtextxy1(x+10+20+40+30+1,y,data.Phai); 
}
void GhiNhanVienVaoFile(char tenfile[], DS_NhanVien &dsNhanVien){
	fstream f;
	f.open(tenfile, ios::out);
	
	f<<dsNhanVien.num<<endl;
	for(int i=0; i<dsNhanVien.num; i++){
		f<<dsNhanVien.DS[i]->MANV<<endl;
		f<<dsNhanVien.DS[i]->Ho<<endl;
		f<<dsNhanVien.DS[i]->Ten<<endl;
		f<<dsNhanVien.DS[i]->Phai<<endl;
		f<<dsNhanVien.DS[i]->CMND<<endl;
		
		f<<dsNhanVien.DS[i]->list_HD.n<<endl;
		NODE_HD *hoaDon = dsNhanVien.DS[i]->list_HD.pHead;
		while(hoaDon!=NULL){
			f<<hoaDon->data.SoHD<<endl;
			f<<hoaDon->data.NgayLap.ngay<<endl;
			f<<hoaDon->data.NgayLap.thang<<endl;
			f<<hoaDon->data.NgayLap.nam<<endl;
			f<<hoaDon->data.NgayLap.sgiay<<endl;
			f<<hoaDon->data.Loai<<endl;
			
			f<<hoaDon->data.ct.num<<endl;
			for(int j=0; j<hoaDon->data.ct.num; j++){
				f<<hoaDon->data.ct.list_CT[j].MAVT<<endl;
				f<<hoaDon->data.ct.list_CT[j].SL<<endl;
				f<<hoaDon->data.ct.list_CT[j].DonGia<<endl;
				f<<hoaDon->data.ct.list_CT[j].VAT<<endl;
				f<<hoaDon->data.ct.list_CT[j].TrangThai<<endl;
			}
			
			hoaDon = hoaDon->pnext;
		}
	}
	
	f.close();
}
void DocNhanVienTuFile(char tenfile[], DS_NhanVien &dsNhanVien){
	fstream f;
	f.open(tenfile, ios::in);
	
	int n=0;
	f>>n;
	f.ignore();
	NhanVien tamNhanVien;
	for(int i=0; i<n; i++){
		f>>tamNhanVien.MANV;
		f.ignore();
		f.getline(tamNhanVien.Ho, sizeof(tamNhanVien.Ho), '\n');
		cout<<tamNhanVien.Ho;
		f.getline(tamNhanVien.Ten, sizeof(tamNhanVien.Ten), '\n');
		cout<<tamNhanVien.Ten;
		f.getline(tamNhanVien.Phai, sizeof(tamNhanVien.Phai), '\n');
		f.getline(tamNhanVien.CMND, sizeof(tamNhanVien.CMND), '\n');
		
		init_DSHD(tamNhanVien.list_HD);
		insert_NV(dsNhanVien, tamNhanVien);
//			print_NV(tamNhanVien,18,18);
		int HDn=0;
		f>>HDn;
		f.ignore();
		HOADON tamHoaDon;
		for(int j=0; j<HDn; j++){
			f.getline(tamHoaDon.SoHD, sizeof(tamHoaDon.SoHD), '\n');
			
			f>>tamHoaDon.NgayLap.ngay;
			f.ignore();
			f>>tamHoaDon.NgayLap.thang;
			f.ignore();
			f>>tamHoaDon.NgayLap.nam;
			f.ignore();
			f>>tamHoaDon.NgayLap.sgiay;
			f.ignore();
			f>>tamHoaDon.Loai;
			f.ignore();
		
			init_Cthoadon(tamHoaDon.ct);
//			insert_HD(dsNhanVien.DS[dsNhanVien.num-1]->list_HD,tamHoaDon);
			f>>tamHoaDon.ct.num;// du dau end
			f.ignore();
			for(int j=0; j<tamHoaDon.ct.num; j++){
				f.getline(tamHoaDon.ct.list_CT[j].MAVT, sizeof(tamHoaDon.ct.list_CT[j].MAVT), '\n');
//				cout<<endl<<"MaVT Test: "<<tamHoaDon.ct.list_CT[j].MAVT<<endl;
				f>>tamHoaDon.ct.list_CT[j].SL;
				f.ignore();
				f>>tamHoaDon.ct.list_CT[j].DonGia;
				f.ignore();
				f>>tamHoaDon.ct.list_CT[j].VAT;
				f.ignore();
				f>>tamHoaDon.ct.list_CT[j].TrangThai;
				f.ignore();
//				insert_CTHD(dsNhanVien.DS[dsNhanVien.num-1]->list_HD.pTail->data.ct,tamHoaDon.ct.list_CT[j]);
			}
			
//			cout<<endl<<"MaVT Test: "<<tamHoaDon.ct.list_CT[0].MAVT<<endl;
//			cout<<endl<<"MaVT Test: "<<tamHoaDon.ct.list_CT[0].SL<<endl;
//			system("pause");
			insert_HD(dsNhanVien.DS[dsNhanVien.num-1]->list_HD, tamHoaDon);
			
//			insert_NV(dsNhanVien, tamNhanVien);
//			print_NV(tamNhanVien,18,18);
//			Sleep(10000);
		}
	}
	
	f.close();
}

void print_DSNV(DS_NhanVien &ds, int x, int y, int trang)
{
	if(ds.num==0)
	return;
	for(int i=0;i<ds.num;i++)
	{
		for(int j=0;j<ds.num;j++)
		{
			if(strcmp(ds.DS[i]->Ten,ds.DS[j]->Ten)<0)
			{
				NhanVien *tam=ds.DS[i];
				ds.DS[i]=ds.DS[j];
				ds.DS[j]=tam;
			}
			if(strcmp(ds.DS[i]->Ten,ds.DS[j]->Ten)==0)
			{
				if(strcmp(ds.DS[i]->Ho,ds.DS[j]->Ho)<0)
				{
				NhanVien *tam=ds.DS[i];
				ds.DS[i]=ds.DS[j];
				ds.DS[j]=tam;
				}
				
			}
			
		}
	}
	for(int i=0;i<10;i++)
	{
		if((trang-1)*10+i>=ds.num)
		return;
		print_NV(*ds.DS[(trang-1)*10+i],x,y);
		y=y+3;
	}
}

NhanVien *TimNhanVien(DS_NhanVien &dsNhanVien, int MANV){
	for(int i=0; i<dsNhanVien.num; i++){
		if(dsNhanVien.DS[i]->MANV==MANV) return dsNhanVien.DS[i];
	}
	return NULL;
}

NODE_HD *TimTatCaHoaDon(DS_NhanVien &dsNhanVien, char SOHD[], NhanVien &nhanVien){
	for(int i=0; i<dsNhanVien.num; i++){
		NODE_HD *tmp = dsNhanVien.DS[i]->list_HD.pHead;
		while(tmp!=NULL){
			if(strcmp(tmp->data.SoHD, SOHD)==0){
				nhanVien = *dsNhanVien.DS[i];
				return tmp;
			}
			tmp=tmp->pnext;
		}
	}
	return NULL;
}

bool TimTatCaVatTu(DS_NhanVien &dsNhanVien, char MaVT[]){
	for(int i=0; i<dsNhanVien.num; i++){
		NODE_HD *tmp = dsNhanVien.DS[i]->list_HD.pHead;
		while(tmp!=NULL){
			for(int i=0; i<tmp->data.ct.num; i++){
				if(strcmp(tmp->data.ct.list_CT[i].MAVT, MaVT)==0){
					return true;
				}
			}
			tmp=tmp->pnext;
		}
	}
	return false;
}

void printdsHD(int x, int y, NhanVien nv, CayVatTu t, Date t1, Date t2)
{
	int dem=0;
	for(NODE_HD *k=nv.list_HD.pHead;k!=NULL;k=k->pnext)
	{
		if(ngay(t2.nam,t2.thang,t2.ngay)>=ngay(k->data.NgayLap.nam,k->data.NgayLap.thang,k->data.NgayLap.ngay)&&ngay(t1.nam,t1.thang,t1.ngay)<=ngay(k->data.NgayLap.nam,k->data.NgayLap.thang,k->data.NgayLap.ngay))
		{
			print_CT_HD(k->data,t,x,y,dem);
//			y=y+dem+1;
//           y=y+2;
		}
		
	}

}

