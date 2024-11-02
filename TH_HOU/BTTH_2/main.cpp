#include <iostream>
#include <iomanip>
#include "sinhvien.h"
#include "LopHoc.h"
using namespace std;
int main(){
    
    DoubleLinkedList list;
    InitializeLopHoc(list);
    BSTree root;
    InitializeSinhVien(root);
    SinhVien sv;
    sv.maSV = 1001;
    strcpy(sv.tenSV, "khang");
    insertSinhVien(root, sv);
    inOrder_LNR(root);
    addSinhVien_LopHoc(list);

}