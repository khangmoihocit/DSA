#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

// 4
// 6 -3 0 4
// tim khoang cach nho nhat giua 2 phan tu, va in ra cac cap nho nhat
int main(){
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	
	int dem = 0;
	int min_int = INT_MAX;
	for(int i=0; i<n-1; ++i){
		if(a[i+1] - a[i] < min_int){
			min_int = a[i+1] - a[i];
		}
	}
	for(int i=0; i<n; ++i){
		if(a[i+1] - a[i] == min_int){
			++dem;
		}
	}
	cout << min_int << " " << dem;
	return 0;
}