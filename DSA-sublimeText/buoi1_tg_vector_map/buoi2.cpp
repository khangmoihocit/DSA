#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n, 10);
	// for (int i=0; i<5; ++i){
	// 	v.push_back(i);
	// }
	cout << v.size() << endl;
	for (int x : v){
		cout << x << " ";
	}
}