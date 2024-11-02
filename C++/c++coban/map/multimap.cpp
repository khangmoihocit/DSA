#include <bits/stdc++.h>
using namespace std;
int main(){
    multimap<int, int>mp;
    mp.insert({1, 100});
    //mp[1]=200; // khong dung duoc trong multimap
    mp.insert({1, 2});
    mp.insert({2, 10});
    mp.insert({2, 5});
    mp.insert({4, 8});
    // for (auto x : mp){
    //     cout << x.first << ' ' << x.second << endl;
    // }

    //second()
    // cout << mp.count(2);

    // //erase(): se xoa het cac key
    // mp.erase(1); // xoa het cac key 1 
    
    //
    auto it=mp.find(1);
    mp.erase(it);
    for (auto x:mp){
        cout << x.first << ' ' << x.second << endl;
    }

}