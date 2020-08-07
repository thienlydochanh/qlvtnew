#include<iostream>
#include<string.h>
#include <fstream>
#include <cmath>
using namespace std;

struct Vattu{
	char MAVT[10]="";
	char TENVT[50]="";
	char DVT[20]="";
	float ton;
};

struct NodeVatTu{
	Vattu vatTu;
	NodeVatTu *left=NULL;
	NodeVatTu *right=NULL;
};

struct CayVatTu{
	NodeVatTu *root=NULL;
	int soluong=0;
};

Vattu TaoVatTuMoi(char MaVT[], char TenVT[], char DVT[], float ton){
	Vattu vatTuTam;
	
	strcpy(vatTuTam.MAVT, MaVT);
	strcpy(vatTuTam.TENVT, TenVT);
	strcpy(vatTuTam.DVT, DVT);
	vatTuTam.ton = ton;
	
	return vatTuTam;
}

NodeVatTu *TaoNodeVatTuMoi(Vattu vatTu){
	NodeVatTu *nodeVatTuTam = new NodeVatTu;
	
	nodeVatTuTam->vatTu = vatTu;
	nodeVatTuTam->left=NULL;
	nodeVatTuTam->right=NULL;
	
	return nodeVatTuTam;
}

void ThemNodeVaoCay(CayVatTu &cayVatTu, NodeVatTu *nodeVatTu){
	if(cayVatTu.root==NULL){
		cayVatTu.root = nodeVatTu;
	}
	else{
		NodeVatTu *tam = cayVatTu.root;
		NodeVatTu *truoctam = tam;
		
		while(tam!=NULL){
			truoctam=tam;
			if(strcmp(nodeVatTu->vatTu.MAVT, tam->vatTu.MAVT)<0){
				tam=tam->left;
			}
			else if(strcmp(nodeVatTu->vatTu.MAVT, tam->vatTu.MAVT)>0){
				tam=tam->right;
			}
		}
		
		if(strcmp(nodeVatTu->vatTu.MAVT, truoctam->vatTu.MAVT)<0){
			truoctam->left=nodeVatTu;
		}
		else if(strcmp(nodeVatTu->vatTu.MAVT, truoctam->vatTu.MAVT)>0){
			truoctam->right=nodeVatTu;
		}
	}
	cayVatTu.soluong++;
}

NodeVatTu *TimKiemVatTu(CayVatTu cayVatTu, char MaVT[]){
	NodeVatTu *tam = cayVatTu.root;
	while(tam!=NULL){
		if(strcmp(tam->vatTu.MAVT, MaVT)==0){
			return tam;
		}
		else if(strcmp(MaVT, tam->vatTu.MAVT)<0){
			tam=tam->left;
		}
		else if(strcmp(MaVT, tam->vatTu.MAVT)>0){
			tam=tam->right;
		}
	}
	return NULL;
}

void HieuChinhVatTuTheoMa(CayVatTu &cayVatTu, char MaVT[], char TenVTMoi[], char DVTMoi[]){
	NodeVatTu *tam = TimKiemVatTu(cayVatTu, MaVT);
	if(tam!=NULL){
		strcpy(tam->vatTu.TENVT, TenVTMoi);
		strcpy(tam->vatTu.DVT, DVTMoi);
	}
}

