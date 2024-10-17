#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int x){
    for(int i=0; i<n; ++i){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n = 7;
    int a[n] = {3, 5, 1, 7, 9, 1, 4};
    int pos = linearSearch(a, n, 7);
    cout << pos;
}