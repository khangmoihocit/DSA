#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;
//các số khác nhau trong mảng
int main(){
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	int count=1;
	for(int i=1; i<n; ++i){
		if(a[i] != a[i-1]){
			++count;
		}
	}
	cout << count;
	return 0;
}