#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 10234;

    string a = to_string(n);

    string s = "1";
    for(int i=1; i<a.length(); ++i){
        s+="0";
    }
    int b = stoi(s);
    cout << b;
    cout << "so sau so 10: " << n%b;
}