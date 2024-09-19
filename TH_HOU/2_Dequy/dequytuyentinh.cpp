#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

//linear recursion(đệ quy tuyến tính) là trường hợp hàm chỉ gọi lại nó 1 lần

//tính giai thừa : điểm dừng: 0! = 1
				//	quy luật: n! = n*(n-1)!
int factoria(int n){
	if(n == 0)
		return 1;
	return n*factoria(n-1);
}
int main(){
	cout << factoria(5);
	return 0;
}