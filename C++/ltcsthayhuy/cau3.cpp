#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a;
    cin >> n;
    if (n>999 && n<=9999){
        a=n%10;
        cout << a;
    }
    else cout << "vui long nhap so co 4 chu so!";
    return 0;
}