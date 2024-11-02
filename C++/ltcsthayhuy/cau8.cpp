#include <bits/stdc++.h>
using namespace std;
void nhaphien(int a[][100], int n, int m){
    cout << "nhap ma tran:" << endl;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "ma tran vua nhap la: " << endl;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j)
            cout << a[i][j] << " ";
            cout << endl;
    }
}
int gtnn(int a[][100], int x, int m){
    int tg=100;
    for (int j=0; j<m; j++){
        if (a[x][j]<tg) tg=a[x][j];
    }
    return tg;
}
int tongcot(int a[][100], int n, int c){
    int res=0;
    for (int i=0; i<n; ++i){
        res+=a[i][c];
    }
    return res;
}
bool check(int a[][100], int n, int m){
    bool khoitao=false;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (a[i][j]>0){
                khoitao=true;
                cout << a[i][j] << " ";
            }
        }
    }
    return khoitao;
}
int dem(int a[][100], int n, int m){
    int sum=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (a[i][j]<0) ++sum;
        }
    }
    return sum;
}

int main(){
    int n, m;
    cout << "nhap so hang: "; cin >> n;
    cout << "nhap so cot: "; cin >>m;
    int a[100][100];
    nhaphien(a, n, m);
    // tim gtnn
    int x;
    cout << endl << "nhap so hang muon tim GTNN: "; cin >> x; x--;
    cout << "-->GTNN la: " << gtnn(a, x, m) << endl;
    // tinh tong cot
    int c;
    cout << endl << "nhap so cot muon cong: "; cin >> c; c--;
    cout << "-->tong la: " << tongcot(a, n, c) << endl;
    // liet ke phan tu duong
    cout << endl;
    if (check(a, n, m)) cout << "la cac so nguyen duong.";
    else cout << "khong ton tai so nguyen duong.";
    // dem so phan tu am
    cout << endl << "so phan tu nguyen am la: " << dem(a, n, m);
    return 0;
}