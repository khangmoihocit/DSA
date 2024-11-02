#include "bits/stdc++.h"
using namespace std;
bool nt(int a, int b){
    while (a!=b){
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    if (a==1) return true;
    else return false;
}
int main(){
    int a, b;
    cin >> a >> b;
    if(nt(a, b)) cout << a << " va " << b << " la 2 so nguyen to cung nhau!";
    else cout << a << " va " << b << " khong la 2 so nguyen to cung nhau!";
}