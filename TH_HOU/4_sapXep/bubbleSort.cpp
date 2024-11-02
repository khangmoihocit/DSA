#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i=0; i<n-1; ++i){
        for(int j=n-1; j>i; j--){
            if(a[j] < a[j-1]){ 
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

int main(){
    int n = 7;
    int a[n] = {15, 7, 23, 19, 25, 8, 31};
    bubbleSort(a, n);
    for(int i=0; i<n; ++i){
        cout << a[i] << " ";
    }

}