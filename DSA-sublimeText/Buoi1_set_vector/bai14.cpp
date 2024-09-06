#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];

	int q; cin >> q;
	while(q--){
		set<int> se;
		int x; cin >> x;
		for (int i=x; i<n; ++i){
			se.insert(a[i]);
		}
		cout << se.size() << endl;
	}
}