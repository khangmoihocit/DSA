#include <bits/stdc++.h>
using namespace std;

//set: khong dung chi so
//find, count, size, insert, erase, 
//vector: dung dc chi so
struct cmp{
	bool operator()(int a, int b) const{
		return a>b;
	}
};
int main(){
//bai21
//12
//2 8 h t t 2 h e h e h t
	// int n; cin >> n;
	// set<char> se;
	// for (int i=0; i<n; ++i){
	// 	char x; cin >> x;
	// 	se.insert(x);
	// }
	// cout << se.size() << endl;
	// for (char x : se){
	// 	cout << x << " ";
	// }
	// cout << endl;
	// for (auto it = se.rbegin(); it != se.rend(); ++it){
	// 	cout << *it << " ";
	// }

//ham find
	// set<int> se = {1, 2, 5, 7, 9};
	// auto it = se.find(5); //O(logn) nếu tìm thấy sẽ trả về iterator tới phần tử tìm thấy
	// 						//không thấy sẽ trả về iterator end()
	// if (it == se.end()){
	// 	cout << "NOT FOUND";
	// }
	// else{
	// 	++it;
	// 	cout << *it << endl;
	// 	cout << "FOUND";
	// }
//ham count: trả về 1 hoặc 0
//erase: xóa phần tử trong set
	// set<int> se = {1, 2, 3, 4,5};
	// auto it = se.find(2);
	// se.erase(it);
	// for (int x : se){
	// 	cout << x << " ";
	// }

//5
//1 2 1 3 4
//2
//1
//6
	// int n; cin >> n;
	// set<int> se;
	// for (int i=0; i<n; ++i){
	// 	int tmp; cin >> tmp;
	// 	se.insert(tmp);
	// }

	// int m; cin >> m;
	// for (int i=0; i<m; ++i){
	// 	int x; cin >> x;
	// 	if (se.count(x) == 0){
	// 		cout << "NO" << endl;
	// 	}else{
	// 		cout << "YES" << endl;
	// 	}
	// }

//multiset: luu cac gia tri trung nhau
	// multiset<int> se;
	// int n; cin >> n;
	// for (int i=0; i<n; ++i){
	// 	int tmp; cin >> tmp;
	// 	se.insert(tmp);
	// }

	// for (int x : se){
	// 	cout << x << " ";
	// }
	// cout << endl;
	// auto it = se.find(2);
	// cout << distance(se.begin(), it);//khoang cach chi so

	// cout << endl << se.count(4);

//pair
	// pair<int, int> p = make_pair(100, 200);
	// // pair<int, int> p = {100, 200};
	// cout << p.first << " " << p.second;

	// pair<int, set<int>> p;
	// p.first = 100;
	// p.second.insert(1);
	// p.second.insert(2);
	// p.second.insert(3);

	// cout << p.first;
	// for (int x : p.second){
	// 	cout << x << " ";
	// }

	// vector<pair<int, int>> v;
	// int n; cin >> n;
	// for (int i=0; i<n; ++i){
	// 	int x, y; cin >> x >> y;
	// 	v.push_back({x, y});
	// }

	// for (pair<int, int> x : v){
	// 	cout << x.first << " " << x.second << endl;
	// }

//sap xep phan tu trong set theo yeu cau nao do
	int n; cin >> n;
	set<int, cmp> se;
	for(int i=0; i<n; ++i){
		int tmp; cin >> tmp;
		se.insert(tmp); //o(longN)
	}
	for(int x : se){
		cout << x << " ";
	}





}