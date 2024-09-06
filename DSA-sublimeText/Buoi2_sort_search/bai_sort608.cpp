 #include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

// 14
// 25556 11105 32129 8765 25187 22479 21283 5842 4471 23648 26441 28433 23517 20475
//sap xep cac so co so luong 0, 6, 8 lớn trước , nếu số lượng bằng nhau thì xếp số nhỏ trước
int soluong(int n){
	int dem=0;
	while(n!=0){
		int tmp = n%10;
		if(tmp == 0 || tmp == 6 || tmp == 8){
			++dem;
		}
		n/=10;
	}
	return dem;
}
bool cmp(int a, int b){
	if(soluong(a) != soluong(b)){
		return soluong(a) > soluong(b);
	}
	return a < b;
}
int main(){
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n, cmp);
	for(int x : a){
		cout << x << " ";
	}
	return 0;
}