#include <bits/stdc++.h>
using namespace std;

int main(){
	// vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(4);
	// v.emplace_back(3);

	// // for (int i=0; i<v.size(); ++i){
	// // 	cout << v[i] << " ";
	// // }
	
	// for (int &x : v){
	// 	x = 100;
	// }

	// for (int x : v){
	// 	cout << x << " ";
	// }

//khai báo vector lấy dữ liệu từ 1 mảng a[]
	// int a[5] = {1, 2, 3, 4, 5};
	// vector<int> v(a, a+5);
	// for (int x : v){
	// 	cout << x << " ";
	// }

	// int n;
	// cin >> n;
	// for (int i = 0; i<n; ++i){
	// 	int tmp; cin >> tmp;
	// 	v.push_back(tmp);
	// }
	// cout << endl;

	// for (int x : v){
	// 	cout << x << " ";
	// }

//iterator
	// vector<int> v = {3, 5, 6, 2};
	// // vector<int>::iterator it = v.begin();
	// // cout << *it;

	// for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
	// 	cout << *it << " ";
	// }
	// cout << endl;
	// for (auto it = v.rbegin(); it!=v.rend(); ++it){
	// 	cout << *it << " ";
	// }

	// auto a = v.begin() + 2;
	// cout << endl << *a;

//các hàm phổ biến trong vector: push_back(), clear(), size(), empty()

//chèn 100 vào chỉ số 3
	vector<int> v = {3, 5, 1, 4, 6, 8};
	v.insert(v.begin()+3, 100);
//xoa phan tu o chi so 3
	v.erase(v.begin() + 3);
	for (int x : v){
		cout << x << " ";
	}
//xoa phan tu cuoi cung cua vector
	v.pop_back();

	
}