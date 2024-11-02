#include "bits/stdc++.h"
using namespace std;
struct DA{
    char mada[20],tenda[20], donvi[20];
    int  kinhphi;
};
void nhapDA(DA &a){
    cin.ignore(1); //sử dụng cin.ignore() và fflush() khi nhập từ số sang chữ
    cout << "\n ma du an: ";
    cin.getline(a.mada,20);
    cout << "\n ten du an: ";
    cin.getline(a.tenda,20);
    cout << "\n don vi: ";
    cin.getline(a.donvi,20);
    cout << "\n kinh phi: "; cin >> a.kinhphi;
}
void hienDA(DA a){
    cout << endl << setw(20)<< setiosflags(ios::left)<< a.mada
    << setw(20)<< setiosflags(ios::left)<< a.tenda
    << setw(20)<< setiosflags(ios::left)<< a.donvi
    << setw(20)<< setiosflags(ios::left)<< a.kinhphi;
}
void nhapdsDA(DA a[], int n){
    for(int i=0; i<n; ++i){
        nhapDA(a[i]);
    }

}
void hiendsDA(DA a[], int n){
   cout << endl << setw(20)<< setiosflags(ios::left)<< "ma du an"
    << setw(20)<< setiosflags(ios::left)<< "ten du an"
    << setw(20)<< setiosflags(ios::left)<< "don vi"
    << setw(20)<< setiosflags(ios::left)<< "kinh phi";
    for(int i=0; i<n; ++i){
        hienDA(a[i]);
    }
}
void dakpcaonhat(DA a[], int n){
    int kinhphicaonhat= a[0].kinhphi;
    for (int i = 1; i < n; ++i) {
        if (a[i].kinhphi > kinhphicaonhat) {
           kinhphicaonhat = a[i].kinhphi;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].kinhphi == kinhphicaonhat) {
            // cout << "Ten du an: " << a[i].tenda << ", kinh phi: " << a[i].kinhphi<< endl;
            cout << endl << setw(20)<< setiosflags(ios::left)<< "ma du an"
                         << setw(20)<< setiosflags(ios::left)<< "ten du an"
                         << setw(20)<< setiosflags(ios::left)<< "don vi"
                         << setw(20)<< setiosflags(ios::left)<< "kinh phi";
            hienDA(a[i]);
        }
    }
}
void duancuacntt(DA a[], int n){
    cout << endl << "cac du an cua don vi cntt la: " << endl;
    cout << endl << setw(20)<< setiosflags(ios::left)<< "ma du an"
                 << setw(20)<< setiosflags(ios::left)<< "ten du an"
                 << setw(20)<< setiosflags(ios::left)<< "don vi"
                 << setw(20)<< setiosflags(ios::left)<< "kinh phi";
    for(int i=0; i<n; ++i){
        if(strcmp(a[i].donvi, "cntt")==0){ // so sanh neu a[i].don=="cntt" thi thuc hien 
            hienDA(a[i]);
        }
    }
}
void ghiFile(DA a[], int n){
    ofstream fout;
    fout.open("duan.dat", ios::out|ios::binary);
    if(!fout.is_open()){
        cout << "\n loi mo tep";
        // thiếu return;
        return;
    }
    for(int i=0; i<n; ++i){
        fout.write((char *)&a[i], sizeof(DA));
    }
    cout << "\nghi tep thanh cong";
}
void docFile(DA a[], int n){
    ifstream fin;
    fin.open("duan.dat", ios::in|ios::binary);
    if(!fin.is_open()){
        cout << "\n loi mo tep";
        fin.close();
    }
    //đọc file 
    n = 0;
    while (!fin.eof()){ 
        fin.read((char*)&a[n], sizeof(DA)); 
        if (fin.gcount() > 0) n++; // ....gcount(): để trả về số lượng ký tự đã đọc hoặc ghi từ lần cuối cùng 
                    // nếu lớn hơn 0 là đã file đã được đọc và ++n để thực hiện tiếp vòng while.
    }
    cout << "\ndoc file thanh cong!";
}


int main(){
    DA a[100];
    int n;
    cout << "\n nhap so luong du an: ";
    cin >> n;
    nhapdsDA(a,n);
    hiendsDA(a,n);
    cout << "\n du an co kinh phi cao nhat: ";
    dakpcaonhat(a,n);
    duancuacntt(a,n);
    ghiFile(a,n);
    docFile(a,n);
}