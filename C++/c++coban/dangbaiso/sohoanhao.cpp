#include <bits/stdc++.h>
using namespace std;
//số hoàn hảo là số có tổng các ước bằng chính nó
bool sohoanhao(int n){
    int res=0;
    for (int i=1; i<=sqrt(n); ++i){  // duyet n chia het den sqrt(n)
        if (n%i==0){                 
            res+=i;                  // tong so uoc 
            if (i!=n/i) res+=n/i;    // tong so uoc con lai khong trung
        }
    }
    if (res-n==n) return true;
    else return false;
}
int main(){
    int n;
    cout << "nhap so: "; cin >> n;
    if (sohoanhao(n)) cout << "yes";
    else cout << "no";
}