void XoaNodeKhoiCayTheoMa(CayVatTu &cayVatTu, char MaVT[]){
	if(strcmp(cayVatTu.root->vatTu.MAVT, MaVT)==0){
		if(cayVatTu.root->left==NULL && cayVatTu.root->right==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = NULL;
			delete xoa;
		}
		else if(cayVatTu.root->left==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = cayVatTu.root->right;
			delete xoa;
		}
		else if(cayVatTu.root->right==NULL){
			NodeVatTu *xoa = cayVatTu.root;
			cayVatTu.root = cayVatTu.root->left;
			delete xoa;
		}
		else{
			NodeVatTu *truocThayThe;
			NodeVatTu *thayThe = cayVatTu.root->right;
			truocThayThe = cayVatTu.root;
			
			while(thayThe->left!=NULL){
				truocThayThe = thayThe;
				thayThe = thayThe->left;
			}
			
			if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)<0){
				cayVatTu.root->vatTu = thayThe->vatTu;
				if(thayThe->right!=NULL) truocThayThe->left = thayThe->right;
				else truocThayThe->left=NULL;
			}
			else if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)>0){
				cayVatTu.root->vatTu = thayThe->vatTu;
				if(thayThe->right!=NULL) truocThayThe->right = thayThe->right;
				else truocThayThe->right = NULL;
			}
			delete thayThe;
		}
	}
	else{
		NodeVatTu *xoa = cayVatTu.root;
		NodeVatTu *truocXoa = cayVatTu.root;
		
		while(strcmp(xoa->vatTu.MAVT, MaVT)!=0 && xoa!=NULL){
			truocXoa = xoa;
			if(strcmp(MaVT, xoa->vatTu.MAVT)<0){
				xoa=xoa->left;
			}
			else if(strcmp(MaVT, xoa->vatTu.MAVT)>0){
				xoa = xoa->right;
			}
		}
		
		if(xoa!=NULL){
			if(xoa->left==NULL && xoa->right==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = NULL;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = NULL;
				}
				delete xoa;
			}
			else if(xoa->left==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = xoa->right;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = xoa->right;
				}
				delete xoa;
			}
			else if(xoa->right==NULL){
				if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)<0){
					truocXoa->left = xoa->left;
				}
				else if(strcmp(xoa->vatTu.MAVT, truocXoa->vatTu.MAVT)>0){
					truocXoa->right = xoa->left;
				}
				delete xoa;
			}
			else{
				NodeVatTu *truocThayThe;
				NodeVatTu *thayThe = xoa->right;
				truocThayThe = xoa;
				
				while(thayThe->left!=NULL){
					truocThayThe = thayThe;
					thayThe = thayThe->left;
				}
				
				if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)<0){
					xoa->vatTu = thayThe->vatTu;
					if(thayThe->right!=NULL) truocThayThe->left = thayThe->right;
					else truocThayThe->left = NULL;
				}
				else if(strcmp(thayThe->vatTu.MAVT, truocThayThe->vatTu.MAVT)>0){
					xoa->vatTu = thayThe->vatTu;
					if(thayThe->right!=NULL) truocThayThe->right = thayThe->right;
					else truocThayThe->right = NULL;
				}
				
				delete thayThe;
			}
		}
	}
	cayVatTu.soluong--;
}

void DeQuyXoaNode(NodeVatTu *node){
	if(node!=NULL){
		DeQuyXoaNode(node->left);
		DeQuyXoaNode(node->right);
		delete node;
	}
}

void XoaToanBoCay(CayVatTu &cayVatTu){
	DeQuyXoaNode(cayVatTu.root);
	cayVatTu.root=NULL;
	cayVatTu.soluong=0;
}

void DuyetNodeGhiVaoFile(fstream &f, NodeVatTu *node){
	if(node!=NULL){
		DuyetNodeGhiVaoFile(f, node->left);
		DuyetNodeGhiVaoFile(f, node->right);
		f<<node->vatTu.MAVT<<endl;
		f<<node->vatTu.TENVT<<endl;
		f<<node->vatTu.DVT<<endl;
		f<<node->vatTu.ton<<endl;
	}
}

void GhiVatTuVaoFile(char tenfile[], CayVatTu cayVatTu){
	fstream f;
	
	f.open(tenfile, ios::out);
	
	if(f!=NULL){
		f<<cayVatTu.soluong<<endl;
		DuyetNodeGhiVaoFile(f, cayVatTu.root);
	}
	
	f.close();
}

