#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "nhap n: "; cin >> n;
    long long a[100];
    a[0]=a[1]=1;
    for (int i=2; i<n; ++i){
        a[i]=a[i-1]+a[i-2];
    }
    cout << "day Fibonaci voi " << n << " so hang dau tien: ";
    for (int i=0; i<n; ++i)
    cout << a[i] << " ";
}