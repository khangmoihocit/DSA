#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>

// Input
// Dòng đầu tiên là số lượng test case T . (1≤T≤100).
// Mỗi test case bao gồm nhiều dòng, dòng đầu tiên là số lượng phần tử trong mảng. 
// (1≤n≤100000).
// Dòng thứ 2 bao gồm n phần tử trong mảng. (-1018≤ai≤1018).
// Output
// In ra số xuất hiện nhiều nhất cùng số lần xuất hiện của nó.
int main(){
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		map<int, int> mp;
		for (int i=0; i<n; ++i){
			int tmp; cin >> tmp;
			mp[tmp]++;
		}
		int max = 0;
		int pos;
		for (auto x : mp){
			if (x.second > max){
				max = x.second;
				pos = x.first;
			}
		}
		cout << pos << " " << mp[pos] << endl;
	}
}