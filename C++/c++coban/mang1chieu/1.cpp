#include "bits/stdc++.h"
using namespace std;
void sapxep(int a[], int n){
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<n; ++j){
            if (a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void hien(int a[], int n){
     for (int i=0; i<n; ++i) cout << a[i] << " ";
}
void chen(int a[], int n){
    int k, x;
    cout << "nhap vi tri can chen: "; cin >> k; --k;
    cout << "nhap so can chen: "; cin >> x;
    // dich chuyen mang sang 1 don vi de chen
    for (int i=n; i>k; --i){
            a[i]=a[i-1];
    }
    a[k]=x;
    n++;
}
void xoa(int a[], int n){
    int k;
    cout << "nhap vi tri muon xoa: "; cin >> k;
    for (int i=k; i<n; ++i){
        a[i]=a[i+1];
    }
    n--;
}

int main(){
    int a[20]={-3, 9, -8, 13, -8, 5, 20, -19, -8};
    for (int i=0; i<10; ++i) cout << a[i] << " " << endl;
    sapxep(a, 10); cout << "mang sau khi sap xep tang dan la: ";
    hien(a, 10);
    cout << endl;
    chen(a, 20);
    hien(a, 11);
    cout << endl;
    xoa(a, 10);
    hien(a, 10);
}