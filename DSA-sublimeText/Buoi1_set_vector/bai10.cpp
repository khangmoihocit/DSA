#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) cin >> b[i];

	set<int> se1;
	vector<int> v;
	for (int x : b) se1.insert(x);
	for (int x : a) v.push_back(x);

	for(int x : v){
		if (se1.find(x) != se1.end()){
			cout << x << " ";
		}
	}

}