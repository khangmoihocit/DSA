#include "bits/stdc++.h"
using namespace std;
int main(){
    // dung trong toa do 
    int n; cin >> n;
    pair<int, int> a[100];
    for (int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for (int i=0; i<n; ++i){
        cout << a[i].first << ' ' << a[i].second << "\t";
    }
}