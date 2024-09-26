#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *pNext;
};

struct SingleList{
    Node *pHead;
};

void createList(SingleList &list){
    list.pHead = NULL;
}

//tạo node
Node * createNode(int d){
    Node *pNode = new Node;
    if(pNode != NULL){
        pNode->data = d;
        pNode->pNext = NULL;
    }else{
        cout << "cap phat bo nho that bai";
    }
    return pNode;
}

void PrintList(SingleList list){
    Node *pTmp = list.pHead;
    if(pTmp == NULL){
        cout << "danh sách rỗng";
    }
    while(pTmp != NULL){
        cout << pTmp->data << " ";
        pTmp = pTmp->pNext;
    }
}

void AddHead(SingleList &list, Node *q){
    if(list.pHead == NULL){
        list.pHead = q;
    }else{
        q->pNext = list.pHead;
        list.pHead = q;
    }
}

int SizeOfList(SingleList list){
    Node *pTmp = list.pHead;
    int n=0;
    while(pTmp != NULL){
        n++;
        pTmp = pTmp->pNext;
    }
    return n;
}

void InsertFirst(SingleList &list, int d){
    Node *pNode = createNode(d);
    if(list.pHead == NULL){
        list.pHead = pNode;
    }else{
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void InsertLast(SingleList &list, int d){
    Node *pNode = createNode(d);
    if(list.pHead == NULL){
        list.pHead = pNode;
    }else{
        Node *pTmp = list.pHead;
        while(pTmp->pNext != NULL){
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
    }
}

void InsertMid(SingleList &list, int pos, int d){
    if(pos<0 || pos >= SizeOfList(list)){ //kiểm tra vị trí truyền vô có hợp lệ k
        cout << "not valid position do insert\n";
    }
    if(pos == 0){
        InsertFirst(list, d);
    }else if(pos == SizeOfList(list)-1){
        InsertLast(list, d);
    }else{
        Node *pNode = createNode(d);
        Node *pIns = list.pHead;
        Node *pPre = NULL;
        int i=0;
        while(pIns != NULL){
            if(i==pos) break;
            pPre = pIns;
            pIns = pIns->pNext;
            ++i;
        }
        pPre->pNext = pNode;
        pNode->pNext = pIns;
    }
}

void RemoveNode(SingleList &list, int d){
    Node *pDel = list.pHead;
    if(pDel == NULL){ //kiểm tra danh sách có phần tử nào chưa
        cout << "The list is empty!\n";
    }else{
        Node *pPre = NULL;
        while(pDel != NULL){ //dịch chuyển con trỏ pDel đến vị trí cần xóa
            if(pDel->data == d) break; //vị trí cần xóa
            pPre = pDel;
            pDel = pDel->pNext;
        }
        if(pDel == NULL){
            cout << "Could not found number!";
        }else{
            if(pDel == list.pHead){ //xóa con trỏ ở vị trí đầu
                list.pHead = list.pHead->pNext;
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }else{ //xóa con trỏ ở vị trí bất kì
                pPre->pNext = pDel->pNext;
                pDel->pNext = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}

Node * SearchNode(SingleList list, int d){
    Node *pTmp = list.pHead;
    while(pTmp != NULL){
        if(pTmp->data == d) break;
        pTmp = pTmp->pNext;
    }
    return pTmp;
}

void SortList(SingleList &list){
    for(Node *pTmp1 = list.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext){
        for(Node *pTmp2 = pTmp1->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext){
            if(pTmp1->data > pTmp2->data){
                swap(pTmp1->data, pTmp2->data);
            }
        }
    }
}

void xoatheodieukien(SingleList &l){
    Node *pDel = l.pHead;
    Node *pPre = NULL;
    while (pDel != NULL) {
        if (pDel->data > 10) {
            if (pDel == l.pHead) {
            // Xóa node đầu tiên
                l.pHead = l.pHead->pNext;
                delete pDel;
                pDel = l.pHead;  // Cập nhật pDel sau khi xóa node
            } else {
            // Xóa node ở giữa hoặc cuối
                pPre->pNext = pDel->pNext;
                delete pDel;
                pDel = pPre->pNext;  // Cập nhật pDel sau khi xóa node
            }
        }else {
            // Duyệt sang node tiếp theo nếu không xóa
            pPre = pDel;
            pDel = pDel->pNext;
        }
    }
}

int main(){
    SingleList l;
    createList(l);
    AddHead(l, createNode(10));
    AddHead(l, createNode(20));
    AddHead(l, createNode(30));
    AddHead(l, createNode(40));

    InsertFirst(l, 100);
    InsertLast(l, 200);
    InsertMid(l, 2, 3);
    InsertMid(l, 7, 3);



    PrintList(l);
    cout << "\n----\n";


    PrintList(l);
    cout << endl;
    // SortList(l);
    // cout << endl << SearchNode(l, 10)->data;
    // cout << endl << SizeOfList(l);

    return 0;
}
