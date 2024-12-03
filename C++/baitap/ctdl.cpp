#include <bits/stdc++.h>>
using namespace std;
struct HoSuDungDien {
    int maHo;
    string tenHo, diaChi;
    string soDienThoai;
    HoSuDungDien* next;
};

struct HoaDon {
    int maHoaDon;
    int soDienThang;
    int maHo;
    string thoiGian;
    double soTien;
    HoaDon* next;
    string ngayThanhLap; //thuộc tính mới
};

HoSuDungDien* danhSachHo = NULL;

HoaDon* danhSachHoaDon = NULL;

void inBangThongTin(string a) {
    int width = 120;
    int padding = (width - a.length()) / 2;
    cout << "\n" << string(padding, ' ') << a << "\n";
    cout << string(width, '-') << endl;
}
// 1. Nhập danh sách hộ sử dụng điện
void nhapHoSuDungDien() {
    int n;
    cout << "Nhap so luong ho su dung dien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        HoSuDungDien* ho = new HoSuDungDien();
        cout << "Nhap thong tin cho ho thu " << (i + 1) << ":\n";

        cout << "Nhap ma ho: ";
        while (!(cin >> ho->maHo)) {
            cout << "Vui long nhap lai ma ho: ";
        }
        cin.ignore();

        cout << "Nhap ten ho: ";
        getline(cin, ho->tenHo);

        cout << "Nhap dia chi: ";
        getline(cin, ho->diaChi);

        cout << "Nhap so dien thoai: ";
        getline(cin, ho->soDienThoai);

        // Thêm vào danh sách liên kết
        ho->next = danhSachHo;
        danhSachHo = ho;

        cout << endl;
    }
}
// 2. Hiển thị danh sách hộ sử dụng điện
void hienThiDanhSachHo() {
    inBangThongTin("DANH SACH HO SU DUNG DIEN");

    if (danhSachHo == NULL) {
        cout << "Danh sach rong.\n";
        return;
    }

    cout << left;
    cout << setw(20) << "Ma Ho"
         << setw(30) << "Ten Ho"
         << setw(40) << "Dia Chi"
         << setw(15) << "So DT"
         << endl;

    HoSuDungDien* current = danhSachHo;
    while (current != NULL) {
        cout << setw(20) << current->maHo
             << setw(30) << current->tenHo
             << setw(40) << current->diaChi
             << setw(15) << current->soDienThoai
             << endl;
        current = current->next;
    }
    cout << endl;
}
// 3. Thêm hóa đơn tiền điện mới
void themHoaDon() {
    hienThiDanhSachHo();
    int maHo;
    cout << "Nhap ma ho de tao hoa don: ";
    while (!(cin >> maHo)) {
        cout << "Vui long nhap lai ma ho: ";
    }
    cin.ignore();

    // Kiểm tra mã hộ có tồn tại trong danh sách hộ sử dụng điện
    HoSuDungDien* ho = danhSachHo;
    bool hoTonTai = false;
    while (ho != NULL) {
        if (ho->maHo == maHo) {
            hoTonTai = true;
            break;
        }
        ho = ho->next;
    }
    if (!hoTonTai) {
        cout << "Ma ho khong ton tai trong danh sach!\n";
        return;
    }

    // Tạo mới hóa đơn
    HoaDon* hd = new HoaDon();

    cout << "Nhap ma hoa don: ";
    while (!(cin >> hd->maHoaDon)) {
        cout << "Vui long nhap lai ma hoa don: ";
    }
    cin.ignore();

    int soDien;
    cout << "Nhap so dien su dung trong thang: ";
    while (!(cin >> soDien)) {
        cout << "Vui long nhap lai so dien su dung: ";
    }
    cin.ignore();

    cout << "Nhap thoi gian: ";
    getline(cin, hd->thoiGian);

    hd->soTien = soDien * 3000;
    hd->maHo = maHo;
    hd->soDienThang = soDien;

    cout << "nhập ngày thành lập: "; getline(cin, hd->ngayThanhLap);

    // Thêm hóa đơn vào đầu danh sách hóa đơn
    hd->next = danhSachHoaDon;
    danhSachHoaDon = hd;

    cout << "Hoa don da duoc them thanh cong!\n";
}

