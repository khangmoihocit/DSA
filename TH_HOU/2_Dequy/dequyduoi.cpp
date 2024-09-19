#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

//tail recursion(đệ quy đuôi): là trường hợp đặc biệt của đệ quy tuyến tính,

int gcd(int m, int n){
	int r;
	if(m<n) return gcd(n, m);
	r = m%n;
	if(r == 0)
		return n;
	else
		return gcd(n, r);
}
int main(){
	cout << gcd(5, 25);
	/*1, gcd(5, 25)
		5<25 -> return gcd(25, 5); và lưu m=5, n=25 vào stack
	2, gcd(25, 5)
		r = 25%5=0 chia hết
		return n=5;
	  gọi stack m=5, n=25;
	  r = 5%25 = 5
	  r != 0 -> return gcd(n=25, r=5);
	3, gcd(25, 5)
		r = 25%5 = 0
		-> return n=5;*/
	return 0;
}