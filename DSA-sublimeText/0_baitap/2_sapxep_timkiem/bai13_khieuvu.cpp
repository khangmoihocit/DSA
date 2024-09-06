#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

int main(){
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;

	sort(a, a+n);
	sort(b, b+m);
	int i=n-1, j=m-1;
	int count = 0;
	while(i>=0 && j>=0){
		if(a[i] > b[j]){
			count++;
			i--;
			j--;
		}else{
			j--;
		}
	}
	cout << count;

	return 0;
}