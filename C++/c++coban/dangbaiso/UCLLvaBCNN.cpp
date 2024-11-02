#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){   // khi b=0 thi uoc chung lon nhat la a;
    while (b!=0){       // (a, a%b) a la UCLN khi a%b=0;
        int du=a%b;
        a=b;
        b=du;
    }
    return a;
}
int lcm(int a, int b){   // tim BCNN
    return a/gcd(a, b) * b;
}
int main(){
    cout << gcd(10, 15) << endl;
    cout << __gcd(20, 40) << endl;
    cout << lcm(2, 3);
}