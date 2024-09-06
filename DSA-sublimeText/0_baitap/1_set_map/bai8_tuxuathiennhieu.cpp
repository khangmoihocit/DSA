#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>

int main(){
	int q; cin >> q;
	cin.ignore();
	while(q--){
		map<string, int> mp;
		string s; getline(cin, s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp){
			mp[tmp]++;
		}

		int max;
		string result;
		for(auto x : mp){
			if(x.second > max || (x.second == max && x.first < result)){
				result = x.first;
				max = x.second;
			}
		}
		cout << result;
	}
	return 0;
}