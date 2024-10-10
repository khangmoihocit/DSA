#include <bits/stdc++.h>
#include "LopHoc.h"
#include "SinhVien.h"
using namespace std;

const string FILE_NAME_LOPHOC = "lophoc.txt";
const string FILE_NAME_SINHVIEN = "sinhvien.txt";

int main(){
    DoubleLinkedList listLopHoc;
    InitializeLopHoc(listLopHoc);
    BSTree listSinhVien;
    InitializeSinhVien(listSinhVien);

    int choice;
    do{
        cout << "------MENU------\n"
             << "1. Lớp học.\n"
             << "2. Sinh viên.\n"
             << "0. Thoát.\n";
        cout << "chọn: "; cin >> choice;
        switch(choice){
            case 1:{
                int choice1;
                do{
                    cout << "------MENU------\n"
                         << "1. Thêm lớp học.\n"
                         << "2. Hiện danh sách lớp học.\n"
                         << "3. Tìm lớp theo mã.\n"
                         << "4. Ghi file\n"
                         << "5. Đọc file\n"
                         << "6. Quay lại.\n"
                         << "0. Thoát.\n";
                    cout << "chọn: "; cin >> choice1;
                    switch(choice1){
                        case 1:
                            InsertLastLopHoc(listLopHoc, InputLopHoc());
                            break;
                        case 2:
                            PrintListLopHoc(listLopHoc);
                            break;
                        case 3:
                            TimTheoMaLop(listLopHoc);
                            break;
                        case 4:
                            WriteFileLopHoc(listLopHoc, FILE_NAME_LOPHOC);
                            break;
                        case 5:
                            ReadFileLopHoc(listLopHoc, FILE_NAME_LOPHOC);
                            break;
                        case 6:
                            break;
                        case 0:
                            exit(0);
                            break;
                    }
                }while(choice1 != 6);
            }
            case 2:{
                int choice2;
                do{
                    cout << "------MENU------\n"
                         << "1. Thêm sinh viên.\n"
                         << "2. Hiện danh sách sinh viên.\n"
                         << "3. Thoát.\n";
                    cout << "chọn: "; cin >> choice2;
                    switch(choice2){
                        case 1:
                            InsertSinhVien(listSinhVien, InputSinhVien());
                            break;
                        case 2:
                            InOrder_LNR(listSinhVien);
                            break;
                        case 0:
                            exit(0);
                            break;
                    }
                }while(choice2 != 0);
            }
        }
    }while(choice != 0);
    return 0;
}