// 4. Hiển thị tất cả thông tin hóa đơn
void hienThiHoaDon() {
    if (danhSachHoaDon == NULL) {
        cout << "Khong co hoa don nao trong danh sach!\n";
        return;
    }

    inBangThongTin("DANH SACH HOA DON TIEN DIEN");
    cout << left;
    cout << setw(10) << "Ma HD"
         << setw(10) << "Ma Ho"
         << setw(20) << "Ho Ten"
         << setw(30) << "Dia Chi"
         << setw(20) << "Thoi Gian"
         << setw(20) << "So Dien"
         << setw(10) << "So Tien"
         << setw(20) << "ngay thanh lap"
         << endl;

    HoaDon* hd = danhSachHoaDon;
    while (hd != NULL) {
        // Tìm hộ tương ứng với mã hóa đơn
        HoSuDungDien* ho = danhSachHo;
        while (ho != NULL && ho->maHo != hd->maHo) {
            ho = ho->next;
        }

        // Kiểm tra xem có tìm thấy hộ không
        if (ho == NULL) {
            cout << "Khong tim thay thong tin ho tuong ung!" << endl;
        } else {
            cout << setw(10) << hd->maHoaDon
                 << setw(10) << hd->maHo
                 << setw(20) << ho->tenHo
                 << setw(30) << ho->diaChi
                 << setw(20) << hd->thoiGian
                 << setw(20) << hd->soDienThang
                 << setw(10) << fixed << setprecision(2) << hd->soTien
                 << setw(20) << hd->ngayThanhLap << endl;
        }
        hd = hd->next;
    }
    cout << endl;
}

// 5. Thống kê tổng tiền đã thu
void thongKeTongTienThu() {
    double tongTien = 0;
    HoaDon* hd = danhSachHoaDon;
    while (hd != NULL) {
        tongTien += hd->soTien;
        hd = hd->next;
    }
    cout << "Tong tien da thu: " << tongTien << " VND\n";
}
// 6. Tìm kiếm hộ theo mã hộ
void timKiemHo() {
    int maHo;
    cout << "Nhap ma ho can tim: ";
    while (!(cin >> maHo)) {
        cout << "Vui long nhap lai ma ho: ";
    }
    cin.ignore();

    HoSuDungDien* ho = danhSachHo;
    while (ho != NULL) {
        if (ho->maHo == maHo) {
            inBangThongTin("THONG TIN HO SU DUNG DIEN");
            cout << left;
            cout << setw(20) << "Ma Ho"
                 << setw(30) << "Ten Ho"
                 << setw(40) << "Dia Chi"
                 << setw(15) << "So DT"
                 << endl;
            cout << setw(20) << ho->maHo
                 << setw(30) << ho->tenHo
                 << setw(40) << ho->diaChi
                 << setw(15) << ho->soDienThoai
                 << endl;
            return;
        }
        ho = ho->next;
    }
    cout << "Ma ho khong ton tai!\n";
}
// 7. Hiển thị hóa đơn theo mã hộ
void hienThiHoaDonTheoHo() {
    inBangThongTin("DANH SACH HO SU DUNG DIEN");
    HoSuDungDien* ho = danhSachHo;
    if (ho == NULL) {
        cout << "Khong co ho nao trong danh sach.\n";
        return;
    }

    cout << left;
    cout << setw(20) << "Ma Ho"
         << setw(30) << "Ho Ten"
         << setw(40) << "Dia Chi"
         << setw(15) << "So Dien Thoai"
         << endl;

    // Hiển thị thông tin tất cả hộ sử dụng điện
    while (ho != NULL) {
        cout << setw(20) << ho->maHo
             << setw(30) << ho->tenHo
             << setw(40) << ho->diaChi
             << setw(15) << ho->soDienThoai << endl;
        ho = ho->next;
    }

    int maHo;
    cout << "Nhap ma ho de hien thi hoa don: ";
    while (!(cin >> maHo)) {
        cout << "Vui long nhap lai ma ho: ";
    }
    cin.ignore();

    ho = danhSachHo;
    bool hoTonTai = false;
    while (ho != NULL) {
        if (ho->maHo == maHo) {
            hoTonTai = true;
            break;
        }
        ho = ho->next;
    }

    if (!hoTonTai) {
        cout << "Khong tim thay ma ho trong danh sach!\n";
        return;
    }

    HoaDon* hd = danhSachHoaDon;
    bool hoaDonTimThay = false;

    inBangThongTin("DANH SACH HOA DON TIEN DIEN CHO MA HO " + to_string(maHo));
    cout << left;
    cout << setw(10) << "Ma HD"
         << setw(10) << "Ma Ho"
         << setw(20) << "Ho Ten"
         << setw(30) << "Dia Chi"
         << setw(20) << "Thoi Gian"
         << setw(20) << "So Dien"
         << setw(10) << "So Tien"
         << endl;

    while (hd != NULL) {
        if (hd->maHo == maHo) {
            hoaDonTimThay = true;
            HoSuDungDien* ho = danhSachHo;
            while (ho != NULL && ho->maHo != hd->maHo) {
                ho = ho->next;
            }

            if (ho != NULL) {
                cout << setw(10) << hd->maHoaDon
                     << setw(10) << hd->maHo
                     << setw(20) << ho->tenHo
                     << setw(30) << ho->diaChi
                     << setw(20) << hd->thoiGian
                     << setw(20) << hd->soDienThang
                     << setw(10) << fixed << setprecision(2) << hd->soTien << endl;
            }
        }
        hd = hd->next;
    }

    if (!hoaDonTimThay) {
        cout << "Khong co hoa don nao cho ma ho " << maHo << endl;
    }
    cout << endl;
}

