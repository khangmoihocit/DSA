#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
typedef long long ll;
int main(){
	int n; cin >> n;
	ll tong = 0;
	int a[n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
		tong += a[i];
	}

	ll min1 = LLONG_MAX;
	ll tong_a = 0;
	for(int i=0; i < n - 1; ++i){
		tong_a += a[i];
		ll tong_b = tong - tong_a;
		ll x = abs(tong_a-tong_b);
		min1 = min(min1, x);
	}
	cout << min1;
	return 0;
}