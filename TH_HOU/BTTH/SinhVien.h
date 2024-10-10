#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
    int maSV;
    char tenSV[250];
};

struct TNode{
    SinhVien data;
    TNode *pLeft;
    TNode *pRight;
};

typedef TNode * BSTree;

void InitializeSinhVien(BSTree &root){
    root = NULL;
}

TNode * CreateTNode(SinhVien data){
    TNode *pNode = new TNode;
    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

void InsertSinhVien(BSTree &root, SinhVien data){
    TNode *pNode = CreateTNode(data);
    if(root == NULL){
        root = pNode;
    }else{
        BSTree tmp = root;
        BSTree parent = NULL;
        while(tmp != NULL){
            parent = tmp;
            if(pNode->data.maSV > tmp->data.maSV){
                tmp = tmp->pRight;
            }else{
                tmp = tmp->pLeft;
            }
        }
        if(pNode->data.maSV < parent->data.maSV){
            parent->pLeft = pNode;
        }else{
            parent->pRight = pNode;
        }
    }
}

void InOrder_LNR(BSTree root){
    if(root != NULL){
        InOrder_LNR(root->pLeft);
        cout << left << setw(15) << root->data.maSV << setw(20) << root->data.tenSV << endl;
        InOrder_LNR(root->pRight); 
    }
}

SinhVien InputSinhVien(){
    SinhVien sv;
    cout << "Nhập mã sinh viên: "; cin >> sv.maSV; cin.ignore();
    cout << "Nhập tên sinh viên: "; cin.getline(sv.tenSV, 250);
    return sv;
}