// 8. Xóa hộ sử dụng điện
void xoaHo() {
    inBangThongTin("DANH SACH HO SU DUNG DIEN");
    HoSuDungDien* ho = danhSachHo;
    cout << left;
    cout << setw(20) << "Ma Ho"
         << setw(30) << "Ten Ho"
         << setw(40) << "Dia Chi"
         << setw(15) << "So Dien Thoai"
         << endl;

    // Hiển thị thông tin các hộ sử dụng điện
    while (ho != NULL) {
        cout << setw(20) << ho->maHo
             << setw(30) << ho->tenHo
             << setw(40) << ho->diaChi
             << setw(15) << ho->soDienThoai << endl;
        ho = ho->next;
    }

    int maHo;
    cout << "Nhap ma ho can xoa: ";
    while (!(cin >> maHo)) {
        cout << "Vui long nhap lai ma ho: ";
    }
    cin.ignore();

    HoSuDungDien* truoc = NULL;
    HoSuDungDien* hienTai = danhSachHo;
    while (hienTai != NULL && hienTai->maHo != maHo) {
        truoc = hienTai;
        hienTai = hienTai->next;
    }
    if (hienTai != NULL) {
        if (truoc == NULL) {
            danhSachHo = hienTai->next;
        } else {
            truoc->next = hienTai->next;
        }
        delete hienTai;
        cout << "Ho da duoc xoa thanh cong!\n";
    } else {
        cout << "Ma ho khong ton tai!\n";
    }
}
// 9. Xóa hóa đơn
void xoaHoaDon() {
    inBangThongTin("DANH SACH HOA DON");
    HoaDon* hd = danhSachHoaDon;
    cout << left;
    cout << setw(10) << "Ma HD"
         << setw(10) << "Ma Ho"
         << setw(20) << "Ho Ten"
         << setw(30) << "Dia Chi"
         << setw(20) << "Thoi Gian"
         << setw(20) << "So Dien"
         << setw(10) << "So Tien" << endl;

    // Hiển thị tất cả hóa đơn
    while (hd != NULL) {
        HoSuDungDien* ho = danhSachHo;
        while (ho != NULL && ho->maHo != hd->maHo) {
            ho = ho->next;
        }
        if (ho != NULL) {
            cout << setw(10) << hd->maHoaDon
                 << setw(10) << hd->maHo
                 << setw(20) << ho->tenHo
                 << setw(30) << ho->diaChi
                 << setw(20) << hd->thoiGian
                 << setw(20) << hd->soDienThang
                 << setw(10) << fixed << setprecision(2) << hd->soTien << endl;
        }
        hd = hd->next;
    }

    int maHoaDon;
    cout << "Nhap ma hoa don can xoa: ";
    while (!(cin >> maHoaDon)) {
        cout << "Vui long nhap lai ma hoa don: ";
    }
    cin.ignore();

    HoaDon* truoc = NULL;
    HoaDon* hienTai = danhSachHoaDon;
    while (hienTai != NULL && hienTai->maHoaDon != maHoaDon) {
        truoc = hienTai;
        hienTai = hienTai->next;
    }
    if (hienTai != NULL) {
        if (truoc == NULL) {
            danhSachHoaDon = hienTai->next;
        } else {
            truoc->next = hienTai->next;
        }
        delete hienTai;
        cout << "Hoa don da duoc xoa thanh cong!\n";
    } else {
        cout << "Ma hoa don khong ton tai!\n";
    }
}
// 10. Ghi danh sách vào tệp
void ghiDanhSachVaoTep() {
    ofstream outHo("ho.txt");
    if (!outHo) {
        cout << "Khong the mo tep ho.txt de ghi\n";
        return;
    }

    // Ghi danh sách hộ vào tệp
    HoSuDungDien* tempHo = danhSachHo;
    while (tempHo != NULL) {
        outHo << tempHo->maHo << "," << tempHo->tenHo << "," << tempHo->diaChi << "," << tempHo->soDienThoai << endl;
        tempHo = tempHo->next;
    }
    outHo.close();

    ofstream outHoaDon("hoadon.txt");
    if (!outHoaDon) {
        cout << "Khong the mo tep hoadon.txt de ghi\n";
        return;
    }

    // Ghi danh sách hóa đơn vào tệp
    HoaDon* tempHD = danhSachHoaDon;
    while (tempHD != NULL) {
        outHoaDon << tempHD->maHoaDon << "," << tempHD->maHo << "," << tempHD->soDienThang << "," << tempHD->soTien << "," << tempHD->thoiGian << endl;
        tempHD = tempHD->next;
    }
    outHoaDon.close();

    cout << "Danh sach hoa don da duoc ghi vao tep hoadon.txt.\n";
}
// 11. Đọc danh sách từ tệp
void docDanhSachTuTep() {
    ifstream inHo("ho.txt");
    if (!inHo) {
        cout << "Khong the mo tep ho.txt.\n";
        return;
    }

    string line;
    while (getline(inHo, line)) {
        HoSuDungDien* ho = new HoSuDungDien;

        // Sử dụng stringstream để tách các trường
        stringstream ss(line);
        string maHoStr;
        getline(ss, maHoStr, ',');
        ho->maHo = stoi(maHoStr);
        getline(ss, ho->tenHo, ',');
        getline(ss, ho->diaChi, ',');
        getline(ss, ho->soDienThoai);
        cout << "Doc duoc: " << ho->maHo << ", " << ho->tenHo << ", " << ho->diaChi << ", " << ho->soDienThoai << endl;
    }
    inHo.close();

    // Đọc dữ liệu từ tệp hóa đơn
    ifstream inHoaDon("hoadon.txt");
    if (!inHoaDon) {
        cout << "Khong the mo tep hoadon.txt.\n";
        return;
    }

    while (getline(inHoaDon, line)) {
        HoaDon* hd = new HoaDon;

        stringstream ss(line);
        string maHoaDonStr, maHoStr, soDienStr, soTienStr;

        getline(ss, maHoaDonStr, ',');
        hd->maHoaDon = stoi(maHoaDonStr);

        getline(ss, maHoStr, ',');
        hd->maHo = stoi(maHoStr);

        getline(ss, soDienStr, ',');
        hd->soDienThang = stoi(soDienStr);

        getline(ss, soTienStr, ',');
        hd->soTien = stod(soTienStr);

        getline(ss, hd->thoiGian);
        cout << "Doc hoa don: " << hd->maHoaDon << ", " << hd->maHo << ", " << hd->soDienThang << ", " << hd->soTien << ", " << hd->thoiGian << endl;
    }
    inHoaDon.close();

    cout << "Danh sach da duoc doc tu tep.\n";
}
// 12. Cập nhật thông tin hộ sử dụng điện
void capNhatThongTinHo() {
    HoSuDungDien* ho = danhSachHo;
    cout << "DANH SACH CAC HO SU DUNG DIEN:\n";
    inBangThongTin("DANH SACH HO SU DUNG DIEN");
    cout << left;
    cout << setw(20) << "Ma Ho"
         << setw(30) << "Ten Ho"
         << setw(40) << "Dia Chi"
         << setw(15) << "So Dien Thoai" << endl;
    while (ho != NULL) {
        cout << setw(20) << ho->maHo
             << setw(30) << ho->tenHo
             << setw(40) << ho->diaChi
             << setw(15) << ho->soDienThoai << endl;
        ho = ho->next;
    }

    int maHo;
    cout << "Nhap ma ho can cap nhat: ";
    while (!(cin >> maHo)) {
        cout << "Vui long nhap lai ma ho: ";
    }
    cin.ignore();

    ho = danhSachHo;
    while (ho != NULL) {
        if (ho->maHo == maHo) {
            cout << "Nhap ten ho moi: ";
            getline(cin, ho->tenHo);

            cout << "Nhap dia chi moi: ";
            getline(cin, ho->diaChi);

            cout << "Nhap so dien thoai moi: ";
            getline(cin, ho->soDienThoai);
            cout << "Thong tin ho da duoc cap nhat!\n";
            return;
        }
        ho = ho->next;
    }

    cout << "Ma ho khong ton tai!\n";
}
// 13. Cập nhật thông tin hóa đơn
void capNhatThongTinHoaDon() {
    HoaDon* hd = danhSachHoaDon;
    cout << "DANH SACH CAC HOA DON:\n";
    inBangThongTin("DANH SACH HOA DON");
    cout << left;
    cout << setw(10) << "Ma HD"
         << setw(10) << "Ma Ho"
         << setw(20) << "Ho Ten"
         << setw(30) << "Dia Chi"
         << setw(20) << "Thoi Gian"
         << setw(20) << "So Dien"
         << setw(10) << "So Tien" << endl;
    while (hd != NULL) {
        HoSuDungDien* ho = danhSachHo;
        while (ho != NULL) {
            if (ho->maHo == hd->maHo) {
                cout << setw(10) << hd->maHoaDon
                     << setw(10) << hd->maHo
                     << setw(20) << ho->tenHo
                     << setw(30) << ho->diaChi
                     << setw(20) << hd->thoiGian
                     << setw(20) << hd->soDienThang
                     << setw(10) << fixed << setprecision(2) << hd->soTien << endl;
                break;
            }
            ho = ho->next;
        }
        hd = hd->next;
    }

    int maHoaDon;
    cout << "Nhap ma hoa don can cap nhat: ";
    while (!(cin >> maHoaDon)) {
        cout << "Vui long nhap lai ma hoa don: ";
    }
    cin.ignore();

    hd = danhSachHoaDon;
    while (hd != NULL) {
        if (hd->maHoaDon == maHoaDon) {
            cout << "Nhap so dien moi: ";
            while (!(cin >> hd->soDienThang)) {
                cout << "Vui long nhap so dien hop le: ";
            }

            cin.ignore();
            cout << "Nhap thoi gian moi: ";
            getline(cin, hd->thoiGian);

            hd->soTien = hd->soDienThang * 3000.0;

            cout << "Thong tin hoa don da duoc cap nhat!\n";
            return;
        }
        hd = hd->next;
    }

    cout << "Ma hoa don khong ton tai!\n";
}
// 14. Sắp xếp danh sách hóa đơn theo số tiền (giảm dần)
void sapXepDanhSachHoaDon() {
    if (danhSachHoaDon == NULL || danhSachHoaDon->next == NULL) {
        cout << "Danh sach hoa don da duoc sap xep.\n";
        return;
    }
    for (HoaDon* i = danhSachHoaDon; i != NULL; i = i->next) {
        for (HoaDon* j = i->next; j != NULL; j = j->next) {
            if (i->soTien < j->soTien) {
                swap(i->maHoaDon, j->maHoaDon);
                swap(i->maHo, j->maHo);
                swap(i->soDienThang, j->soDienThang);
                swap(i->soTien, j->soTien);
                swap(i->thoiGian, j->thoiGian);
            }
        }
    }
    cout << "Danh sach hoa don da duoc sap xep theo so tien giam dan\n";
}
// 15. Hiển thị hóa đơn theo giá trị tiền
void hienThiHoaDonTheoGiaTriTien() {
    double giaTriTien;
    cout << "Nhap gia tri tien de tim hoa don: ";
    while (!(cin >> giaTriTien)) {  // Kiểm tra giá trị nhập
        cout << "Vui long nhap gia tri tien hop le: ";
    }

    bool timThay = false;
    HoaDon* hd = danhSachHoaDon;
    while (hd != NULL) {
        if (hd->soTien >= giaTriTien) {
            timThay = true;
            HoSuDungDien* ho = danhSachHo;
            while (ho != NULL && ho->maHo != hd->maHo) {
                ho = ho->next;
            }
            if (ho != NULL) {
                inBangThongTin("CHI TIET HOA DON TIEN DIEN");
                cout << left;
                cout << setw(15) << "Ma HD"
                     << setw(15) << "Ma Ho"
                     << setw(20) << "Ho Ten"
                     << setw(30) << "Dia Chi"
                     << setw(15) << "So Dien"
                     << setw(15) << "So Tien" << endl;
                cout << setw(15) << hd->maHoaDon
                     << setw(15) << hd->maHo
                     << setw(20) << ho->tenHo
                     << setw(30) << ho->diaChi
                     << setw(15) << hd->soDienThang
                     << setw(15) << fixed << setprecision(2) << hd->soTien << endl;
            }
        }
        hd = hd->next;
    }
    if (!timThay) {
        cout << "Khong tim thay hoa don voi gia tri tien lon hon hoac bang " << giaTriTien << endl;
    }
}

