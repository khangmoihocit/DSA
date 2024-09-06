#include <bits/stdc++.h>
using namespace std;

#define ppi pair<pair<int, int>, int>
// Input
// Dòng đầu tiên là số lượng test case T . (1≤T≤100).
// Mỗi test case gồm 3 dòng, dòng đầu tiên là số lượng phần tử của mảng thứ nhất và 
// mảng thứ 2. (1≤n, m≤1000).
// Dòng thứ 2 là các số thuộc mảng thứ 1. (-109≤ai≤109
// )
// Dòng thứ 3 là các số thuộc mảng thứ 2. ((-109≤ai≤109
// )
// Output
// Liệt kê các số thuộc mảng thứ 1 mà không thuộc mảng thứ 2, theo thứ tự xuất hiện, 
// nếu không tồn tại số nào in ra “NOT FOUND”
int main(){
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<m; ++i) cin >> b[i];

	bool foundAny = false;
	for(int i=0; i<n; ++i){
		bool check = false;
		for (int j=0; j<m; ++j){
			if (a[i] == b[j]){
				check = true;
				break;
			}
		}
		if (!check){
			cout << a[i] << endl;
			foundAny = true;
		} 
	}
	if (!foundAny) cout << "NOT FOUND" << endl;


}