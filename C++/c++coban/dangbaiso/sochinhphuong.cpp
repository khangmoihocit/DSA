#include <bits/stdc++.h>
using namespace std;
bool ktra(int n){
    int a=sqrt(n);
    if (a*a==n) return true;
    else return false;
}
int main(){
    int n;
    cout << "nhap so nguyen n: "; cin >> n;
    if (ktra(n)) cout << n << " la so chinh phuong.";
    else cout << n << " khong phai la so chinh phuong.";
    return 0;
}