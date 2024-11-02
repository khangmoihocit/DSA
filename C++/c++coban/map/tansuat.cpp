#include <bits/stdc++.h>
using namespace std;


int main(){
	map<long long, int>mp; 
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
		mp[a[i]]++; //mp({key, value})

	}
	for (int i=0; i<n; ++i){
		if (mp[a[i]]!=0){ // value co gia tri thi in ra
			cout << a[i] << ' ' << mp[a[i]] << endl;
			mp[a[i]]=0; //gia tri value =0 tuc la da in ra va khong in ra lan nua
		}
	}
	return 0;
}