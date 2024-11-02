#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct SinhVien{
    int maSV;
    char tenSV[30];
};

struct NodeSinhVien{
    SinhVien data;
    NodeSinhVien *pLeft;
    NodeSinhVien *pRight;
};

typedef NodeSinhVien *BSTree;

void InitializeSinhVien(BSTree &root){
    root = NULL;
}

NodeSinhVien * createNodeSinhVien(SinhVien data){
    NodeSinhVien *pNode = new NodeSinhVien;
    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

void insertSinhVien(BSTree &root, SinhVien data){
    NodeSinhVien *pNode = createNodeSinhVien(data);
    if(root == NULL){
        root = pNode;
    }else{
        BSTree tmp = root;
        BSTree parent = NULL;
        while(tmp != NULL){
            parent = tmp;
            if(pNode->data.maSV < tmp->data.maSV){
                tmp = tmp->pLeft;
            }else{
                tmp = tmp->pRight;
            }
        }
        if(pNode->data.maSV < parent->data.maSV){
            parent->pLeft = pNode;
        }else{
            parent->pRight = pNode;
        }
    }
}

void inOrder_LNR(BSTree root){
    if(root != NULL){
        inOrder_LNR(root->pLeft);
        cout << left << setw(15) << root->data.maSV << setw(20) << root->data.tenSV << endl;
        inOrder_LNR(root->pRight); 
    }
}

SinhVien inputSinhVien(){
    SinhVien sv;
    cout << "Nhập mã sinh viên: "; cin >> sv.maSV; cin.ignore();
    cout << "Nhập tên sinh viên: "; cin.getline(sv.tenSV, 250);
    return sv;
}
#endif