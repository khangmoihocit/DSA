#include <bits/stdc++.h>
using namespace std;
//cho 1 mang so nguyen , in ra cac phan ttu  trong mang theo thu tu tan suat xuat hien giam dan,
// neu co nhieu so cung tan suat  xuat hien thi so nao nho hon in ra truoc

//1.dem tan suat (map)
//2. chuyen cac phan tu trong map ra vector pair
//3. viet comparator cho vector pairn-->sort
//4. In
bool cmp(pair<int, int>a, pair<int, int>b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}

int main(){
    int a[10]={3, 3, 5, 5, 5, 5, 7, 7, 8, 2};
    map<int, int>mp;
    for (int i=0; i<10; ++i){
        mp[a[i]]++;
    }
    //chuyen map sang vector pair de dang sap xep
    vector<pair<int, int>>v;
    for (auto it:mp){
        v.push_back(it);
    }

    sort(begin(v), end(v), cmp);
    //hien
    for (auto it:v){
        //it.second: value
        //it.first: key
        for (int j=0; j<it.second; ++j){
            cout << it.first << ' ';
        }
    }

}