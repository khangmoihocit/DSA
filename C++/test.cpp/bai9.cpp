#include <bits/stdc++.h>
using namespace std;
struct sach{
    char tens[10];
    char tentg[15];
    char nxb[15];
    int nam;
};

void nhap(sach &a){
    cin.ignore(1);
    cout << "ten sach: "; cin.getline(a.tens, 10);
    cout << "ten tac gia: "; cin.getline(a.tentg, 15);
    cout << "nha xuat ban: "; cin.getline(a.nxb, 15);
    cout << "nam xuat ban: "; cin >> a.nam;
}

void hien(sach a){
    cout << setw(10) << setiosflags(ios::left) << a.tens
         << setw(15) << setiosflags(ios::left) << a.tentg
         << setw(15) << setiosflags(ios::left) << a.nxb
         << setw(15) << setiosflags(ios::left) << a.nam
         << endl;
}

void nhapds(sach a[], int n){
    for (int i=0; i<n; ++i){
        nhap(a[i]);
    }
}

void hiends(sach a[], int n){
    cout << setw(10) << setiosflags(ios::left) << "ten sach"
         << setw(15) << setiosflags(ios::left) << "ten tac gia"
         << setw(15) << setiosflags(ios::left) << "nha xuat ban"
         << setw(15) << setiosflags(ios::left) << "nam xuat ban"
         << endl;
    for (int i=0; i<n; ++i){
        hien(a[i]);
    }
}

void ghifile(sach a[], int n){
    ofstream out;
    out.open("sach.dat", ios::out|ios::binary);
    if(!out.is_open()){
        cout << "loi mo tep!";
        return;
    }
    for (int i=0; i<n; ++i){
        out.write((char*)&a[i], sizeof(sach));
    }
    cout << endl << "ghi tep thanh cong vao tep sach.dat!" << endl;
    out.close();
}

void docfile(sach a[], int n){
    ifstream in; 
    in.open("sach.dat", ios::in|ios::binary);
    if(!in.is_open()){ 
        cout << "loi mo tep!"; 
        return; 
    }
    n = 0;
    while (!in.eof()){ 
        in.read((char*)&a[n], sizeof(sach)); 
        if (in.gcount() > 0) n++;
    }
    in.close(); 
    hiends(a, n);
}

void timsach(sach a[], int n){
    char x[10];
    cout << "nhap ten sach muon tim kiem: ";
    cin.ignore();
    cin.getline(x, 10);
    for (int i=0; i<n; ++i){
        if (strcmp(a[i].tens, x)==0){
            cout << setw(10) << setiosflags(ios::left) << "ten sach"
                 << setw(15) << setiosflags(ios::left) << "ten tac gia"
                 << setw(15) << setiosflags(ios::left) << "nha xuat ban"
                 << setw(15) << setiosflags(ios::left) << "nam xuat ban"
                 << endl;
            hien(a[i]);
            break;
        }
    }
}

void thongke(sach a[], int n){
    int s=0;
    for (int i=0; i<n; ++i){
        if (a[i].nam<=1989 && a[i].nam>=1980) ++s;
    }
    cout << "so luong sach tu thap nien 80 la: " << s << endl;
}

void cachnam(sach a[], int n){
    bool tg=false;
    sach b[100];
    int temp=0;
    for (int i=0; i<n; ++i){
        if (2023-a[i].nam==30){
            b[i]=a[i];
            ++temp;
            tg=true;
        }
    }
    if(tg){
        cout << endl << "sach da san xuat cach day 30 nam la: ";
        for (int i=0; i<temp; ++i){
            cout << b[i].tens << " ";
        }
        cout << endl;
    }
    else{
        cout << "khong ton tai sach tu 30 nam truoc(tinh tu nam 2023).";
    }
}

int main(){
    sach a[100];
    int n, choose;
    do{
        cout << endl
             << "MENU: " << endl
             << "1. Nhap danh sach cac sach." << endl
             << "2. Hien danh sach cac sach." << endl
             << "3. Tim sach." << endl
             << "4. Thong ke so luong sach tu thap nien 80." << endl
             << "5. Ten cac quyen sach da xuat ban cach day 30 nam." << endl
             << "0. Thoat chuong trinh."
             << endl;
        cout << "Chon: "; cin >> choose;
        switch(choose){
            case 1: {
                cout << "nhap so luong sach: "; cin >> n;
                nhapds(a, n);
                ghifile(a, n);
                break;
            }
            case 2: {
                docfile(a, n);
                break;
            }
            case 3: {
                timsach(a, n);
                break;
            }
            case 4: {
                thongke(a, n);
                break;
            }
            case 5: {
                cachnam(a, n);
                break;
            }
            case 0: {
                cout << "ket thuc chuong trinh!";
                break;
            }
            default: {
                cout << "loi! Vui long nhap lai theo menu (Vd: '1').";
                break;
            }
        }
    }
    while(choose!=0);
    return 0;  
}