// 16. Tìm kiếm hóa đơn theo ngày thành lập
void timKiemHoaDonTheoNgay() {
    string ngayCanTim;
    cout << "Nhap ngay thanh lap can tim (dd/mm/yyyy): ";
    getline(cin, ngayCanTim);

    bool timThay = false;
    HoaDon* hd = danhSachHoaDon;

    inBangThongTin("HOA DON THEO NGAY THANH LAP " + ngayCanTim);
    cout << left;
    cout << setw(10) << "Ma HD"
         << setw(10) << "Ma Ho"
         << setw(20) << "Ho Ten"
         << setw(30) << "Dia Chi"
         << setw(20) << "Thoi Gian"
         << setw(20) << "So Dien"
         << setw(10) << "So Tien"
         << setw(20) << "Ngay TL" << endl;

    while (hd != NULL) {
        if (hd->ngayThanhLap == ngayCanTim) {
            timThay = true;
            HoSuDungDien* ho = danhSachHo;
            while (ho != NULL && ho->maHo != hd->maHo) {
                ho = ho->next;
            }

            if (ho != NULL) {
                cout << setw(10) << hd->maHoaDon
                     << setw(10) << hd->maHo
                     << setw(20) << ho->tenHo
                     << setw(30) << ho->diaChi
                     << setw(20) << hd->thoiGian
                     << setw(20) << hd->soDienThang
                     << setw(10) << fixed << setprecision(2) << hd->soTien
                     << setw(20) << hd->ngayThanhLap << endl;
            }
        }
        hd = hd->next;
    }

    if (!timThay) {
        cout << "Khong tim thay hoa don nao duoc lap vao ngay " << ngayCanTim << endl;
    }
}

