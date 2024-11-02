#include <bits/stdc++.h>
using namespace std;
//tim kiem tuyen tinh: linear search : o(n);
// tim kiem nhi phan: binary search: o(logN) da duoc sap xep tang dan hoac giam dan
//binary search animation

bool search(int a[], int n, int x){
	int left = 0, right = n - 1;
	while(left <= right){ 
		int mid = (left + right) / 2;
		if (a[mid] == x){
			return true;
		}
		else if (a[mid] < x){
            //tim o ben phai mid
			left = mid + 1;
		}
		else {
            //tim o ben trai mid
			right = mid - 1;
		}
	}
	return false;
}

// binary_search(a, a+n, x)
// binary_search(a.begin(), a.end(), x)



int main(){
	int n,x ; cin >> n >> x;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	if (search(a, n, x)) cout << "Yes";
	else cout << "no";


}