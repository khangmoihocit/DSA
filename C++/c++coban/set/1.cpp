#include <bits/stdc++.h>
using namespace std;

//0logn
//a.size()
//a.insert(...)
//find
// a.count(...) : tim kiem phan tu 
// erase
int main(){
    set<int>s; // khai bao 
    // s.insert(100); // ham set k luu cac phan tu giong nhau
    for (int i=0; i<10; i++){
        s.insert(i);
    }
    // cout << s.size() << endl;
    // if (s.count(12)!=0) //  tim so 12 co trong set hay khong
    //     // s.find() != s.end()
    //     cout << "yes";
    // else cout << "no";
    // cach xoa trong set
    for (int x:s){
        cout << x << ' ';
    }
    s.erase(5); // xoa so 5 trong set
    s.erase(s.find(6)); //tim so 6 va xoa no, xoa bang iterator
    cout << endl;
    for (int x:s){
        cout << x << ' ';
    }
    cout << endl;
    cout << *s.begin(); // phan tu dau
    cout << *s.rbegin() << endl; //phan tu cuoi
    // duyet set
    for (set<int>::iterator it=s.begin(); it!=s.end(); ++it){
        cout << *it << ' ';
    }
}