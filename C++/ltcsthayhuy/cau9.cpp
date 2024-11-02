#include "bits/stdc++.h"
using namespace std;

struct hoadon{
    char mahoadon[10];
    int ngay;
    char tensp[10];
    float giasp;
    int soluongsp;
    float thanhtien;
};

void nhap(hoadon &a) {
    cout << "ma hoa don: ";
    cin.ignore(1);
    cin.getline(a.mahoadon, 10);
    cout << "ngay: ";
    cin >> a.ngay;
    cin.ignore(1);
    cout << "ten san pham: ";
    cin.getline(a.tensp, 10);
    cout << "gia san pham: ";
    cin >> a.giasp;
    cout << "so luong san pham: ";
    cin >> a.soluongsp;
    a.thanhtien = a.giasp * a.soluongsp;
}

void hien(hoadon a){
    cout << setw(10) << a.mahoadon
         << "\t" << setw(15) << a.ngay
         << "\t" << setw(15) << a.tensp
         << "\t" << setw(10) << a.giasp
         << "\t" << setw(10) << a.soluongsp
         << "\t" << setw(10) << a.thanhtien << endl;
}

void nhapds(hoadon arr[], int n){
    for (int i = 0; i < n; ++i) {
        nhap(arr[i]);
    }
}

void hiends(hoadon arr[], int n){
    cout << setw(10) << setiosflags(ios::left) << "mahoadon"
         << "\t" << setw(15) << "ngay(7/2016)"
         << "\t" << setw(15) << "tensp"
         << "\t" << setw(10) << "giasp"
         << "\t" << setw(10) << "soluongsp"
         << "\t" << setw(10) << "thanhtien" 
         << endl;
    for (int i = 0; i < n; ++i) {
        hien(arr[i]);
    }
}

void ghifile(hoadon arr[], int n){
    ofstream out;
    out.open("hoadon.dat", ios::out|ios::binary);
    if(!out.is_open()){
        cout << "loi mo tep!";
        return;
    }
    for (int i=0; i<n; ++i){
        out.write((char*)&arr[i], sizeof(hoadon));
    }
    cout << endl << "ghi tep thanh cong vao tep hoadon.dat!" << endl;
    out.close();
}

void docfile(hoadon arr[], int &n){
    ifstream in; 
    in.open("hoadon.dat", ios::in|ios::binary);
    if(!in.is_open()){ 
        cout << "loi mo tep!"; 
        return; 
    }
    n = 0; // Đặt số lượng hóa đơn là 0
    while (!in.eof()){ 
        in.read((char*)&arr[n], sizeof(hoadon)); 
        if (in.gcount() > 0) n++; // Nếu số byte đọc được lớn hơn 0, tăng số lượng hóa đơn lên 1
    }
    in.close(); 
    hiends(arr, n);
}

void sapxep(hoadon arr[], int n){
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            if (arr[i].ngay>arr[j].ngay || (arr[i].ngay==arr[j].ngay && strcmp(arr[i].tensp, arr[j].tensp)>0)){
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << endl << "danh sach hoa don sau khi sap xep la: " << endl;
    hiends(arr, n);
    ofstream out;
    out.open("sapxep.dat", ios::binary);
    if (!out.is_open()){
        cout << "loi ghi vao tep sap xep!";
        return;
    }
    for (int i=0; i<n; ++i){
        out.write((char*)&arr[i], sizeof(hoadon));
    }
    cout << "ghi thanh cong vao tep sapxep.dat!" << endl;
    out.close();
}

void find(hoadon arr[], int n){
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            if (arr[i].thanhtien<arr[j].thanhtien){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << setw(10) << setiosflags(ios::left) << "mahoadon"
         << "\t" << setw(15) << "ngay(7/2016)"
         << "\t" << setw(15) << "tensp"
         << "\t" << setw(10) << "giasp"
         << "\t" << setw(10) << "soluongsp"
         << "\t" << setw(10) << "thanhtien" 
         << endl;
    hien(arr[0]);
}

bool check(int n){
    if (n<0 || n>100) return false;
    return true;
}

int main() {
    hoadon a[100];
    int choose;
    int n;
    do {
        cout << endl
             << "MENU :" << endl
             << "1. Nhap danh sach hoa don." << endl
             << "2. Hien danh sach hoa don." << endl
             << "3. Sap xep hoa don theo ngay." << endl
             << "4. Tim hoa don co tong thanh tien cao nhat." << endl
             << "5. Thoat." << endl
             << "Chon: ";
        cin >> choose;
        switch (choose) {
            case 1: {
                cout << "Nhap so luong hoa don: "; cin >> n;
                if (check(n)) { // kiem tra so luong hoa don 0<n<100
                nhapds(a, n);
                ghifile(a, n);
                break;
                }
                else {  
                    cout << "Vui long nhap dung so luong hoa don!" << endl;
                    break;
                }
            }
            case 2: {
                cout << "\nDanh sach hoa don: " << endl;
                docfile(a, n);
                break;
            }
            case 3: {
                sapxep(a, n);
                break;
            }
            case 4: {
                find(a, n);
                break;
            }
            case 5: {
                cout << "Ket thuc chuong trinh!";
                break;
            }
            default: {
                cout << "loi! Vui long nhap lai." << endl;
                break;
            }
        }
    }
    while (choose!=5);
    return 0;
}
