#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>

int main(){
	int n; cin >> n;
	vector<pair<char, int>> v;
	for (int i=0; i<n; ++i){
		char x; cin >> x;
		bool check = true;
		for (int j=0; j<v.size(); ++j){
			if (x == v[j].first){
				v[j].second ++;
				check = false;
			}
		}
		if (check){
			v.push_back({x, 1});
		}
	}
	cout << v.size() << endl;
	for (pair<char, int> x : v){
		cout << x.first << " " << x.second << endl;
	}
}