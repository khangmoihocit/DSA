#include<bits/stdc++.h>
using namespace std;

                                         //SẢN PHẨM

// Khởi tạo đối tượng sản phẩm
struct SanPham{
    string MaSP;
    string TenSP;
    string ChatLieu;
    double Gia;
    int SLTonKho;
};
// Tạo lk trước sau cho sản phẩm
struct DNodeSP{
    SanPham sp;
    DNodeSP *pPrevious;
    DNodeSP *pNext;
};
//Tạo danh sách cho sản phẩm
struct DoubleListSP{
    DNodeSP *pHead;
};
void InitializerSP(DoubleListSP &listSP){
    listSP.pHead=NULL;
}
//Chèn dữ liệu
//Sản phẩm
DNodeSP *CreateNodeSP(SanPham sp){
    DNodeSP *pDNodeSP=new DNodeSP;
    if(pDNodeSP!=NULL){
        pDNodeSP->sp=sp;
        pDNodeSP->pPrevious=NULL;
        pDNodeSP->pNext=NULL;
    }else{
        cout<<"Chèn thất bại";
    }
    return pDNodeSP;
}
//Đếm kích cỡ list SP
int SizeOfListSP(DoubleListSP list){
    DNodeSP *pTmp=list.pHead;
    int nSize=0;
    while(pTmp!=NULL){
        ++nSize;
        pTmp=pTmp->pNext;
    }
    return nSize;
}

//Nhập sản phẩm
SanPham InPut(){
    SanPham sp;
    cout<<"Ma san pham:";
    getline(cin,sp.MaSP);
    cout<<"Ten san pham:";
    getline(cin,sp.TenSP);
    cout<<"Chat lieu san pham:";
    getline(cin,sp.ChatLieu);
    cout<<"Gia san pham:";
    cin>>sp.Gia;cin.ignore();
    cout<<"So luong ton kho:";
    cin>>sp.SLTonKho;cin.ignore();
    return sp;
}

