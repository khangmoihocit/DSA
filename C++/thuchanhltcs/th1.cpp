#include "bits/stdc++.h"
using namespace std;
int main(){
    char s[5];
    cin.getline(s, 5);
    ofstream out;
    out.open("test.txt");
    if (!out.is_open()){
        cout << "loi! khong ghi dc tep.";
    }
    cout << "ghi tep thanh cong";
    out.write((char*)&s, sizeof(s));
}