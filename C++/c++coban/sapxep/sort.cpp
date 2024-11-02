#include <bits/stdc++.h>
#include <algorithm> 
//sort, stable_sort
using namespace std;
// mang: (x;y)  sort(a+x, a+y+1)
// vector (x:y) sort(a.begin+x, a.begin+y+1)

// sap xep theo gia tri tuyet doi
bool cmp1(int a, int b){
    return abs(a) < abs(b);
}

//sap xep theo tong cac chu so
int tinhtog(int n){
    int res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
bool cmp2(int a, int b){
    return tinhtog(a) < tinhtog(b);
}

//sap xep nhieu tieu chi: sap xep theo tong chu so tang dan, neu = nhau thi xep so lon dung truoc
bool cmp3(int a, int b){
    if (tinhtog(a)!=tinhtog(b)) return tinhtog(a) < tinhtog(b); //tc thu nhat
    else return a>b; // tieu chi thu 2
}

int main(){
    // int a[6]={323, 62, 152, 1001, 8, 17};
     int a[7]={4, 7, 23, 92, 10, 55, 46};

    //stable_sort(a, a+6, cmp2) cung tieu chi sap xep thi giu nguyen vi tri ban dau
    sort(a, a+7, cmp3);
    for (int x:a){
        cout << x << ' ';
    }

}