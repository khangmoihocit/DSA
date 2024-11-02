#include <bits/stdc++.h>
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

int dem(int a[], int n){
    int sum=0;
    for (int i=0; i<n; ++i){
        if (a[i]%2==0) sum++;
    }
    return sum;
}

int cmax(int a[], int n){
    int tg=0;
    for (int i=0; i<n; ++i){
        if (a[i]>tg) tg=a[i];
    }
    return tg;
}

bool vitri(int a[], int n, int x){
    bool bandau=false;  
    for (int i=0; i<n; ++i){
        if (a[i]==x){   
            bandau=true;
            int c=i+1;
            cout << c << " ";
        }
    }
    return bandau;
}

void sapxep(int a[], int n){
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            if (a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

int main(){
    int n, x; cout << "nhap so phan tu mang: "; cin >> n; cout << endl;
    int a[n];
    nhapxuat(a, n);
    // tim so phan tu chan
    cout << endl << "so phan tu chan la: " << dem(a, n);
    // tim gtln 
    cout << endl << "gia tri lon nhat trong mang la: " << cmax(a, n);
    // tim vi tri x xuat hien
    cout << endl << "\nnhap x: "; cin >> x;
    if (vitri(a, n, x)) cout << "la vi tri x xuat hien."<< endl;
    else cout << "no"<< endl;
    //sap xep
    sapxep(a, n);
    cout << endl << "mang sau khi sap xep la: ";
    for (int i=0; i<n; ++i) cout << a[i] << " ";
    return 0;
}