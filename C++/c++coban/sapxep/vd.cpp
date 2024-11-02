#include <bits/stdc++.h>
using namespace std;

int tinhtong(int n){
    int res=0;
    while(n>0){
        int tmp=n%10;
        n/=10;
        res+=tmp;
    }
    return res;
}

bool cmp(int a, int b){
    if (tinhtong(a)!=tinhtong(b)) return tinhtong(a) < tinhtong(b);
    else return a>b;
}

int main(){
    // int a[7]={4, 7, 23, 92, 10, 55, 46};
    int a[6]={323, 62, 152, 1001, 8, 17};
    sort(a, a+6, cmp);
    for (int x:a){
        cout << x << ' ';
    }
}