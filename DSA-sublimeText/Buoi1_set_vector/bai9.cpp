#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	set<int> se;
	int a[n]; int b[m];
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) cin >> b[i];

	for(int x : a) se.insert(x);
	for(int x : b) se.insert(x);

	for (auto it = se.rbegin(); it!=se.rend(); ++it){
		cout << *it << " ";
	}

}