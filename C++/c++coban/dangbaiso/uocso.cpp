#include <bits/stdc++.h>
using namespace std;
int dem(int n){
    int uoc=0;
    for (int i=1; i<=sqrt(n); ++i){
        if (n%i==0){
            ++uoc;
            if (i!=n/i) ++uoc;
        }
    }
    return uoc;
}
int main(){
    int n;
    cin >> n;
    cout << dem(n);
}