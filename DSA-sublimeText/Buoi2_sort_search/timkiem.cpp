#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

//tim kiem: tim kiem tuyen tinh + tim kiem nhi phan
//find(): O(N)
//binarySeach(): O(logN), trả về true false
int main(){
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i];

	// int *p = find(a, a+n, 5); //không tìm thấy trả về a+n
	
	// if(p == a+n){
	// 	cout << "NOT FOUND";
	// }else{
	// 	cout << "FOUND";
	// }
	for(int x : a){
		cout << x << " ";
	}

	// if(binary_seach(a, a+n, 8)){
	// 	cout << "FOUND";
	// }else{
	// 	cout << "NOT FOUND";
	// }
	

	return 0;
}