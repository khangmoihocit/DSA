#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>
#define pi pair<int, int>

void viTri(vector<pair<int, int>> &v, int &n){
	for (int i=0; i<v.size(); ++i){
		if (n == v[i].first){
			v[i].second ++;
			return;
		}
	}
	v.push_back({n, 1});
}

int main(){
	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		bool ktra = false;
		for (int j=0; j<v.size(); j++){
			if (v[j].first == x){
				v[j].second ++;
				ktra = true;
			}
		}
		if (ktra == false){
			v.push_back({x, 1});
		}
	}

	for (auto x : v){
		cout << x.first << " " << x.second << endl;
	}

}