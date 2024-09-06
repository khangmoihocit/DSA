#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>

// Input
// Dòng đầu tiên là số lượng test case T . (1≤T≤100).
// Mỗi test case bao gồm một xâu chỉ gồm các kí tự là chữ cái không quá 10000 kí tự
// Output
// In YES nếu xâu nhập vào là xâu pangram, ngược lại in NO
int main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s; getline(cin, s);
		set<char> se;
		//duyet qua xau va dua cac ki tu thuong vao trong set
		for(char x : s){
			if(isalpha(x)){ //kiem tra x co phai la ki tu khong
				se.insert(tolower(x)); //chuyen x ve chu cai thuong
			}
		}

		if(se.size() == 26){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}