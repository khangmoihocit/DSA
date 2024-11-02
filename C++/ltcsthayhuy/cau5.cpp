#include <bits/stdc++.h>
using namespace std;
bool ktra(int n){
    float a=sqrt(n);
    if (a*a==n) return true;
    else return false;
}
int main(){
    int n;
    cout << "nhap so nguyen n: "; cin >> n;
    if (ktra(n)) cout << n << "\nyes";
    else cout << n << "\nno";
}