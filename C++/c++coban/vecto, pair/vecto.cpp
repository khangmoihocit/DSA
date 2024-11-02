// 43:20
#include "bits/stdc++.h"
using namespace std;
// cu phap vector<kieu_du_lieu> a;
// // push_back(x)
// // a.size()
// // pos_back() : xoa phan tu o cuoi
// //clear()
// void test(){
//     vector<int> a;
//     a.push_back(100);
//     a.push_back(200);
//     a.push_back(300);
//     // for (int i=0; i<a.size(0); ++i){
//     //     cout << a[i] << " ";
//     // }
//     for (vector<int>::iterator it=a.begin(); it!=a.end(); ++it){
//         //  iterator            bat dau       dk lap  a.end(): vi tri sau phan tu cuoi cung mang
//         cout << *it << ' ';
//     }
//     // begin()+x = a[x];
//     cout << endl;
//     cout << *(a.begin()+2) << endl;
//     // for each: cach hien mang
//     for (int x:a){
//         cout << x << ' ';
//     }
// }
// void nhap(){
//     int n; cin >> n;
//     vector<int>a(n);
//     // cach nhap
//     for (int i=0; i<n; ++i){
//         int tmp; cin >> tmp;
//         a.push_back(tmp);
//     }
//     for (int x:a){
//         cout << x << ' ';
//     }
//     // vector<int> a(n, 100); //tao mang n phan tu 100
// }

// void xoa(){
//     vector<int> a(10);
//     for (int i=1; i<=10; ++i){
//         a[i-1]=i;
//     }
//     for (int x:a){
//         cout << x << ' ';
//     }
//     cout << endl;
//     // a.erase(a.begin()+4); // xoa phan tu thu a[5];
//     a.erase(a.begin()+1, a.begin()+9); // xoa phan tu trong doan [x; y)
//     for (int x:a){
//         cout << x << " ";
//     }
// }

//insert

int main(){
    //tao nhieu phan tu giong nhau
    int n = 100;
    vector<int>a(n, 8); //tao 1 mang co 100 phan tu so '8'
    for (int x : a){
        cout << x << ' ';
    }
    return 0;
   
}