void DocVatTuTuFile(char tenfile[], CayVatTu &cayVatTu){
	fstream f;
	
	f.open(tenfile, ios::in);
	
	if(f!=NULL){
		XoaToanBoCay(cayVatTu);
		int n=0;
		f>>n;
		f.ignore();
		Vattu tam;
		for(int i=0; i<n; i++){
			f.getline(tam.MAVT, sizeof(tam.MAVT), '\n');
			f.getline(tam.TENVT, sizeof(tam.TENVT), '\n');
			f.getline(tam.DVT, sizeof(tam.DVT), '\n');
			f>>tam.ton;
			f.ignore();
			ThemNodeVaoCay(cayVatTu, TaoNodeVatTuMoi(tam));
		}
	}
	
	f.close();
}

void DuyetNode(NodeVatTu *node, Vattu *vt, int &i){
	if(node!=NULL){
		DuyetNode(node->left, vt, i);
		vt[i]=node->vatTu;
		i++;
		DuyetNode(node->right, vt, i);
	}
}

void DoCayVaoMangVatTu(Vattu *&vt, CayVatTu cayVatTu){
	int n=cayVatTu.soluong;
	vt = new Vattu[n];
	int i=0;
	DuyetNode(cayVatTu.root, vt, i);
}

float CharToFloat(char ch[]){
	char chrFloat[7]="";
	char chrAFloat[7]="";
	int j=0;
	bool isAfter=false;
	int k=0;
	for(int i=0; i<strlen(ch); i++){
		if(!isAfter){
			if(ch[i]=='.'){
				chrFloat[j]=0;
				j=0;
				isAfter=true;
				continue;
			}
		}
		if(!isAfter)
		{
			chrFloat[j] = ch[i];
			j++;
		}
		else{
			chrAFloat[j] = ch[i];
			k++;
			j++;
		}
	}
	chrAFloat[j]=0;
	float fFloat=0;
	fFloat = (float) atoi(chrFloat) + ((float)atoi(chrAFloat)/pow(10,k));
	return fFloat;
}

void FloatToChar(char soTon[], float nFloat){
	strcpy(soTon,"");
	int a = floor(nFloat);
	char chrA[10]="";
	itoa(a, chrA, 10);
	strcat(soTon, chrA);
	a = floor(((float)nFloat-a)*100);
	itoa(a, chrA, 10);
	strcat(soTon, ".");
	strcat(soTon, chrA);
}

void print_VT(Vattu data,int x, int y)
{
   char chrFloat[7]="";
   FloatToChar(chrFloat, data.ton);
//   cout<<"Float: "<<chrFloat;
   outtextxy1(x+20+1,y,data.MAVT);
   outtextxy1(x+20+30+1,y,data.TENVT);
   outtextxy1(x+20+30+40+1,y,chrFloat);
   outtextxy1(x+20+30+40+30+1,y, data.DVT);
}

void print_DSVT(Vattu *vt, int size, int x, int y, int trang)
{
	if(size==0)
	return;
	for(int i=0;i<10;i++)
	{
		if((trang-1)*10+i>=size)
		return;
		print_VT(vt[(trang-1)*10+i],x,y);
		y=y+3;
	}
}

void LayThongTinVatTu(Vattu *vt, int i, int trang, int size, char MAVT[], char TENVT[], char DVT[], char chrFloat[], float &nfloat){
	if((trang-1)*10+i>=size) return;
//	cout<<"i: "<<(trang-1)*10+i;
	strcpy(MAVT, vt[(trang-1)*10+i].MAVT);
	strcpy(TENVT, vt[(trang-1)*10+i].TENVT);
	strcpy(DVT, vt[(trang-1)*10+i].DVT);
	FloatToChar(chrFloat, vt[(trang-1)*10+i].ton);
	nfloat = vt[(trang-1)*10+i].ton;
	outtextxy1(27,4,MAVT);
	outtextxy1(69,4,TENVT);
	outtextxy1(110,4,chrFloat);
	outtextxy1(140,4,DVT);
//	system("pause");
}
