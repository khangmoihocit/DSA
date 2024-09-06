#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) cin >> b[i];

	set<int> se1(a, a + n);
	set<int> se2(b, b + n);
	set<int> v;
	for(int x : b){
		if(se1.find(x) != se1.end()){
			v.insert(x);
		}
	}
	set<int> output;
	for (int x : se1){
		if (v.find(x) == v.end()){
			output.insert(x);
		}
	}
	for (int x : se2){
		if (v.find(x) == v.end()){
			output.insert(x);
		}
	}
	for (int x : output){
		cout << x << " ";
	}
}