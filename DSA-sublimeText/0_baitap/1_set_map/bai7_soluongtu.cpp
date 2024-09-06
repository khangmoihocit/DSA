#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>

/*
2
Python C++ java php Python python 
Andrew neiman heisenberg neiman
*/
int main(){
	int q; cin >> q;
	cin.ignore();
	while(q--){
		string s; getline(cin, s);
		stringstream ss(s);
		string tmp;
		set<string> se;
		while(ss >> tmp){
			se.insert(tmp);
		}

		cout << se.size() << endl;
	}
	return 0;
}