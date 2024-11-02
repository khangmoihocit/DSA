#include "bits/stdc++.h"
using namespace std;
int main(){
    //string substr(pos, n) : cat thanh xau con tu vi tri pos va lay n ki tu.
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int pos=a.find(b);   //vi tri ma b xuat hien trong a.
    if (pos>0)
        cout << a.substr(pos); //cat chuoi a tu vi tri pos.
    else 
        cout << "k ton tai!";
}