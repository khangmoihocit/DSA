#include "bits/stdc++.h"
using namespace std;
void nhap(int a[][100], int n, int m){
     for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
}
void hien(int a[][100], int n, int m){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j)
            cout << a[i][j] << " ";
            cout << endl;
    }
}
void chen(int a[][100], int& n, int& m, int giatri, int k, int h){
    for (int i=n; i>k; --i){
        for (int j=m; j>h; --j){
            a[i][j]=a[i-1][j-1];
        }    
    }
    a[k][h]=giatri;
    ++n;
    ++m;
}
void xoa(int a[][100], int n, int m){
    int h, c;
    cin >> h >> c;
    for (int i=h; i<n-1; ++i){
        for (int j=c; i<m; ++j){
            a[i][j]=a[i+1][j];
        }
    }
    n--;
    m--;
}



int main(){
    int a[100][100];
    int n=3; int m=3;
    nhap(a, n, m);
    hien(a, n, m);
    cout << endl;
    // chen;
    int k, h;
    cout << "nhap so hang muon chen: "; cin >> k; k--;
    cout << "nhap so cot muon chen: "; cin >> h; h--;
    int giatri;
    cout << "nhap gia tri muon chen: "; cin >> giatri;
    chen(a, n, m, giatri, k, h);
    hien(a, n, m);
    // xoa 1 phan tu;
    cout << endl;
    xoa(a, n, m);
    hien(a, n, m);
    return 0;
}