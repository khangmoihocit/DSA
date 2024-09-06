#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	set<string> se;
	while(cin >> s){
		se.insert(s);
	}
	cout << se.size() << endl;
	cout << *se.begin() << " " << *se.rbegin();
}