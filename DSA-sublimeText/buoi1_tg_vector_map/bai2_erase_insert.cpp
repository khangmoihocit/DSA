#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v;
	for (int i=0; i<n; ++i){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}

	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		if (x == 1){
			int pos, val; cin >> pos >> val;
			if(pos >= 0 && pos <= v.size()){
				v.insert(v.begin() + pos, val);
			}
		}
		if (x == 2){
			int pos; cin >> pos;
			if(pos >= 0 && pos <= v.size()){
				v.erase(v.begin() + pos);
			}
		}
	}
	
	if(v.size() == 0) cout << "EMPTY";
	else{
		for (int x : v){
			cout << x << " ";
		}
	}
	
}