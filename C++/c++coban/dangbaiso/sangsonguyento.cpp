#include "bits/stdc++.h"
using namespace std;
// de sang duoc snt < n 
// thi phai tao duoc mang co co n+1 phan tu 
int n=1000000;
bool nt[1000001];
void sang(){
    for (int i=0; i<=n; ++i){    //khoi tao luc dau all la snt
        nt[i]=true;
    }
    nt[0]=nt[1]=false;          // 0 va 1 k la snt
    for (int i=2; i<=sqrt(n); ++i){ 
        if (nt[i]==true){       // neu la so nt thi boi cua no khong la snt
            for (int j=i*i; j<=n; j+=i){
                nt[j]=false;        // cho boi k la snt
            }
        }
    }
}
int main(){
    sang();
    int a;
    cout << "nhap so nt: "; cin >> a;
    for (int i=0; i<=a; i++){  // hien ra snt neu trong mang nt[...] =true la snt
        if (nt[i]==true) cout << i << " "; 
    }
}