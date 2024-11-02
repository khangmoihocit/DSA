#include "bits/stdc++.h"
using namespace std ;
struct kh{
    char thangthu[10];
   char makh[10];
   char hoten[10];
   char diachi[10];
   int dntt;
};

void hienkh(kh a){
    cout<<setw(8)<<setiosflags(ios::left)<<a.thangthu
        <<setw(8)<<setiosflags(ios::left)<<a.makh
        <<setw(8)<<setiosflags(ios::left)<<a.hoten
        <<setw(8)<<setiosflags(ios::left)<<a.diachi
        <<setw(8)<<setiosflags(ios::left)<<a.dntt<<endl;
}
void nhapdskh(kh a[], int n)
{
    for (int i=0;i<n;++i)
    {
    cin.ignore() ;
    cout << "thang thu:";cin.getline(a[i].thangthu,10);
    cout << "mskh:"; cin.getline(a[i].makh,10) ;
    cout << "hoten:";cin.getline(a[i].hoten,10);
    cout << "ngaysinh:";cin.getline(a[i].diachi,10);
    cout << "gtinh:"; cin >> a[i].dntt ;
    }
}
void hiendskh(kh a[], int n){
    cout<<"\n"<<setw(8)<<setiosflags(ios::left)<<"thangthu:"
        <<setw(8)<<"mskh"
        <<setw(8)<<"hoten"
        <<setw(8)<<"diachi"
        <<setw(8)<<"dntt"<<endl;
    for (int i=0;i<n;++i)
        hienkh(a[i]);
}
void ghifile(kh a[],int n){
    ofstream f;
    f.open("kh.dat",ios::out|ios::binary);
    for (int i=0;i<n;++i)
    f.write((char*)&a[i], sizeof(kh));
    f.close();
}
void docfile(kh a[],int &n ){
    ifstream fff ;
    fff.open("kh.dat",ios::in|ios::binary);
    n=0 ;
    while(!fff.eof()){
        fff.read((char*)&a[n],sizeof(kh));
        if(fff.gcount()>0) ++n ;
    }
    
}



int main (){
    nv a[100];int n; cin >> n;
    nhapdskh(a,n);
    hiendskh(a,n);
    ghifile(a,n);
    docfile(a,n);
    return 0 ;

}

