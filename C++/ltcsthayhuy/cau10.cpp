#include "bits/stdc++.h"
using namespace std;
struct sp{
    int masp;
    char tensp[20];
    float giasp;
    int soluong;
};

void nhap(sp &a){
    cout << "ma san pham: "; cin >> a.masp;
    cin.ignore(1);
    cout << "ten san pham: "; cin.getline(a.tensp, 20);
    cout << "gia san pham: "; cin >> a.giasp;
    cout << "so luong san pham: "; cin >> a.soluong;
}

void hien(sp a){
    cout << setw(15) << setiosflags(ios::left) << a.masp
         << setw(20) << setiosflags(ios::left) << a.tensp
         << setw(20) << setiosflags(ios::left) << a.giasp
         << setw(10) << setiosflags(ios::left) << a.soluong
         << endl;
}

void nhapds(sp a[], int n){
    for (int i=0; i<n; ++i){
        nhap(a[i]);
    }
}

void hiends(sp a[], int n){
    cout << setw(15) << setiosflags(ios::left) << "ma san pham"
         << setw(20) << setiosflags(ios::left) << "ten san pham"
         << setw(20) << setiosflags(ios::left) << "gia san pham"
         << setw(10) << setiosflags(ios::left) << "so luong"
         << endl;
    for (int i=0; i<n; ++i){
        hien(a[i]);
    }
}

void update(sp a[], int n){
    char x[20];
    cin.ignore(1);
    cout << "nhap ten san pham muon cap nhat: "; cin.getline(x, 20);
    bool s=false;
    for (int i=0; i<n; ++i){
        if (strcmp(x, a[i].tensp)==0){
            s=true;
            nhap(a[i]);
            break;
        }
    }
    if (s){
        hiends(a, n);
    }
    else {
        cout << "ten san pham khong ton tai!";
    }
}

void sapxep(sp a[], int n){
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            if (a[i].soluong > a[j].soluong){
                swap(a[i], a[j]);
            }
        }
    }
    hiends(a, n);
}

bool check(sp a[], int n, float x, float y){
    for (int i=0; i<n; ++i){
        if (a[i].giasp>=x && a[i].giasp<=y) return true;
    }
    return false;
}

void thongke(sp a[], int n){
    int x, y, tmp=0;
    sp b[100];
    cout << "nhap khoang don gia bat dau: "; cin >> x;
    cout << "nhap khoang don gia ket thuc: "; cin >> y;
    if (check(a, n, x, y)){ // kiểm tra xem có đơn nào nằm trong khoảng x đến y không
        for (int i=0; i<n; ++i){
            if (a[i].giasp>x && a[i].giasp<y){
                b[tmp]=a[i];
                ++tmp;
            }
        }
        cout << endl << "hoa don co don gia nam trong khoang " << x << "-->" << y << endl;
        cout << setw(15) << setiosflags(ios::left) << "ma san pham"
             << setw(20) << setiosflags(ios::left) << "ten san pham"
             << setw(20) << setiosflags(ios::left) << "gia san pham"
             << setw(10) << setiosflags(ios::left) << "so luong"
             << endl;
        for (int i=0; i<tmp; ++i){
            hien(b[i]);
        }
        ofstream out;
        out.open("sach.dat", ios::binary);
        if (!out.is_open()){
            cout << "loi mo tep!";
            return;
        }
        for (int i=0; i<tmp; ++i){
            out.write((char*)&b[i], sizeof(sp));
        }
        cout << "ghi tep thanh cong vao file sach.dat.";
        out.close();
    }
    else {
        cout << "khong ton tai san pham nam trong khoang gia nay!";
    }
}

int main(){
    sp a[100];
    int n, choose;
    do {
        cout << endl
             << "MENU" << endl
             << "1. Nhap danh sach san pham." << endl
             << "2. Hien danh sach san pham." << endl
             << "3. Cap nhap thong tin san pham." << endl
             << "4. Sap xep danh sach so luong san pham theo so luong tang dan." << endl
             << "5. thong ke cac san pham co don gia tu x den y." << endl
             << "0. Thoat." << endl
             << "Chon: ";
        cin >> choose;
        switch (choose){
            case 1: {
                cout << "nhap so luong danh sach san pham: "; cin >> n;
                nhapds(a, n);
                break;
            }
            case 2: {
                hiends(a, n);
                break;
            }
            case 3: {
                update(a, n);
                break;
            }
            case 4: {
                sapxep(a, n);
                break;
            }
            case 5: {
                thongke(a, n);
                break;
            }
            case 0: {
                cout << "ket thuc chuong trinh.";
                break;
            }
            default: {
                cout << "loi! Vui long nhap lai.";
                break;
            }
        }
    }
    while (choose!=0);
    return 0;
}