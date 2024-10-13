#include <iostream>
using namespace std;

bool check(long long n){
    string s = to_string(n);

    string firstNumber = s.substr(0, 2);
    string secondNumber = s.substr(2);

    long long a = stoi(firstNumber);
    long long b = stoi(secondNumber);

    if(a != 10) return false;
    if(b <= 2) return false;
    return true;
}

int main() {
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(check(n)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
