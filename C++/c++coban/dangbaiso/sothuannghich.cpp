#include "bits/stdc++.h"
using namespace std;
bool check(int n){
    int du; int temp=n;
    int lat=0;
    while (n!=0){
        du=n%10;
        lat=lat*10+du;
        n/=10;
    }
    if (lat==temp) return true;
    else return false;
}
int main(){
    if (check(34543)) cout << "la so thuan nghich!";
}