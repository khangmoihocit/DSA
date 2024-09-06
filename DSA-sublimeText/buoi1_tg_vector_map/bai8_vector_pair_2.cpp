#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>
int main(){
	int n; cin >> n;
	vector<ppi> vp;
	for(int i=0; i<n; ++i){
		int x, y, z; cin >> x >> y >> z;
		vp.push_back({{x, y}, z});
	}

	vector<int> v;
	for(auto x : vp){
		int sum = 0;
		sum = x.first.first + x.first.second + x.second;
		v.push_back(sum);
	}

	for (int x : v){
		cout << x << " ";
	}


}
