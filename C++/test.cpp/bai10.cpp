#include <bits/stdc++.h>
using namespace std;

struct sv{
    char masv[20];
    char tensv[20];
    int ngaysinh;
    char gioitinh[15];
    float diemtb;
};

void nhap(sv &a){
    cin.ignore(1);
    cout << "ma sinh vien: "; cin.getline(a.masv, 20);
    cout << "ten sinh vien: "; cin.getline(a.tensv, 20);
    cout << "ngay sinh: "; cin >> a.ngaysinh;
    cin.ignore(1);
    cout << "gioi tinh: "; cin.getline(a.gioitinh, 15);
    cout << "diem trung binh: "; cin >> a.diemtb;
}

void hien(sv a){
    cout << setw(20) << setiosflags(ios::left) << a.masv
         << setw(20) << setiosflags(ios::left) << a.tensv
         << setw(15) << setiosflags(ios::left) << a.ngaysinh
         << setw(15) << setiosflags(ios::left) << a.gioitinh
         << setw(15) << setiosflags(ios::left) << a.diemtb
         << endl;
}

void nhapds(sv a[], int &n){
    for (int i=0; i<n; ++i){
        nhap(a[i]);
        if (strcmp(a[i].masv, "0")==0){
            n=i;
            break;
        }
    }
}

void hientieude(){
    cout << setw(20) << setiosflags(ios::left) << "masinhvien"
         << setw(20) << setiosflags(ios::left) << "tensinhvien"
         << setw(15) << setiosflags(ios::left) << "ngaysinh"
         << setw(15) << setiosflags(ios::left) << "gioitinh"
         << setw(15) << setiosflags(ios::left) << "diemTB"
         << endl;
}

void hiends(sv a[], int n){
    hientieude();
    for (int i=0; i<n; ++i){
        hien(a[i]);
    }
}

void sapxep(sv a[], int n){
    cout << "danh sach sinh vien sau khi sap xep: " << endl;
    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            if (strcmp(a[i].tensv, a[j].tensv)>0)
                swap(a[i], a[j]);
        }
    }
    ofstream out;
    out.open("sv.dat", ios::binary);
    if (!out.is_open()){
        cout << "loi mo tep!";
        return;
    }
    for (int i=0; i<n; ++i){
        out.write((char*)&a[i], sizeof(sv));
    }
    out.close();
    hiends(a, n);
    cout << endl << "ghi tep thanh cong vao file sv.dat.";
}

void tim(sv a[], int n){
    bool tg=false;
    float m=10;
    int f;
    for (int i=0; i<n; ++i){
        if (strcmp(a[i].gioitinh, "nu")==0){
            if (a[i].diemtb<m){
                m=a[i].diemtb;
                f=i;
                tg=true;
            }
        }
    }
    if (tg) {
        cout << "Sinh vien nu co diem thap nhat: " << endl;
        hientieude();
        hien(a[f]);
    } else {
        cout << "Khong co sinh vien nu nao trong danh sach." << endl;
    }
}

void dem(sv a[], int n){
    int m=0;
    for (int i=0; i<n; ++i){
        if (strcmp(a[i].gioitinh, "nam")==0) ++m;
    }
    cout << "so sinh vien nam la: " << m;
}

int main(){
    sv a[100];
    int n, chon;
    do{
        cout << endl
             << "MENU" << endl
             << "1. Nhap danh sach sinh vien." << endl
             << "2. Hien danh sach sinh vien." << endl
             << "3. Sap xep danh sach sinh vien theo thu tu alphabet." << endl
             << "4. Tim sinh vien nu co diem trung binh thap nhat." << endl
             << "5. Dem so sinh vien nam." << endl
             << "0. Thoat chuong trinh." << endl
             << "chon :";
        cin >> chon;
        switch(chon){
            case 1: {
                cout << "nhap so luong danh sach sinh vien: "; cin >> n;
                nhapds(a, n);
                break;
            }
            case 2: hiends(a, n); break;
            case 3: sapxep(a, n); break;
            case 4: tim(a, n); break;
            case 5: dem(a, n); break;
            case 0: cout << "ket thuc chuong trinh!";
            default: cout << "Loi! Vui long nhap theo MENU(Vd: 1)."; break;
        }
    }
    while (chon!=0);
    return 0;
}

