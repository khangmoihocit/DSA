#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    if (n<2) return false;
    for (int i=2; i<=sqrt(n); ++i){
        if (n%i==0) return false; // neu n ma chia het cho so tu 2 --> n thi sai
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for (int i=3; i<=n; ++i){
        if (check(i))
            cout << i << " ";
    }
}