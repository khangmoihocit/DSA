#ifndef LOPHOC_H
#define LOPHOC_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "sinhvien.h"
using namespace std;

struct LopHoc{
    int maLop;
    char tenLop[20];
};

struct Node{
    LopHoc data;
    Node *pNext;
    Node *pPrevious;
    BSTree rootSinhVien;
};

struct DoubleLinkedList{
    Node *pHead;
    Node *pTail;
};

void InitializeLopHoc(DoubleLinkedList &list){
    list.pHead = NULL;
    list.pTail = NULL;
}

Node * CreateNode(LopHoc data){
    Node *pNode = new Node;
    if(pNode != NULL){
        pNode->data = data;
        pNode->pNext = NULL;
        pNode->pPrevious = NULL; 
    }else{
        cout << "cấp phát bộ nhớ thất bại!";
    }
    return pNode;
}

void InsertLastLopHoc(DoubleLinkedList &list, LopHoc data){
    Node *pNode = CreateNode(data);
    if(list.pHead == NULL){
        list.pHead = list.pTail = pNode;
    }else{
        list.pTail->pNext = pNode;
        pNode->pPrevious = list.pTail;
        list.pTail = pNode;
    }
}

int SizeOfListLopHoc(DoubleLinkedList list){
    Node *pTmp = list.pHead;
    int count = 0;
    while(pTmp != NULL){
        count++;
        pTmp = pTmp->pNext;
    }
    return count;
}

void PrintListLopHoc(DoubleLinkedList list){
    Node *pTmp = list.pHead;
    if(list.pHead == NULL){
        cout << "Danh sách rỗng.\n";
    }else{
        cout << left << setw(20) << "Mã lớp" << setw(20) << "Tên lớp" << endl;
        while(pTmp != NULL){
            cout << left << setw(20) << pTmp->data.maLop << setw(20) << pTmp->data.tenLop << endl;
            pTmp = pTmp->pNext;
        }
    }
}

void WriteFileLopHoc(DoubleLinkedList list, string fileName){
    ofstream file(fileName, ios::binary);
    
    if(file.is_open()){
        int n = SizeOfListLopHoc(list);
        file.write((char*)&n, sizeof(int));
        Node *pTmp = list.pHead;
        while(pTmp != NULL){
            file.write((char*)&pTmp->data, sizeof(LopHoc));
            pTmp = pTmp->pNext;
        }
        file.close();
        cout << "ghi vào file " << fileName << " thành công!\n";
    }else{
        cout << "không thể mở file để ghi\n";
    }
}

void ReadFileLopHoc(DoubleLinkedList &list, string fileName){
    ifstream file(fileName, ios::binary);
    
    if(file.is_open()){
        int n;
        file.read((char*)&n, sizeof(int));
        for(int i=0; i<n; ++i){
            LopHoc lopHoc;
            file.read((char*)&lopHoc, sizeof(LopHoc));
            InsertLastLopHoc(list, lopHoc);
        }
        file.close();
        cout << "đọc file " << fileName << " thành công!\n";
    }else{
        cout << "không thể mở file để đọc!\n";
    }
}

//thêm lớp học từ bàn phím
// LopHoc InputLopHoc(){
//     LopHoc lopHoc;
//     cout << "Nhập mã lớp: "; cin >> lopHoc.maLop;
//     cin.ignore();
//     cout << "Nhập tên lớp: "; cin.getline(lopHoc.tenLop, 20);
//     return lopHoc;
// }

// Node * SearchNodeById(DoubleLinkedList list, int maLop){
//     Node *pTmp = list.pHead;
//     while(pTmp != NULL){
//         if(pTmp->data.maLop == maLop) break;
//         pTmp = pTmp->pNext;
//     }
//     return pTmp;
// }

// void TimTheoMaLop(DoubleLinkedList list){
//     int maLop;
//     cout << "Nhập mã lớp: "; cin >> maLop;
//     Node *pNode = SearchNodeById(list, maLop);
//     if(pNode == NULL){
//         cout << "không tìm thấy!.\n";
//     }else{
//         cout << left << setw(20) << "Mã lớp" << setw(20) << "Tên lớp" << endl;
//         cout << left << setw(20) << pNode->data.maLop << setw(20) << pNode->data.tenLop << endl;
//     }  
// }

LopHoc inputLopHoc(){
    LopHoc lopHoc;
    cout << "Nhập mã lớp: "; cin >> lopHoc.maLop;
    cin.ignore();
    cout << "Nhập tên lớp: "; cin.getline(lopHoc.tenLop, 20);
    return lopHoc;
}

Node * searchLopById(DoubleLinkedList list, int maLop){
    Node *pTmp = list.pHead;
    while(pTmp != NULL){
        if(pTmp->data.maLop == maLop) break;
        pTmp = pTmp->pNext;
    }
    return pTmp;
}

void addSinhVien_LopHoc(DoubleLinkedList listLopHoc){ //thêm 1 sinh viên vô 1 lớp học
    int maLop, n = 0;
    cout << "nhập mã lớp để thêm sinh viên: "; cin >> maLop;
    Node *pNode = searchLopById(listLopHoc, maLop);
    while(pNode == NULL){
        n++;
        if(n == 3){
            cout << "Vui lòng thử lại!\n";
            break;
        }
        cout << "mã lớp không tồn tại. Vui lòng nhập lại!\n";
        cout << "nhập mã lớp để thêm sinh viên: "; cin >> maLop;
        pNode = searchLopById(listLopHoc, maLop);
    }
    if(pNode != NULL){
        SinhVien sinhVien = inputSinhVien();
        insertSinhVien(pNode->rootSinhVien, sinhVien);
        cout << "-> Thêm thành công sinh viên vào lớp " << pNode->data.maLop << "\n";
    }
}

// DoubleLinkedList searchLopHocById(DoubleLinkedList list, int maLop){
//     DoubleLinkedList listById;
//     initializeLopHoc(listById);

//     Node *pTmp = list.pHead;
//     while(pTmp != NULL){
//         if(pTmp->data.maLop == maLop){
//             insertLastLopHoc(listById);
//         }
//         pTmp = pTmp->pNext;
//     }
//     return listById;
// }

// void timLopHocTheoMa(DoubleLinkedList list){
//     int maLop;
//     cout << "Nhập mã lớp: "; cin >> maLop;
//     if(list.pHead == NULL){
//         cout << "không tìm thấy.\n";
//         return;
//     }

//     DoubleLinkedList listById = searchLopHocById(list, maLop);
//     if(listById.pHead == NULL){
//         cout << "không tìm thấy.\n";
//     }else{
//         printListLopHoc(listById);
//     }
// }
#endif