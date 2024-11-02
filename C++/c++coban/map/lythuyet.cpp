#include <bits/stdc++.h>
using namespace std;
// map se tu sap xep theo thu tu tang dan
//insert(): logN 
//mp[key]=value <-> mp.insert(key, value)
//size()
//find()
//count()

int main(){
    // map<int, int>mp;
    // // mp.insert({1, 2});
    // // cout << mp.size() << endl;
    // // cout << mp[1];
    // // mp[2]=10 // <-> mp({2, 10})
    // // map[3]++; //mp[3]=1
    // mp[1]=100;
    // mp[2]=200;
    // mp[3]=300;
    // //for each
    // // for (pair<int, int>x : mp){
    // //     cout << x.first << ' ' << x.second << endl;
    // // }
    // //iterator
    // // for (map<int, int>::iterator i=mp.begin(); i!=mp.end(); ++i){
    // //     cout << (*i).first << ' ' << (*i).second << endl; 
    // // }
 
    // // if (mp.find(75) != mp.end()) cout << "FOUND";
    // // //   khong tim thay 1, se it vao mp.end; neu it khac mp.end() tuc la tim thay
    // // else cout << "NOT FOUND";
    // // cout << endl;

    // // //
    // // auto it = mp.find(2);
    // // if (it==mp.end()) cout << "NOT FOUND";

    // //xoa thong qua key
    // mp.erase(2);
    // for (auto x:mp){
    //     cout << x.first << ' ' << x.second << endl;
    // }

    // //xoa thong qua iterator
    // auto it=mp.find(3);
    // mp.erase(it);
    // for (auto x:mp){
    //     cout << x.first << ' ' << x.second << endl;
    // }

    map<long long, int> mp;
    // int n; cin >> n;
    // int a[n];
    // for (int i=0; i<n; ++i){
    //     cin >> a[i];
    //     mp[a[i]]++;
    // }
    // for (auto x:mp){
    //     cout << x.first << ' ' << x.second << endl;
    // }
    mp[1]=2;
    mp[2]=3;
    mp[3]=4;
    mp.erase(2);
    for (auto x:mp){
        cout << x.first << ' ' << x.second << endl;
    }
}