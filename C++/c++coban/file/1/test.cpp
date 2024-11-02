#include "bits/stdc++.h"
using namespace std;
struct sv{
    int stt;
    string hvt;
    string lop;
};

void nhap(sv &a){
    cout << "so thu tu: "; cin >> a.stt;
    cin.ignore(1);
    cout << "nhap ho ten: "; getline(cin, a.hvt);
    cout << "nhap lop: "; getline(cin, a.lop);
}

void hien(sv a){
    cout << setw(4) << a.stt
         << "\t" << setw(15) << a.hvt
         << "\t" << setw(5) << a.lop << endl;
}

void nhapds(sv arr[], int n){
    for (int i=0; i<n; ++i){
        nhap(arr[i]);
    }
}

void hiends(sv arr[], int n){
    cout << setw(4) << setiosflags(ios::left) << "STT"
         << "\t" << setw(15) << "ho va ten"
         << "\t" << setw(5) << "lop" << endl;
    for (int i=0; i<n; ++i){
        hien(arr[i]);
    }
}

fstream f;
void ghifile(sv arr[], int n){
    f.open("danhsachsv.txt", ios::out|ios::binary);
    if (!f.is_open()){
        cout << "loi mo tep";
        return;
    }
    for (int i=0; i<n; ++i){
        f.write((char *)&arr[i], sizeof(sv));
    }
    cout << "\nghi tep thanh cong!";
    f.close();
}

void docfile

int main(){
    sv arr[10];
    int n;
    cout << "nhap so luong sinh vien: "; cin >> n;
    nhapds(arr, n);
    hiends(arr, n);
    ghifile(arr, n);
    docfile(arr, n);
}
