#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right){
    int i = left, j = right;
    int pivot = arr[(left + right)/2];
    while(i <= j){
        while(arr[i] < pivot) i++; //tìm phần tử lớn hơn pivot
        while(arr[j] > pivot) j--; //tìm phần tử nhỏ hơn pivot
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(left < j) quickSort(arr, left, j);
    if(i < right) quickSort(arr, i, right);
}

int main(){
    int n = 7;
    int arr[7] = {3, 5, 8, 1, 2, 9, 4};
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}