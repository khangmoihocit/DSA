#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>

int main(){
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		set<int> se;
		for (int i=0; i<n; ++i){
			int x; cin >> x;
			se.insert(x);
		}
		cout << se.size() << endl;
	}
}