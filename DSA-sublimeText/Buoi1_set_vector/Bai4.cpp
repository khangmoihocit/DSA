#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	multiset<int> se;
	for (int i=0; i<n; ++i){
		int tmp; cin >> tmp;
		se.insert(tmp);
	}	
	int q; cin >> q;
	for (int i=0; i<q; ++i){
		int x, y; cin >> x >> y;
		if(x == 1){
			se.insert(y);
		}
		if(x == 2){
			auto it = se.find(y);
			if (it != se.end()){
				se.erase(distance(se.begin(), it));
			}
		}
		if(x == 3){
			if (se.find(y) != se.end()){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
}