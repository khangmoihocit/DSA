#include "bits/stdc++.h"
using namespace std;
bool check(int n){
    if (n%2==0) return true;
    else return false;
}
int main(){
    int n=100;
    if(check(n)) cout << "YES";
    else cout << "NO";
}