#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
    int pos = 0;
    int x;
    for(int i=1; i<n; ++i){
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos-1] > x); pos--){
            a[pos] = a[pos - 1];
        }
        a[pos] = x;
    }
}

void insertionSort_2(int a[], int n){
    int vitrimin;
    for(int i=0; i<n; ++i){
        vitrimin = i;
        for(int j=i+1; i<n; ++j){
            if(a[j] < a[vitrimin]){
                vitrimin = j;
            }
        }
        
    }
}

int main(){
    int n = 7;
    int a[n] = {2, 5, 1, 6, 2, 8, 3};
    insertionSort(a, n);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}