void thoatChuongTrinh() {
    cout << "Thank you!" << endl;
    exit(0);
}
int main() {
    while (true) {
        cout << "--------------------- MENU ----------------------\n";
        cout << "1. Nhap danh sach ho su dung dien\n";
        cout << "2. Hien thi danh sach ho su dung dien\n";
        cout << "3. Them hoa don moi\n";
        cout << "4. Hien thi danh sach hoa don\n";
        cout << "5. Thong ke tong tien da thu\n";
        cout << "6. Tim kiem ho theo ma ho\n";
        cout << "7. Hien thi hoa don theo ma ho\n";
        cout << "8. Xoa ho su dung dien\n";
        cout << "9. Xoa hoa don\n";
        cout << "10. Ghi danh sach vao tep\n";
        cout << "11. Doc danh sach tu tep\n";
        cout << "12. Cap nhat thong tin ho su dung dien\n";
        cout << "13. Cap nhat thong tin hoa don\n";
        cout << "14. Sap xep danh sach hoa don\n";
        cout << "15. Hien thi hoa don theo gia tri tien\n";
        cout << "16. Tim kiem hoa don theo ngay thanh lap\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";

        int luaChon;
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                nhapHoSuDungDien();
                break;
            case 2:
                hienThiDanhSachHo();
                break;
            case 3:
                themHoaDon();
                break;
            case 4:
                hienThiHoaDon();
                break;
            case 5:
                thongKeTongTienThu();
                break;
            case 6:
                timKiemHo();
                break;
            case 7:
                hienThiHoaDonTheoHo();
                break;
            case 8:
                xoaHo();
                break;
            case 9:
                xoaHoaDon();
                break;
            case 10:
                ghiDanhSachVaoTep();
                break;
            case 11:
                docDanhSachTuTep();
                break;
            case 12:
                capNhatThongTinHo();
                break;
            case 13:
                capNhatThongTinHoaDon();
                break;
            case 14:
                sapXepDanhSachHoaDon();
                break;
            case 15: