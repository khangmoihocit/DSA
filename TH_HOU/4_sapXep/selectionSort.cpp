#include <bits/stdc++.h>
using namespace std;

//n(n - 1) / 2
void selectionSort(int a[], int n){
    int min;
    for(int i=0; i<n-1; ++i){
        min = i;
        for(int j=i+1; j<n; ++j){ //tìm vị trí nhỏ nhất trong dãy còn lại
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

int main(){
    int n = 7;
    int a[n] = {2, 5, 1, 6, 2, 8, 3};
    selectionSort(a, n);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}