#include <bits/stdc++.h>
using namespace std;

void mang(){
    int a[4]={3, 5, 9, 1};

    sort(a, a+4); // sắp xếp tăng dần
    sort (a, a+4, greater<int>()); // sắp xếp giảm dần
    for (int x : a){
        cout << x << " ";
    }
}

// sap xep tu chi so x den y
sort(a+x, a+y+1)

void vector1(){
    cout << endl;
    int n=6;
    vector<int>a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());   // giảm dần thì thêm greater<int>() 
    for (int x:a){
        cout << x << " ";
    }
}
int main(){
    mang();
    vector1();
    return 0;
}