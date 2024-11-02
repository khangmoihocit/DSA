#include "bits/stdc++.h"
using namespace std;
void nhap(int a[][100], int n, int m){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void hien(int a[][100], int n, int m){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void hienhangk(int a[][100], int k, int m){
    for (int j=0; j<m; ++j){
        cout << a[k][j] << " ";
    }
}

int tinhtong(int a[][100], int n, int k){
    int s=0;
    for (int i=0; i<n; ++i){
        s += a[i][k]; 
    }
    return s;
}

void vitri(int a[][100], int n, int m, int z){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (a[i][j]==z){
                ++i;
                ++j;
                cout << "(" << i << ";" << j << ")";
                break;
            }
        }
    }
}

int vitritongmax(int a[][100], int n, int m){
    int s=0;
    int tg=0;
    int vitri;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            s+=a[i][j];
        }
        if (s>tg){
            tg=s;
            vitri=i;
        }
    }
    return ++vitri;
}

int main(){
    int a[100][100];
    int n, m;
    cout << "nhap so hang: "; cin >> n;
    cout << "nhap so cot: "; cin >>m;
    nhap(a, n, m);
    cout << "ma tran vua nhap la: " << endl;
    hien(a, n, m);
    int k;
    cout << endl << "nhap so hang muon hien: "; cin >> k; --k;
    hienhangk(a, k, m);
    int h;
    cout << endl << "nhap cot muon cong: "; cin >> h; --h;
    cout << "-->Tong la: "<< tinhtong(a, n, h);
    int x;
    cout << endl << "nhap gia tri muon tim: "; cin >> x;
    cout << "-->vi tri dau tien x xuat hien la: "; vitri(a, n, m, x);
    cout << endl << "-->hang co tong lon nhat la: " << vitritongmax(a, n, m);
    return 0;
}