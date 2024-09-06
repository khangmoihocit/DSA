#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i=0; i<n; ++i){
		int x, y; cin >> x >> y;
		v.push_back({x, y});
	}
	vector<float> vf;
	for (pair<int, int> p : v){
		float result = sqrt((p.first*p.first) + (p.second * p.second));
		vf.push_back(result);
	}
	for(float x : vf){
		cout << fixed << setprecision(2) << x << " ";
	}
}