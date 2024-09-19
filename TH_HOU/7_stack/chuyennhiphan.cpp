#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;



int main(){
	int n; cin >> n;
	stack<int> sta;
	while(n>0){
		sta.push(n%2);
		n/=2;
	}
	while(!sta.empty()){
		cout << sta.top();
		sta.pop();
	}
	return 0;
}