//thêm sản phẩm vào cuối danh sách
void InsertNodeSP(DoubleListSP &listSP,SanPham sp){
    DNodeSP *pDNodeSP=CreateNodeSP(sp);
    if(listSP.pHead==NULL){
        listSP.pHead=pDNodeSP;
    }else{
        DNodeSP *pTmp=listSP.pHead;
        while(pTmp->pNext!=NULL){
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pDNodeSP;
        pDNodeSP->pPrevious=pTmp;
    }
    cout<<"Them thanh cong"<<endl;
}

//1.Chèn dữ liệu cho sản phẩm
void ChenSPVaoDS(DoubleListSP &listSP,SanPham sp){
    cout<<"\nNhap vi tri muon chen(1.Dau[0] | 2.Cuoi["<<SizeOfListSP(listSP)
        <<"] | 3.Giua [0,"<<SizeOfListSP(listSP)-1<<"]):";
    int chon;cin>>chon;cin.ignore();
    int so;
    if(chon==3){
        cout<<"Muon chen vao vi tri nao:";
        cin>>so;cin.ignore();
    }
    DNodeSP *pDNodeSP=CreateNodeSP(sp);
    if(listSP.pHead==NULL){
        listSP.pHead=pDNodeSP;
    }else{
        if(chon==1){                                   //Chèn đầu
            pDNodeSP->pNext=listSP.pHead;
            listSP.pHead->pPrevious=pDNodeSP;
            listSP.pHead=pDNodeSP;
        }
        if(chon==2){                                  //Chèn cuối
            DNodeSP *pTmp=listSP.pHead;
            while(pTmp->pNext!=NULL){
                pTmp=pTmp->pNext;
            }
            pTmp->pNext=pDNodeSP;
            pDNodeSP->pPrevious=pTmp;
        }
        if(chon==3){                                  //Chèn giữa
            int i=0;
            DNodeSP *pIns=listSP.pHead;
            DNodeSP *pPre=NULL;
            while(i!=so){
                pPre=pIns;
                pIns=pIns->pNext;
                ++i;
            }
            pPre->pNext=pDNodeSP;
            pDNodeSP->pPrevious=pPre;
            pDNodeSP->pNext=pIns;
            pIns->pPrevious=pDNodeSP;
        }
    }
    cout<<"\nChen thanh cong"<<endl;
}


//Hiện danh sách sản phẩm`
//Tiêu đề
void PrintTieuDeSP(){
    cout<<"Ma san pham     Ten san pham     Chat lieu     Gia          So luong ton kho"<<endl;
}
//Sản phẩm
void PrintSP(SanPham sp){
    cout<<left<<setw(15)<<sp.MaSP<<" "<<left <<setw(16)<<sp.TenSP<<" "<<left<<setw(13)
        <<sp.ChatLieu<<" "<<left<<setw(12)<<sp.Gia<<" "<<sp.SLTonKho<<endl;
}
//Danh sách sản phẩm
void HienDanhSachSP(DoubleListSP listSP){
    if(listSP.pHead==NULL){
        cout<<"Danh sach san pham rong";
    }else{
        PrintTieuDeSP();
        DNodeSP *pTmp=listSP.pHead;
        while(pTmp!=NULL){
            PrintSP(pTmp->sp);
            pTmp=pTmp->pNext;
        }
    }
    cout<<endl;
}

//Đọc, ghi file danh sách sản phẩm
//Ghi file
void WriteFileSP(DoubleListSP listSP, string FileName){
    ofstream ofs(FileName,ios::binary);
    if(!ofs.is_open()){
        cout<<"Ghi file that bai";
    }else{
        DNodeSP *pTmp=listSP.pHead;
        int n = SizeOfListSP(listSP);
        ofs.write((char*)&n,sizeof(int));
        while(pTmp!=NULL){
            ofs.write((char*)&(pTmp->sp),sizeof(SanPham));
            pTmp=pTmp->pNext;
        }
        ofs.close();
        cout<<"Ghi file thanh cong"<<endl;
    }
}
//Đọc file

//Đọc danh sách sản phẩm
void ReadFileSP(DoubleListSP &listSP, string FileName){
    ifstream ifs(FileName,ios::binary);
    if(!ifs.is_open()){
        cout<<"Doc file that bai";
    }else{
        int n;
        ifs.read((char*)&n,sizeof(int));
        for(int i=0;i<n;++i){
            SanPham sp;
            ifs.read((char*)&sp, sizeof(SanPham));
            InsertNodeSP(listSP,sp);
        }
        ifs.close();
        cout<<"Doc file thanh cong"<<endl;
    }
}





//Xoá sản phẩm khỏi danh sách
void RemoveByMaSP(DoubleListSP &listSP){
    cout<<"Nhap ma san pham muon xoa:";
    string maSP;
    cin>>maSP;cin.ignore();
    DNodeSP *pDel=listSP.pHead;
    if(pDel==NULL){
        cout<<"Danh sach rong khong co sp";
    }
    DNodeSP *pPre=NULL;
    while(pDel!=NULL){
        if(pDel->sp.MaSP==maSP)
            break;
        pPre=pDel;
        pDel=pDel->pNext;
    }
    if(pDel==NULL){
       cout<<"MaSP ko ton tai";
    }else{
        if(pDel==listSP.pHead){
            if(listSP.pHead->pNext==NULL){
                DoubleListSP list;
                InitializerSP(list);
                listSP=list;
            }else{
                listSP.pHead=listSP.pHead->pNext;
                listSP.pHead->pPrevious=NULL;
                pDel->pNext=NULL;
            }
        }else if(pDel->pNext==NULL){
            pPre->pNext=NULL;
            pDel->pPrevious=NULL;
        }else{
            pPre->pNext=pDel->pNext;
            pDel->pNext->pPrevious=pPre;
            pDel->pPrevious=NULL;
            pDel->pNext=NULL;
        }
        delete pDel;
    }
}
//Tìm kiếm sp theo MaSP
DNodeSP *SearchSP(DoubleListSP listSP){
    cout<<"Nhap maSP muon tim kiem:";
    string maSP;cin>>maSP;
    DNodeSP *pTmp=listSP.pHead;
    while(pTmp!=NULL){
        if(pTmp->sp.MaSP==maSP)
            break;
        pTmp=pTmp->pNext;
    }
    if(pTmp==NULL){
        cout<<"Khong co sp co MaSP tren";
    }else{
        PrintTieuDeSP();
    }
    return pTmp;
}
//Sắp xếp danh sach theo Gia
void SortListSP(DoubleListSP &listSP){
    if(listSP.pHead==NULL){
        cout<<"Danh sach rong";
    }else{
        for(DNodeSP *pTmp1=listSP.pHead;pTmp1!=NULL;pTmp1=pTmp1->pNext){
            for(DNodeSP *pTmp2=pTmp1->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
                if(pTmp1->sp.Gia>pTmp2->sp.Gia){
                    SanPham tmp=pTmp1->sp;
                    pTmp1->sp=pTmp2->sp;
                    pTmp2->sp=tmp;
                }
            }
        }
    }
}
//Cập nhật giá tiền hoặc SLTonKho cho sp
void UpdateSP(DoubleListSP &listSP){
    cout<<"Chon loai cap nhat(1.Gia | 2.SLTonKho):";
    int chon;cin>>chon;cin.ignore();
    cout<<"MaSP duoc cap nhat:";string maSP;cin>>maSP;
    DNodeSP *pUpd=listSP.pHead;
    while(pUpd!=NULL){
        if(pUpd->sp.MaSP==maSP)
            break;
        pUpd=pUpd->pNext;
    }
    switch(chon){
        case 1:
            cout<<"Gia cap nhat";double gia;cin>>gia;cin.ignore();
            if(gia<=0){
                cout<<"Gia khong hop le";
            }else
                pUpd->sp.Gia=gia;
            break;
        case 2:
            cout<<"SLTonKho cap nhat";int SL;cin>>SL;cin.ignore();
            if(SL<=0){
                cout<<"SL khong hop le";
            }else
                pUpd->sp.SLTonKho=SL;
            break;
    }
}
//Xóa danh sách san pham
void XoaDSSP(DoubleListSP &listSP){
    cout<<"Bat dau xoa"<<endl;
    while(listSP.pHead!=NULL){
        DNodeSP *pDel=listSP.pHead;
        listSP.pHead=listSP.pHead->pNext;
        pDel->pNext=NULL;
        pDel->pPrevious=NULL;
        PrintSP(pDel->sp);cout<<" dang xoa"<<endl;
        delete pDel;
    }
    cout<<"Xoa hoan tat"<<endl;
}













                                             //HÓA ĐƠN




// Khởi tạo đối tượng hóa đơn-sản phẩm
struct HoaDonSP{
    string MaSP;
    int SLMua;
    double ThanhTien;
};
//Tạo lk trước sau cho hóa đơn -sản phẩm
struct DNodeHDSP{
    HoaDonSP hd;
    DNodeHDSP *pPrevious;
    DNodeHDSP *pNext;
};
//Tạo danh sách cho hóa đơn sản phẩm
struct DoubleListHDSP{
    DNodeHDSP *pHead;
};
void InitializerHDSP(DoubleListHDSP &listHDSP){
    listHDSP.pHead=NULL;
}
//Hóa đơn sản phẩm
DNodeHDSP *CreateNodeHDSP(HoaDonSP hd){
    DNodeHDSP *pDNodeHD=new DNodeHDSP;
    if(pDNodeHD!=NULL){
        pDNodeHD->hd=hd;
        pDNodeHD->pPrevious=NULL;
        pDNodeHD->pNext=NULL;
    }else{
        cout<<"Chèn thất bại";
    }
    return pDNodeHD;
}
//Nhập hóa đơn sản phẩm
HoaDonSP InputHDSP(DoubleListSP &listSP){
    HoaDonSP hdsp;
    while(true){
        cout<<"Ma san pham:";cin>>hdsp.MaSP;cin.ignore();
        DNodeSP *pTmp=listSP.pHead;

        while(pTmp!=NULL){
            if(pTmp->sp.MaSP==hdsp.MaSP){
                while(true){
                    cout<<"So luong mua:";cin>>hdsp.SLMua;cin.ignore();
                    if(pTmp->sp.SLTonKho<hdsp.SLMua){
                        cout<<"So luong khong hop le";
                        cout<<"\n Nhap lai"<<endl;
                    }else{
                        hdsp.ThanhTien=pTmp->sp.Gia*hdsp.SLMua;
                        pTmp->sp.SLTonKho=pTmp->sp.SLTonKho-hdsp.SLMua;
                        return hdsp;
                    }
                }
            }else{
                pTmp=pTmp->pNext;
            }
        }
        cout<<"Ma san pham khong ton tai"<<endl;
        cout<<"Nhap iai"<<endl;
    }
}
//ChenHDSPVaoDS
void ChenHDSPVaoDS(DoubleListHDSP &listHDSP,DoubleListSP &listSP,HoaDonSP hdsp){
    DNodeHDSP *pDNodeHDSP=CreateNodeHDSP(hdsp);
    if(listHDSP.pHead==NULL){
        listHDSP.pHead=pDNodeHDSP;
    }else{
        pDNodeHDSP->pNext=listHDSP.pHead;
        listHDSP.pHead->pPrevious=pDNodeHDSP;
        listHDSP.pHead=pDNodeHDSP;
    }
}
//Hiện danh sách mua
void PrintSPMua(HoaDonSP hdsp){
    cout<<left<<setw(15)<<hdsp.MaSP<<" "<<left<<setw(8)<<hdsp.SLMua<<" "<<left<<setw(14)<<hdsp.ThanhTien<<" ";
}
void PrintHDSP(DoubleListHDSP listHDSP){
    DNodeHDSP *pTmp=listHDSP.pHead;
    while(pTmp!=NULL){
        PrintSPMua(pTmp->hd);
        pTmp=pTmp->pNext;
        if(pTmp!=NULL){
            cout<<"\n                 ";
        }
    }
}





// Khởi tạo đối tượng hóa đơn- khách hàng
struct HoaDonKH{
    string TenKH;
    DoubleListHDSP hdsp;
    double TongThanhTien;
};
// Tạo lk trước sau cho hóa đơn-khách hàng
struct DNodeHDKH{
    HoaDonKH hd;
    DNodeHDKH *pPrevious;
    DNodeHDKH *pNext;
};
//Tạo danh sách cho hoá đơn khách hàng
struct DoubleListHDKH{
    DNodeHDKH *pHead;
};
void InitializerHDKH(DoubleListHDKH &listHDKH){
    listHDKH.pHead=NULL;
}

//Hoá đơn khách hàng
DNodeHDKH *CreateNodeHDKH(HoaDonKH hd){
    DNodeHDKH *pDNodeHD=new DNodeHDKH;
    if(pDNodeHD!=NULL){
        pDNodeHD->hd=hd;
        pDNodeHD->pPrevious=NULL;
        pDNodeHD->pNext=NULL;
    }else{
        cout<<"Chèn thất bại"<<endl;
    }
    return pDNodeHD;
}
//Đếm kích cỡ sai hóa đơn-khách hàng
int SizeOfListHDKH(DoubleListHDKH list){
    int nSize=0;
    DNodeHDKH *pTmp=list.pHead;
    while(pTmp!=NULL){
        ++nSize;
        pTmp=pTmp->pNext;
    }
    return nSize;
}

HoaDonKH InputHDKH(DoubleListSP &listSP){
    DoubleListHDSP listHDSP;
    InitializerHDSP(listHDSP);
    HoaDonKH hd;
    cout<<"Ten khach hang:";cin>>hd.TenKH;
    cout<<"Da mua may loai san pham:";int SL;cin>>SL;cin.ignore();
    for(int i=0;i<SL;++i){
        ChenHDSPVaoDS(listHDSP,listSP,InputHDSP(listSP));
    }
    hd.hdsp=listHDSP;
    DNodeHDSP *pTmp=listHDSP.pHead;
    int TongThanhTien=0;
    while(pTmp!=NULL){
        TongThanhTien+=pTmp->hd.ThanhTien;
        pTmp=pTmp->pNext;
    }
    hd.TongThanhTien=TongThanhTien;
    return hd;
}

void ChenHDKHVaoDS(DoubleListHDKH &listHDKH,HoaDonKH hdkh){
    DNodeHDKH *pDNodeHDKH=CreateNodeHDKH(hdkh);
    if(listHDKH.pHead==NULL){
        listHDKH.pHead=pDNodeHDKH;
    }else{
        pDNodeHDKH->pNext=listHDKH.pHead;
        listHDKH.pHead->pPrevious=pDNodeHDKH;
        listHDKH.pHead=pDNodeHDKH;
    }
}

void TieuDeHDKH(){
    cout<<"Ten khach hang \t Ma san pham \t SL mua   Thanh tien \t Tong thanh toan"<<endl;
}
void PrintHDKH(HoaDonKH kh){
    cout<<left<<setw(16)<<kh.TenKH<<" ";
    PrintHDSP(kh.hdsp);
    cout<<setw(33)<<kh.TongThanhTien<<endl<<endl;
}

void HienDSHDKH(DoubleListHDKH listHDKH,DoubleListSP listSP){
    if(listHDKH.pHead==NULL){
        cout<<"Danh sach rong"<<endl;
    }else{
        DNodeHDKH *pTmp=listHDKH.pHead;
        TieuDeHDKH();
        while(pTmp!=NULL){
            PrintHDKH(pTmp->hd);
            pTmp=pTmp->pNext;
        }
    }
}
//Đọc ghi file HoaDon
//Ghi file
//Xoa hoa don theo ten khach hang
void RemoveByTenKH(DoubleListHDKH &listHDKH){
    cout<<"Nhap ten khach hang muon xoa:";
    string tenKH;
    cin>>tenKH;cin.ignore();
    DNodeHDKH *pDel=listHDKH.pHead;
    if(pDel==NULL){
        cout<<"Danh sach rong khong co hoa don";
    }
    DNodeHDKH *pPre=NULL;
    while(pDel!=NULL){
        if(pDel->hd.TenKH==tenKH)
            break;
        pPre=pDel;
        pDel=pDel->pNext;
    }
    if(pDel==NULL){
       cout<<"Ten khach hang ko ton tai";
    }else{
        if(pDel==listHDKH.pHead){
            if(listHDKH.pHead->pNext==NULL){
                DoubleListHDKH list;
                InitializerHDKH(list);
                listHDKH=list;
            }else{
                listHDKH.pHead=listHDKH.pHead->pNext;
                listHDKH.pHead->pPrevious=NULL;
                pDel->pNext=NULL;
            }
        }else if(pDel->pNext==NULL){
            pPre->pNext=NULL;
            pDel->pPrevious=NULL;
        }else{
            pPre->pNext=pDel->pNext;
            pDel->pNext->pPrevious=pPre;
            pDel->pPrevious=NULL;
            pDel->pNext=NULL;
        }
        delete pDel;
    }
}
//Tim kiem hoa don theo ten khach hang
DNodeHDKH *SearchHDKH(DoubleListHDKH listHDKH){
    cout<<"Nhap ten khach hang muon tim kiem:";
    string tenKH;cin>>tenKH;
    DNodeHDKH *pTmp=listHDKH.pHead;
    while(pTmp!=NULL){
        if(pTmp->hd.TenKH==tenKH)
            break;
        pTmp=pTmp->pNext;
    }
    if(pTmp==NULL){
        cout<<"Khong co hoa don co ten khach hang tren";
    }else{
        TieuDeHDKH();
    }
    return pTmp;
}
//Sắp xếp hóa đơn theo tên khách hàng
void SortListHDKH(DoubleListHDKH &listHDKH){
    if(listHDKH.pHead==NULL){
        cout<<"Danh sach rong";
    }else{
        for(DNodeHDKH *pTmp1=listHDKH.pHead;pTmp1!=NULL;pTmp1=pTmp1->pNext){
            for(DNodeHDKH *pTmp2=pTmp1->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
                if(pTmp1->hd.TenKH>pTmp2->hd.TenKH){
                    HoaDonKH tmp=pTmp1->hd;
                    pTmp1->hd=pTmp2->hd;
                    pTmp2->hd=tmp;
                }
            }
        }
    }
}
//Xóa danh sach hóa đơn khách hàng
void XoaDSHDKH(DoubleListHDKH &listHDKH){
    cout<<"Bat dau xoa"<<endl;
    while(listHDKH.pHead!=NULL){
        DNodeHDKH *pDel=listHDKH.pHead;
        listHDKH.pHead=listHDKH.pHead->pNext;
        pDel->pNext=NULL;
        pDel->pPrevious=NULL;
        PrintHDKH(pDel->hd);cout<<" dang xoa"<<endl;
        delete pDel;
    }
    cout<<"Xoa hoan tat"<<endl;
}










int main()
{
    DoubleListSP listSP;
    InitializerSP(listSP);
    DoubleListHDKH listHDKH;
    InitializerHDKH(listHDKH);
    int chon;
    do{
        cout<<setw(60)<<"MENU"<<endl<<endl;
        cout<<"1.San pham"<<endl;
        cout<<"2.Chi tiet hoa don"<<endl;
        cout<<"0.Ket thuc chuong trinh"<<endl;
        cout<<"\nChon dieu ban muon:";cin>>chon;cin.ignore();cout<<endl;
        switch(chon){
            case 1:
                int sp;
                do{
                    cout<<setw(60)<<"SAN PHAM"<<endl<<endl;
                    cout<<"1.Them san pham vao cua hang"<<endl;
                    cout<<"2.Hien danh sach san pham trong cua hang"<<endl;
                    cout<<"3.Ghi danh sach san pham vao file sanpham.txt"<<endl;
                    cout<<"4.Doc danh sach san pham tu file sanpham.txt"<<endl;
                    cout<<"5.Xoa san pham theo maSP"<<endl;
                    cout<<"6.Tim san pham theo maSP"<<endl;
                    cout<<"7.Sap xep san pham theo gia tang dan"<<endl;
                    cout<<"8.Cap nhat san pham"<<endl;
                    cout<<"9.Xoa danh sach san pham"<<endl;
                    cout<<"0.Quay lai"<<endl;
                    cout<<"\nChon dieu ban muon:";cin>>sp;cin.ignore();
                    switch(sp){
                        case 1:
                            ChenSPVaoDS(listSP,InPut());
                            break;
                        case 2:
                            HienDanhSachSP(listSP);
                            break;
                        case 3:
                            WriteFileSP(listSP,"sanpham.txt");
                            break;
                        case 4:
                            ReadFileSP(listSP, "sanpham.txt");
                            break;
                        case 5:
                            RemoveByMaSP(listSP);
                            break;
                        case 6:
                            PrintSP(SearchSP(listSP)->sp);
                            break;
                        case 7:
                            SortListSP(listSP);
                            break;
                        case 8:
                            UpdateSP(listSP);
                            break;
                        case 9:
                            XoaDSSP(listSP);
                            break;
                    }
                }while(sp!=0);
                break;
            case 2:
                int hd;
                do{
                    cout<<setw(60)<<"CHI TIET HOA DON"<<endl<<endl;
                    cout<<"1.Them hoa don vao cua hang"<<endl;
                    cout<<"2.Hien danh sach hoa don trong cua hang"<<endl;
                    cout<<"3.Ghi danh sach hoa don vao file hoadon.bin"<<endl;
                    cout<<"4.Doc danh sach hoa don tu file hoadon.bin"<<endl;
                    cout<<"5.Xoa hoa don theo ten khach hang"<<endl;
                    cout<<"6.Tim hoa don theo ten khach hang"<<endl;
                    cout<<"7.Sap xep hoa don theo ten khach hang"<<endl;
                    cout<<"8.Xoa danh sach hoa don"<<endl;
                    cout<<"0.Quay lai"<<endl;
                    cout<<"\n Nhap dieu ban muon:";cin>>hd;cin.ignore();
                    switch(hd){
                        case 1:
                            ChenHDKHVaoDS(listHDKH,InputHDKH(listSP));
                            break;
                        case 2:
                            HienDSHDKH(listHDKH,listSP);
                            break;
                        case 3:

                            break;
                        case 4:

                            break;
                        case 5:
                            RemoveByTenKH(listHDKH);
                            break;
                        case 6:
                            PrintHDKH(SearchHDKH(listHDKH)->hd);
                            break;
                        case 7:
                            SortListHDKH(listHDKH);
                            break;
                        case 8:
                            XoaDSHDKH(listHDKH);
                            break;
                    }
                }while(hd!=0);
                break;
        }
    }while(chon!=0);
    return 0;
}
