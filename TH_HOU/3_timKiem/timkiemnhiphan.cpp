#include<bits/stdc++.h>
using namespace std;

//ap dung cho mang da sap xep
int binarySearch(int a[], int n, int x){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x){
            return mid;
        }else if(a[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n = 7;
    int a[n] = {1, 2, 4, 7, 7, 7, 9};
    int pos = binarySearch(a, n, 7);
    cout << pos;
}