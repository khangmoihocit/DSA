#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>

int main(){
	int n; cin >> n;
	set<int> se;
	for(int i=0; i<n; ++i){
		int x; cin >> x;
		se.insert(x);
	}
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		if (se.find(x) != se.end()){
			cout << "YES" << endl;
		}else{
			cout << "NO\n";
		}
	}
}