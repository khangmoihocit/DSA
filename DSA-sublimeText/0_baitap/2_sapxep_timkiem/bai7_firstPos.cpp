#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

int firstPos(int a[], int n, int x){
	int left = 0, right = n-1, res = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(a[mid] == x){
			res = mid + 1;
			right = mid - 1;
		}else if(a[mid] > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return res;
}
int main(){
	int q; cin >> q;
	while(q--){
		int n, x; cin >> n >> x;
		int a[n];
		for(int i=0; i<n; ++i) cin >> a[i];

		cout << firstPos(a, n, x) << endl;
	}
	return 0;
}