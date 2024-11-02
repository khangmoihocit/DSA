#include <bits/stdc++.h>
using namespace std;
bool ktra(char a[], char x){  // ktra ki tu x co ton tai trong xau k?
    for (int i=0; i<=strlen(a); ++i){
        if (x==a[i]) 
            return true;
    }
    return false;
}
int main(){
    char a[80];
    cout << "nhap 1 xau bat ky: ";
    cin.getline(a, 80);
    char x;
    cout << "nhap 1 ky tu de ktra: "; cin >> x;
    if (ktra(a, x)) cout << "yes";
    else cout << "no";
    return 0;
}