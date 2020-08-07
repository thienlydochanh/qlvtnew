#include "dohoa.h"
#include "VatTu.h"
#include "NhanVien.h"
void laythongtinnhanvien(DS_NhanVien ds, int vt, char cMNV[],char Ho[],char Ten[],char Phai[],char CMND[])
{
	if(vt>ds.num||vt==-1)
	return;
	itoa(ds.DS[vt]->MANV,cMNV,10);
	outtextxy1(27,4,cMNV);
	strcpy(Ho,ds.DS[vt]->Ho);
	outtextxy1(69,4,Ho);
	strcpy(Ten,ds.DS[vt]->Ten);
	outtextxy1(116,4,Ten);
	strcpy(Phai,ds.DS[vt]->Phai);
	outtextxy1(76,9,Phai);
	strcpy(CMND,ds.DS[vt]->CMND);
	outtextxy1(27,9,CMND);
}
void run()
{
	CayVatTu root;
	
	DS_NhanVien dsNV;
	init_DSNV(dsNV);
	DocNhanVienTuFile("nhanvien.txt",dsNV);
//	cout<<endl<<"test: "<<dsNV.DS[2]->Ten<<" - "<<dsNV.DS[2]->list_HD.n;
//	cout<<endl<<"test2: "<<dsNV.DS[2]->list_HD.pHead->data.SoHD<<" - "<<dsNV.DS[2]->list_HD.pHead->data.ct.num;
//	cout<<endl<<"test3: "<<dsNV.DS[2]->list_HD.pHead->data.ct.list_CT[0].MAVT<<" - "<<dsNV.DS[2]->list_HD.pHead->data.ct.list_CT[0].SL;
//	system("pause");
	DocVatTuTuFile("VatTu.txt", root);
//	Sleep(5000);
//	bangnhanvien(1);
//	print_DSNV(dsNV,18,18+4,1);
	if(dsNV.DS[0]==NULL)
	cout<<" null lll l l l";
	
//	Sleep(5000);
	int x=2,y=2;
	int key=0;
		Manhinhchinh();
		while(1)
		{
       
	 		char c=0;
			if(kbhit())
			{
				c=getch();
			    trodichuyenlenxuong(x,y,key,MID,c);
		        
		    
		    trolai:
		    	gotoxy(5,50);
		    	cout<<" key:   ";
		    	gotoxy(8,50);
		    	cout<<key;
			switch(key)
			{
				case 1:
				{
					
					char MAVT[10]="";
					char TENVT[50]="";
					char DVT[20]="";
					char cton[10]="";
					float ton;
					
					Vattu *mangTamVatTu=NULL;
					int trang=1;
					bool isNew=true;
					
			   		gdnhapvattu();
			   		bangvattu(1);
			   		DoCayVaoMangVatTu(mangTamVatTu, root);
					print_DSVT(mangTamVatTu, root.soluong, 18, 18+4,1);

                 if(buocdem(x,y,key,0)==true)
                 {
                 	x=20;
					y=4;
					key=0;
				 }
				 else
				 {
				 	goto trolai;
				 }
		       
			    while(1)
			    {
				      c=0;
			    	if(kbhit())
			    	{
			    		c=getch();
						trodichuyen(x,y,key,MID,c);
			    		trove1:
                gotoxy(5,50);
		    	cout<<" key:   ";
		    	gotoxy(8,50);
		    	cout<<key;
			    	switch(key)
			    	{
			    		case 11:
			    			{
			    				if(isNew)	ScannerString(MAVT,20,27,4,key,key,x,y);
			    				goto trove1;
			    				break;
							}
						case 12:{
							ScannerString(TENVT,100,69,4,key,key,x,y);
							if(!isNew) key = 14;
							goto trove1;
			    			break;
						
								}
						case 13:{
							if(isNew==false)
							{
								key=(key==12)?14:12;
								goto trove1;
							}
							ScannerString(cton,100,110,4,key,key,x,y);
							goto trove1;
							break;
						}
						case 14:{
							ScannerString(DVT,140,140,4,key,key,x,y);
							goto trove1;
							break;
						}
						case 1111:{
						nutchucnang(1);
						
						if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   if(strlen(MAVT)==0 || strlen(TENVT)==0 || strlen(DVT)==0){
						   		outtextxy1(2,35,"Khong duoc de");
							   	outtextxy1(2,36,"trong");
						   		goto trove1;
						   }
							if(isNew){
								if(TimKiemVatTu(root, MAVT)==NULL){
						   			ton = CharToFloat(cton);
									ThemNodeVaoCay(root,TaoNodeVatTuMoi(TaoVatTuMoi(MAVT, TENVT, DVT, ton)));
									nutchucnang(0);
								}
							   	else{
							   		outtextxy1(2,35,"Ma VT da");
							   		outtextxy1(2,36,"duoc su dung");
							   		goto trove1;
								}
						   }
						   else{
								HieuChinhVatTuTheoMa(root, MAVT, TENVT, DVT);
								nutchucnang(0);
								isNew=true;
						   }
						   	
						   	GhiVatTuVaoFile("VatTu.txt", root);
						   	gdnhapvattu();
					   		bangvattu(trang);
					   		if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
					   		DoCayVaoMangVatTu(mangTamVatTu, root);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4,1);
						   	
						   	strcpy(MAVT,"");
						   	strcpy(TENVT,"");
						   	strcpy(DVT,"");
						   	strcpy(cton,"");
						   	ton=0;
						   	
						   	key=11;
						   	goto trove1;
							break;
						}
						case 1113:{
						nutchucnang(3);
						
						if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   strcpy(MAVT,"");
						   	strcpy(TENVT,"");
						   	strcpy(DVT,"");
						   	strcpy(cton,"");
						   	ton=0;
						   isNew=true;
		             	   nutchucnang(0);
		             	   key = 11;
		             	   goto trove1;
							break;
						}
						case 1112:{
                        nutchucnang(2);
						
                    	if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   nutchucnang(0);
						   
						   if(TimTatCaVatTu(dsNV, MAVT) || TimKiemVatTu(root, MAVT)->vatTu.ton>0){
						   		outtextxy1(2,35,"Khong the xoa");
							   	outtextxy1(2,36,"vat tu nay");
							   	goto trove1;
						   }
						   
						XoaNodeKhoiCayTheoMa(root, MAVT);
						
						GhiVatTuVaoFile("VatTu.txt", root);
						gdnhapvattu();
				   		bangvattu(trang);
				   		if(mangTamVatTu!=NULL) delete[] mangTamVatTu;
				   		DoCayVaoMangVatTu(mangTamVatTu, root);
						print_DSVT(mangTamVatTu, root.soluong, 18, 18+4,1);
						isNew=true;
						
						key=11;
						goto trove1;
						break;
						}
						case 101:{
							LayThongTinVatTu(mangTamVatTu, 0, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+0], 18, 18+4);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
						case 102:{
							LayThongTinVatTu(mangTamVatTu, 1, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+1], 18, 18+7);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
						case 103:{
							LayThongTinVatTu(mangTamVatTu, 2, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+2], 18, 18+10);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 104:{
							LayThongTinVatTu(mangTamVatTu, 3, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+3], 18, 18+13);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 105:{
							LayThongTinVatTu(mangTamVatTu, 4, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+4], 18, 18+16);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 106:{
							LayThongTinVatTu(mangTamVatTu, 5, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+5], 18, 18+19);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 107:{
							LayThongTinVatTu(mangTamVatTu, 6, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+6], 18, 18+22);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 108:{
							LayThongTinVatTu(mangTamVatTu, 7, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+7], 18, 18+25);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 109:{
							LayThongTinVatTu(mangTamVatTu, 8, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+8], 18, 18+28);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
							case 110:{
							LayThongTinVatTu(mangTamVatTu, 9, trang, root.soluong, MAVT, TENVT, DVT, cton, ton);
							SetColor(15);
							print_DSVT(mangTamVatTu, root.soluong, 18, 18+4, trang);
							SetColor(14);
							print_VT(mangTamVatTu[(trang-1)*10+9], 18, 18+31);
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove1;
						   }
						   isNew=false;
						   key=12;
						   goto trove1;
							break;
						}
						case 9999:
						{
							x=3;y=3;
							key=1;
							goto trolai;
						}
						default:{
							if(key==1||key==2||key==3||key==4)
							{
								key=11;
								goto trove1;
							}
							break;
						}

					}
			    		
			    
			    	
			}
			
//					break;
		      }
		       break;
					}
			case 2:{
				bool trangthailuu=true;
				int trang =1;
			    gdnhapnhanvien();
			    bangnhanvien(trang);
			    print_DSNV(dsNV,18,18+4,trang);
               if(buocdem(x,y,key,0)==true)
                 {
                 	x=20;
					y=4;
					key=0;
//                 	goto trolai;
				 }
				 else
				 {
				 	goto trolai;
				 }
		       
		            	int MANV;
		            	char cMANV[6]="";
                    	char Ho[30]="";
              			char Ten[20]="";
						char Phai[4]="";
						char CMND[13]="";
                        int vt=-1;
			    while(1)
			    {
				     c=0;
			    	if(kbhit())
			    	{
			    		c=getch();
						trodichuyen(x,y,key,MID,c);
			    		trove2:
                    gotoxy(5,50);
		    	cout<<" key:   ";
		    	gotoxy(8,50);
		    	cout<<key;
			    	switch(key)
			    	{
			    		case 21:
			    			{
			    				
			    				ScannerString(cMANV,20,27,4,key,key,x,y);
			    				outtextxy1(20,13,"                                       ");
			    				goto trove2;
			    				break;
							}
						case 22:{
							ScannerString(Ho,100,69,4,key,key,x,y);
							outtextxy1(20,13,"                                       ");
							goto trove2;
			    			break;
						
								}
						case 23:{
							ScannerString(Ten,100,116,4,key,key,x,y);
							outtextxy1(20,13,"                                       ");
							goto trove2;
							break;
						}
						case 25:{
							ScannerString(Phai,100,76,9,key,key,x,y);
							outtextxy1(20,13,"                                       ");
							goto trove2;
							break;
						}
						case 24:{
							ScannerString(CMND,100,27,9,key,key,x,y);
							outtextxy1(20,13,"                                       ");
							goto trove2;
							break;
						}

						case 1111:{
                       nutchucnang(1);
					
				           if(buocdem(x,y,key,0)==false)
				           {
				            goto trove2;
						   }
						   	if(cMANV[0]*Ho[0]*Ten[0]*Phai[0]*CMND[0]==0)
						{
							outtextxy1(20,13,"Thong tin khong duoc de trong !");
								nutchucnang(0);
							key=21;
							goto trove2;
							
						}
						if(kiemtratrungnhanvien(dsNV,CMND,atoi(cMANV))==true&&trangthailuu==true)
						{
							outtextxy1(20,13,"Thong tin da duoc su dung !");
							nutchucnang(0);
							key=21;
							goto trove2;
						}
							NhanVien temp;
							if(trangthailuu==true)
							{
							temp=newdata_NV(atoi(cMANV),Ho,Ten,Phai,CMND);
							insert_NV(dsNV,temp);
							GhiNhanVienVaoFile("nhanvien.txt",dsNV);
						  MANV=0;
		            	 memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            	 memset(CMND,0,13);
						 gdnhapnhanvien();
			             bangnhanvien(1);
			            print_DSNV(dsNV,18,18+4,trang);
							nutchucnang(0);
							key=21;
							goto trove2;
							break;
							}
							if(trangthailuu==false)
							{
								if(atoi(cMANV)!=dsNV.DS[vt]->MANV&&kiemtratrungnhanvien(dsNV,CMND,atoi(cMANV))==true)
								{
									outtextxy1(20,13,"Thong tin da duoc su dung !");
							nutchucnang(0);
							key=21;
							goto trove2;
								}
								temp=newdata_NV(atoi(cMANV),Ho,Ten,Phai,CMND);
								sua_NV(dsNV,temp,vt);
								vt=-1;
							memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            	 memset(CMND,0,13);
						 gdnhapnhanvien();
			             bangnhanvien(1);
			            print_DSNV(dsNV,18,18+4,trang);	
							}
						
						}
						case 1112:{// HUY
                        nutchucnang(2);
					  
							if(buocdem(x,y,key,0)==false)
				           {
				            goto trove2;
						   }
						     if(dsNV.DS[vt]->list_HD.pHead!=NULL)
					    {
					    	outtextxy1(20,13,"Khong xoa duoc nhan vien nay !");
							nutchucnang(0);
							key=21;
							goto trove2;
						}
						   del_NV(dsNV,vt);
						   vt=-1;
						   gdnhapnhanvien();
						   bangnhanvien(trang);
			            print_DSNV(dsNV,18,18+4,trang);	
		             	   nutchucnang(0);
							break;
						}
						case 1113:{//NEW
                        nutchucnang(3);
                        if(buocdem(x,y,key,0)==false)
				           {
				            goto trove2;
						   }
						 MANV=0;
		            	 memset(cMANV,0,6);
		            	 memset(Ho,0,30);
		            	 memset(Ten,0,20);
		            	 memset(Phai,0,4);
		            	 memset(CMND,0,13);
						 gdnhapnhanvien();
			             bangnhanvien(1);
			            print_DSNV(dsNV,18,18+4,1);
		             	nutchucnang(0);
		             	key=21;
		             	x=20;
				       	y=4;
				       	  trangthailuu=true;
		                goto trove2;
						break;
						}
						case 200:{
							SetColor(15);
							bangnhanvien(trang);
                            print_DSNV(dsNV,18,18+4,trang);
							break;
						}
						case 201:{
//							cout<<" vo key 101";
                            vt=(trang-1)*10+key-201;
                            if(vt>=dsNV.num) break;
                            SetColor(15);
                            print_DSNV(dsNV,18,18+4,trang);
                              
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
	                        if(buocdem(x,y,key,0)==false)
				           {
				              goto trove2;
						   }

                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                            trangthailuu=false;
                            	key=21;
		                   	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
						case 202:{ 
					    	vt=(trang-1)*10+key-201;
						    if(vt>=dsNV.num) break;
							SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
							 
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						      
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
						
						case 203:{
						    vt=(trang-1)*10+key-201;
							  if(vt>=dsNV.num) break;
							SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
                             
						      
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						      
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							
							case 204:{
							vt=(trang-1)*10+key-201;
						     if(vt>=dsNV.num) break;
							SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
						    
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						    
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
							break;
						}
							case 205:{ 
							vt=(trang-1)*10+key-201;
							      if(vt>=dsNV.num) break;
								SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
							    
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						      
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							case 206:{
							vt=(trang-1)*10+key-201;
						     if(vt>=dsNV.num) break;
								SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
						    
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						      
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							case 207:{
							vt=(trang-1)*10+key-201;
						     if(vt>=dsNV.num) break;
								SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
						    
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						    
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							case 208:{
							vt=(trang-1)*10+key-201;
				     	 if(vt>=dsNV.num) break;
							SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
				     	
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						     
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							case 209:{
							vt=(trang-1)*10+key-201;
						 if(vt>=dsNV.num) break;
							SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
						
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						     
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
							case 210:{
							vt=(trang-1)*10+key-201;
						      if(vt>=dsNV.num) break;
								SetColor(15);
                            print_DSNV(dsNV,18,18+4,1);
						     
                             SetColor(14);
                             print_NV(*dsNV.DS[vt],18,18+4+(key-201)*3);
                             SetColor(15);
	                        if(buocdem(x,y,key,0)==false)
				           {
						    
                             
				            goto trove2;
						   }
                            
                            SetColor(14);
                            laythongtinnhanvien(dsNV,vt,cMANV,Ho,Ten,Phai,CMND);
                              trangthailuu=false;
                              	key=21;
		             	x=20;
				       	y=4;goto trove2;
						    SetColor(15);
							break;
						}
						case 9999:
						{
							x=3;y=15;
							key=2;
							goto trolai;
						}
						default:{
							if(key==1||key==2||key==3||key==4)
							{
								key=21;
								goto trove2;
							}
							break;
						}

					}
			    		
			    
			    	
			}
			
//					break;
		      }
				break;
			}
			case 3:{
					char LOAIHD[3]="";
					char NGAYLAP[50]="";
					char SOHD[25]="";
					int MANV;
					char chrMANV[10]="";
					Date ngayLap = GetNow(NGAYLAP);
					
					int trang=1;
					bool isRemove=false;
					bool isnew=false;
					int vt=0;
					HOADON tmpHoaDon  = newdata_HD("", ngayLap, ' ');
					
					char MaVT[15]="";
					char chrSL[10]="";
					char chrDonGia[20]="";
					char chrVAT[10]="";
					
			   		gdhoahon();
			   		banghoadon();
			   		outtextxy1(76,4, NGAYLAP);

                 if(buocdem(x,y,key,0)==true)
                 {
                 	x=20;
					y=4;
					key=0;
				 }
				 else
				 {
				 	goto trolai;
				 }
		       
			    while(1)
			    {
				      c=0;
			    	if(kbhit())
			    	{
			    		c=getch();
						trodichuyen(x,y,key,MID,c);
			    		trove3:
                gotoxy(5,50);
		    	cout<<" key:   ";
		    	gotoxy(8,50);
		    	cout<<key;
			    	switch(key)
			    	{
			    		case 31:
			    			{
			    				
			    				ScannerString(LOAIHD,1,35,4,key,key,x,y);
			    				
			    				if(LOAIHD[0]!='N' && LOAIHD[0]!='X'){
			    					outtextxy1(2, 35, "Chi nhap");
			    					outtextxy1(2, 36, "N hoac X");
//			    					key = 31;
                                   isnew=true;
			    					goto trove3;
								}
								else{
									tmpHoaDon.Loai = LOAIHD[0];
									outtextxy1(2, 35, "        ");
			    					outtextxy1(2, 36, "        ");
			    					isnew=false;
								}
			    				goto trove3;
			    				break;
							}
//						case 32:{
////							key=33;
//							goto trove3;
//			    			break;
//						
//								}
						case 33:{
							ScannerString(SOHD,20,116,4,key,key,x,y);
							NhanVien tmpNV;
							if(TimTatCaHoaDon(dsNV, SOHD, tmpNV)!=NULL&&isnew==true){
//								outtextxy1(2, 35, "So Hoa Don");
//			    				outtextxy1(2, 36, "da duoc dung");
//			    				key = 33;
//								banghoadon();
								if(tmpHoaDon.ct.num==0){
									NODE_HD *tmpHD = TimTatCaHoaDon(dsNV, SOHD, tmpNV);
									outtextxy(35,4, tmpHD->data.Loai);
									char chrNL[20] = "";
									char chrString[10]="";
									itoa(tmpHD->data.NgayLap.ngay, chrString, 10);
									strcat(chrNL, chrString);
									strcat(chrNL, "-");
									itoa(tmpHD->data.NgayLap.thang, chrString, 10);
									strcat(chrNL, chrString);
									strcat(chrNL, "-");
									itoa(tmpHD->data.NgayLap.nam, chrString, 10);
									strcat(chrNL, chrString);
									outtextxy1(76,4, chrNL);
									itoa(tmpNV.MANV, chrString, 10);
									outtextxy1(35,9, chrString);
									char TenNV[60]="";
									strcat(TenNV, tmpNV.Ho);
									strcat(TenNV, " ");
									strcat(TenNV, tmpNV.Ten);
									outtextxy1(76,9, TenNV);
									print_DSCTHD(tmpHD->data.ct, root, 18, 18+3);
								}
			    				goto trove3;
							}
							else{
								strcpy(tmpHoaDon.SoHD, SOHD);
								outtextxy1(2, 35, "          ");
			    				outtextxy1(2, 36, "            ");
			    				banghoadon();
							}
							goto trove3;
							break;
						}
						case 34:{
							ScannerString(chrMANV,7,35,9,key,key,x,y);
							MANV=atoi(chrMANV);
							if(TimNhanVien(dsNV, MANV)==NULL){
								outtextxy1(2, 35, "Khong tim thay");
			    				outtextxy1(2, 36, "nhan vien");
//			    				key = 34;
			    				goto trove3;
							}
							else{
								outtextxy1(2, 35, "              ");
			    				outtextxy1(2, 36, "         ");
			    				char ten[50]="";
			    				NhanVien tmpNhanVien = *TimNhanVien(dsNV, MANV);
			    				strcpy(ten, tmpNhanVien.Ho);
			    				strcat(ten, " ");
			    				strcat(ten, tmpNhanVien.Ten);
			    				outtextxy1(76, 9, ten);
							}
							goto trove3;
							break;
						}
						case 35:{
							
							ScannerString(MaVT,10,25,14,key,key,x,y);
							NodeVatTu *tmpVatTu = TimKiemVatTu(root, MaVT);
							if(tmpVatTu==NULL){
								outtextxy1(2, 35, "Khong tim thay");
			    				outtextxy1(2, 36, "Vat Tu");
//			    				key = 35;
			    				goto trove3;
							}
							else{
								outtextxy1(2, 35, "              ");
			    				outtextxy1(2, 36, "         ");
			    				char tenVatTu[60]="";
								strcpy(tenVatTu, tmpVatTu->vatTu.TENVT);
			    				outtextxy1(49, 14, tenVatTu);
							}
							goto trove3;
							break;
						}
						case 36:{
							ScannerString(chrSL,7,43+36,14,key,key,x,y);
							
							goto trove3;
							break;
						}
						case 37:{
							ScannerString(chrDonGia,15,63+36,14,key,key,x,y);
							
							goto trove3;
							break;
						}
						case 38:{
							ScannerString(chrVAT,8,86+36,14,key,key,x,y);
							
							goto trove3;
							break;
						}
						case 39:{
							button(139,13,39,10,3,2,12,"NHAP VT",MID);
							button(150,13,40,7,3,2,0,"XOA",MID);
							if(buocdem(x,y,key,0)==false)
				           {
				           	button(139,13,39,10,3,2,0,"NHAP VT",MID);
				           	button(150,13,40,7,3,2,0,"XOA",MID);
				            goto trove3;
						   }
						   button(139,13,39,10,3,2,0,"NHAP VT",MID);
						   if(LOAIHD[0]=='X'){
//						   	    int slt=TimKiemVatTu(root, MaVT)->vatTu.ton-CharToFloat(chrSL);
						   	    if(0>TimKiemVatTu(root, MaVT)->vatTu.ton-CharToFloat(chrSL))
						   	    {
						   	    	outtextxy1(2, 35, "so luong vt");
			    					outtextxy1(2, 36, "khong du .max");	
			    					char s[10]="";
			    					FloatToChar(s,TimKiemVatTu(root, MaVT)->vatTu.ton);
			    					outtextxy1(2, 37, s);
			    					break;
								}
								TimKiemVatTu(root, MaVT)->vatTu.ton -= CharToFloat(chrSL);
						   }
						   else if(LOAIHD[0]=='N'){
						   		TimKiemVatTu(root, MaVT)->vatTu.ton += CharToFloat(chrSL);
						   }
						   insert_CTHD(tmpHoaDon.ct, newdataCTHD(MaVT, CharToFloat(chrSL), CharToFloat(chrDonGia), CharToFloat(chrVAT), 1));
						   
						   GhiVatTuVaoFile("VatTu.txt", root);
						   
						   banghoadon();
						   print_DSCTHD(tmpHoaDon.ct, root, 18, 18+3);
						   
						   strcpy(MaVT,"");
						   strcpy(chrSL,"");
						   strcpy(chrDonGia,"");
						   strcpy(chrVAT,"");
						   
						   outtextxy1(25,14, "          ");
						   outtextxy1(49,14, "               ");
						   outtextxy1(43+36,14, "       ");
						   outtextxy1(63+36,14, "            ");
						   outtextxy1(85+36,14, "         ");
							
							key=35;
							goto trove3;
							break;
						}
						case 40:{
							button(139,13,39,10,3,2,0,"NHAP VT",MID);
							button(150,13,40,7,3,2,12,"XOA",MID);
							if(buocdem(x,y,key,0)==false)
				           {
				           	button(139,13,39,10,3,2,0,"NHAP VT",MID);
				           	button(150,13,40,7,3,2,0,"XOA",MID);
				            goto trove3;
						   }
						   button(150,13,40,7,3,2,0,"XOA",MID);
						   
						   if(isRemove){
						   		if(LOAIHD[0]=='X'){
									TimKiemVatTu(root, MaVT)->vatTu.ton += CharToFloat(chrSL);
							   	}
							   	else if(LOAIHD[0]=='N'){
							   		TimKiemVatTu(root, MaVT)->vatTu.ton -= CharToFloat(chrSL);
							   	}
							   	GhiVatTuVaoFile("VatTu.txt", root);
								Xoa1CTHD(tmpHoaDon.ct, vt);
								banghoadon();
								print_DSCTHD(tmpHoaDon.ct, root, 18, 18+3);
								isRemove = false;
						   }
						   
						   strcpy(MaVT,"");
						   strcpy(chrSL,"");
						   strcpy(chrDonGia,"");
						   strcpy(chrVAT,"");
						   
						   outtextxy1(25,14, "          ");
						   outtextxy1(49,14, "               ");
						   outtextxy1(43+36,14, "       ");
						   outtextxy1(63+36,14, "            ");
						   outtextxy1(85+36,14, "         ");
							
							key=35;
							goto trove3;
							break;
						}
						case 1111:{
						nutchucnang(1);
						
						if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   if(strlen(SOHD)==0 || strlen(chrMANV)==0 || tmpHoaDon.ct.num==0){
						   		outtextxy1(2, 35, "khong duoc bo");
			    				outtextxy1(2, 36, "trong");	
						   		goto trove3;
						   }
						   
//							if(isNew){
								insert_HD(TimNhanVien(dsNV, MANV)->list_HD, tmpHoaDon);
								nutchucnang(0);
//						   }
						   	
						   	GhiNhanVienVaoFile("NhanVien.txt", dsNV);
						   	gdhoahon();
					   		banghoadon();
					   		outtextxy1(76,4, NGAYLAP);
						   	
						   	strcpy(SOHD,"");
						   	strcpy(LOAIHD,"");
						   	strcpy(NGAYLAP,"");
						   	strcpy(chrMANV,"");
						   	tmpHoaDon  = newdata_HD("", ngayLap, ' ');
									   	
						   	key=31;
						   	goto trove3;
							break;
						}
						case 301:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 302:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 303:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 304:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 305:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 306:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 307:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 308:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 309:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 310:
						{
							if(key-301>tmpHoaDon.ct.num){
								goto trove3;
							}
							vt=key-301;
							SetColor(15);
                            print_DSCTHD(tmpHoaDon.ct,root,18,18+3); 
                            SetColor(14);
                            print_CTHD(tmpHoaDon.ct.list_CT[key-301],TimKiemVatTu(root, tmpHoaDon.ct.list_CT[key-301].MAVT)->vatTu.TENVT,18,18+3+(key-301)*3);
                            SetColor(15);
                            
                            if(buocdem(x,y,key,0)==false)
				           {
				            goto trove3;
						   }
						   
						   isRemove=true;
						   LayThongTin1CTHD(tmpHoaDon.ct, root, vt, tmpHoaDon.ct.num, MaVT, chrSL, chrDonGia, chrVAT);
                            key=40;
                            
							goto trove3;
							break;
						}
						case 9999:
						{
							x=3;y=3;
							key=1;
							goto trolai;
						}
						default:{
							if(key==1||key==2||key==3||key==4)
							{
								key=31;
								goto trove3;
							}
							break;
						}

					}
			    		
			    
			    	
			}
			
//					break;
		      }
		       break;
					
			}
			case 4:{
//			gdthongke();
			gdthongke_NV();
			bangthongke_hdnv(1);
			 if(buocdem1(x,y,key,0)==true)
                 {
                 	x=30;
					y=8;
					key=0;
//                 	goto trolai;
				 }
				 else
				 {
				 	goto trolai;
				 }
				 char MANV[10]="";
				 char Ngay1[10]="";
				 char Ngay2[10]="";
				 Date t1;
				 Date t2;
				 int vt=-1;
			while(1)
			    {
				      c=0;
			    	if(kbhit())
			    	{
			    		c=getch();
						trodichuyen(x,y,key,MID,c);
			    	 trolai4:
                gotoxy(5,50);
		    	cout<<" key:   ";
		    	gotoxy(8,50);
		    	cout<<key;
		    	  
			    	switch(key)
			    	{
			    		case 411:
			    			{
//			    				memset(MANV,0,10);
			    				outtextxy1(2, 35, "          ");
			    				outtextxy1(2, 36, "          ");
			    				outtextxy1(31,8,"                ");
			    				outtextxy1(51,8,"                         ");
			    				outtextxy1(93,8,"              ");
			    				outtextxy1(134,8,"              ");
			    				ScannerString(MANV,10,31,8,411,key,x,y);
			    				if(MANV[0]=='0')
			    				{
			    					if(strlen(Ngay1)<10)
								{
									outtextxy1(2, 35, "khong de trong");
			    					outtextxy1(2, 36, "thong tin");
								}
								}
			    				vt= timkiem_NV_vt(dsNV,atoi(MANV));
			    				if(vt==-1||vt>dsNV.num) 
							{
									outtextxy1(2, 35, "Nhan vien");
			    					outtextxy1(2, 36, "k ton tai");
			    					x=30;
			    					y=8;
			    					key=0;
			    					goto trolai4;
								break;
							}
			    				outtextxy1(51,8,dsNV.DS[vt]->Ho);
			    				outtextxy1(71,8,dsNV.DS[vt]->Ten);
								goto trolai4; 
							}
						case 412:
							{
								Scannerdate(Ngay1,10,93,8,412,key,x,y);
								if(strlen(Ngay1)<10)
								{
									outtextxy1(2, 35, "ngay k dung");
			    					outtextxy1(2, 36, "dd/mm/yyyy");
			    					break;
								}
								t1=chuyenchuoithoigian(Ngay1);
//								cout<<"\n"<<t1.ngay<<" "<<t1.thang<<" "<<t1.nam;
								goto trolai4;
							}
						case 413:{
							Scannerdate(Ngay2,10,134,8,413,key,x,y);
							if(strlen(Ngay2)<10)
								{
									outtextxy1(2, 35, "ngay k dung");
			    					outtextxy1(2, 36, "dd/mm/yyyy");
			    					break;
								}
							t2=chuyenchuoithoigian(Ngay2);
							goto trolai4;
							break;
						}
						case 414:{
							
//							cout<<" vi tri "<<vt;
							if(vt==-1||vt>dsNV.num) 
							{
									outtextxy1(2, 35, "Nhan vien");
			    					outtextxy1(2, 36, "k ton tai");
								break;
							}

							
							printdsHD(18+1,18+3,*dsNV.DS[vt],root,t1,t2);
							key=0;
							x=31;
							y=8;
//							goto trolai4;
							break;
						}
						case 9999:
						{
							x=2;y=20;
							key=4;
							goto trolai;
						}
						default:{
							if(key==1||key==2||key==3||key==4)
							{
								key=414;
								goto trolai4;
							}
								x=30;
				            	y=8;
				            	key=414;
				            		goto trolai4;
							break;
						}
						
			     	}
			}
		}
//gdthongke_doanhthu();
//bangthongkedoanhthu();

				break;
			}
		default:{
//				key=1;
               if(key==0)
               break;
               key=1;
               x=3;
               y=3;
			   goto trolai;
				break;
			}
			
		}
			
		}
		
		
}
}
