#include "bits/stdc++.h"
using namespace std;
struct xe{
    int stt;
    char tenxe[10];
    char mauxe[10];
    int chongoi;
    int namsx;
    float giathue;
};

void nhapxe(xe &a){
    cout << "so thu tu: "; cin >> a.stt;
    cin.ignore(1);
    cout << "ten xe: "; cin.getline(a.tenxe, 10);
    cout << "mau xe: "; cin.getline(a.mauxe, 10);
    cout << "so cho ngoi: "; cin >> a.chongoi;
    cout << "nam san xuat: "; cin >> a.namsx;
    cout << "gia thue xe: "; cin >> a.giathue;
}

void hienxe(xe a){
    cout << setw(5) << a.stt
         << setw(10) << a.tenxe
         << setw(10) << a.mauxe
         << setw(15) << a.chongoi
         << setw(15) << a.namsx
         << setw(15) << a.giathue;
}

void nhapdsxe(xe a[], int n){
    for (int i=0; i<n; ++i){
        nhapxe(a[i]);
    }
}

void hiendsxe(xe a[], int n){
    cout << setw(5) << setiosflags(ios::left) << "stt"
         << setw(10) << setiosflags(ios::left) << "ten xe"
         << setw(10) << setiosflags(ios::left) << "mau xe"
         << setw(15) << setiosflags(ios::left) << "so cho ngoi"
         << setw(15) << setiosflags(ios::left) << "nam san xuat"
         << setw(15) << setiosflags(ios::left) << "gia thue xe" << endl;
    for (int i=0; i<n; ++i){
        hienxe(a[i]);
        cout << endl;
    }
}

void timxe(xe a[], int n){
    cout << setw(5) << setiosflags(ios::left) << "stt"
         << setw(10) << setiosflags(ios::left) << "ten xe"
         << setw(10) << setiosflags(ios::left) << "mau xe"
         << setw(15) << setiosflags(ios::left) << "so cho ngoi"
         << setw(15) << setiosflags(ios::left) << "nam san xuat"
         << setw(15) << setiosflags(ios::left) << "gia thue xe" << endl;
    // sap xep gia giam dan
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
           if (a[i].giathue < a[j].giathue){
                swap(a[i].giathue, a[j].giathue);
            }
        }
    }
    // chi hien xe 5 cho
    for (int i=0; i<n; ++i){
        if (a[i].chongoi==5){
            hienxe(a[i]);
            cout << endl;
        }
    }
}

int main(){
    xe a[20];
    int n;
    cout << "nhap so luong danh sach: "; cin >> n;
    nhapdsxe(a, n);
    cout << "danh sach xe: " << endl;
    hiendsxe(a, n);
    cout << endl << "danh sach xe 5 cho ngoi sap xep giam dan: " << endl;
    timxe(a, n);
    return 0;
}