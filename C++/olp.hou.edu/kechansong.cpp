#include<bits/stdc++.h>
using namespace std;

void check(int a[], int b[], int n, int q, int &res){
    for (int i=0; i<n; ++i){
        if (a[i]>q){
            b[res++]=a[i];  // sao chep cac so thoa man dk
        }
    }
}

void hien(int b[], int res){
    for (int i=0; i<res; ++i){
        cout << b[i] << " ";
    }
}

void sapxep(int b[], int res){
    for (int i=0; i<res-1; i++){
        for (int j=i+1; j<res; j++){
            if (b[i]<b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}
int main(){
    int n=7;
    int q=10;
    int a[7]={1, 7, 8, 2, 9, 4};
    int b[7];
    int res=0;
    check(a, b, n, q, res);
    if (res==0) cout << "FAIL";
    else {
        sapxep(b, res);
        cout << endl;
        hien(b, res);
        cout << endl << res;
    }
}