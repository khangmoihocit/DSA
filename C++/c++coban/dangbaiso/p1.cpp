#include <bits/stdc++.h>
using namespace std;
// void : k can du lieu tra ve
int max_(int a, int b){
    if (a>b) return a;
    else return b;
}
double tong(int n){
    double sum=0;
    for (int i=1; i<=n; ++i){
    sum+=1.0/i;
    }
    return sum;
}
long long tongchan(int a, int b){
    long long sum=0;
    for (int i=a; i<=b; ++i){
        if (i%2==0) sum+=i;
    }
    return sum;
}
void test_(int n){ // truyen gia tri
    n*=2;
}
void test_2(int &n){ // truyen tham chieu : n va x cung trong 1 o nho, thay doi tham so ham main.
    n*=2;
}
// so nguyen to
bool ngto(int n){
    int uoc=0;
    for (int i=1; i<=n; ++i){
        if (n%i==0) ++uoc;
    }
    if (uoc==2) return true; // dung la so nguyen to
    else return false;
}







int main(){
    cout << max_(4, 20);
    cout << endl << tong(2);
    cout << "\ntong cac so chan trong doan la : " << tongchan(2,5) << endl;

    // void test
    int x=100;
    test_(x); cout << x << endl;
    test_2(x); cout << x << endl;

    // kiem tra so nguyen to
    int n; cout << "nhap so nguyen n : "; cin >> n;
    if (ngto(n)) cout << "n la so nguyen to." << endl;
    else cout << "n khong la so nguyen to." << endl;

    return 0;
}