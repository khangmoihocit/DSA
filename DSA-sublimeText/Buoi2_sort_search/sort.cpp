#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
typedef long long ll;

//sort search: basic
//sort(a + x, a + y + 1);
//sort(v.begin + x, v.end + y + 1);

int tong(int n){
	int ans = 0;
	while(n != 0){
		ans += n%10;
		n /= 10;
	}
	return ans;
}
bool cmp(int a, int b){
	if(tong(a) != tong(b)){
		return tong(a) < tong(b);
	}else{
		return a < b;
	}
}
int main(){
	// int a[] = {1, 5, 7, 3, 9, 2, 0, 2, 8};
	// // int n = a.length();
	// sort(a, a + 5, greater<int>());
	// for(int x : a){
	// 	cout << x << " ";
	// }

	// cout << endl;

	// vector<int> v = {4, 5, 2, 7};
	// sort(v.begin(), v.end());
	// for(int x : v){
	// 	cout << x << " ";
	// }
	int a[] = {100, 111, 101, 99, 3};
	// sort(a, a + 5, cmp);
	

//cách viết hàm sort khác
	sort(a, a+5, [](int a, int b)->bool{
		return a < b;
	});
	for(int x : a){
		cout << x << " ";
	}
	return 0;
}