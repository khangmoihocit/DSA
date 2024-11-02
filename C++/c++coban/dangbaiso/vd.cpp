#include "bits/stdc++.h"
using namespace std;
void nhapxuat(int a[], int n){
    cout << "nhap mang:" << endl;
    for (int i=0; i<n; ++i){
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
    cout << endl << "mang vua nhap la: ";
    for (int i=0; i<n; ++i)
    cout << a[i] << " ";
    cout << endl;
}
void vitri(int a[], int n){
    double tg=0;
    int s;
    for (int i=0; i<n-2; ++i){
        double res=0;
        res=(a[i]+a[i+1]+a[i+2])/3.0;
        if (res>tg){
            tg=res;
            s=i;
        }
    }
    int c = s+1;
    int b = s+2;
    cout << s << c << b << endl;
    cout << "gia tri TBC: " << tg << endl;
}
int main(){
    int n; cin >> n;
    int a[n];
    nhapxuat(a, n);
    cout << "vi tri trung binh cong lon nhat 3 so lien tiep: ";
    vitri(a, n);
    return 0;
}