#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>

// Tìm từ được lặp lại đầu tiên trong câu.
// Input
// Dòng đầu tiên là số lượng bộ test (1 ≤T≤100).
// T dòng tiếp theo mỗi dòng chứa một chuỗi đầu vào.
// Output
// Từ đầu tiên được lặp lại, dữ liệu đảm bảo câu có 2 từ trở lên vào có xuất hiện từ
// được lặp lại
int main(){
	int q; cin >> q;
	cin.ignore();
	while(q--){
		string s; getline(cin, s);
		stringstream ss(s);
		set<string> se;
		string tmp;
		while(ss >> tmp){
			if(se.find(tmp) != se.end()){ //neu tim thay
				cout << tmp << endl;
				break;	
			}
			se.insert(tmp);
		}
	}
	return 0;
}