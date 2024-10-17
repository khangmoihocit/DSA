#include <bits/stdc++.h>
using namespace std;
//SinhVien: cay nhi phan tim kiem
//LopHoc: danh sach lien ket doi

struct SinhVien{
    int maSV;
    char tenSV[250];
};

struct LopHoc{
    int maLop;
    char tenLop[20];
};

struct NodeSinhVien{
    SinhVien data;
    NodeSinhVien *pLeft;
    NodeSinhVien *pRight;
};

typedef NodeSinhVien *BSTree;

struct NodeLopHoc{
    LopHoc data;
    NodeLopHoc *pNext;
    NodeLopHoc *pPrevious;
    BSTree rootSinhVien;
};

struct DoubleLinkedList{
    NodeLopHoc *pHead;
    NodeLopHoc *pTail;
};

//prototypes lophoc
void initializeLopHoc(DoubleLinkedList &list);
void timKiemLopHoc(DoubleLinkedList list); //tim kiem lop hoc theo ma lop
void insertLopHoc(DoubleLinkedList &list, LopHoc data);
LopHoc inputLopHoc();
void printListLopHoc(DoubleLinkedList list); //hien danh sach lop hoc
void addSinhVien_LopHoc(DoubleLinkedList listLopHoc); //them 1 sinh vien vao 1 lop hoc
void printListSinhVien_LopHoc(DoubleLinkedList listLopHoc); //hien danh sach sinh vien cua 1 lop hoc
void WriteFileLopHoc(DoubleLinkedList list, string fileName);
void ReadFileLopHoc(DoubleLinkedList &list, string fileName);
void menu();

int main(){
    DoubleLinkedList listLopHoc; 
    initializeLopHoc(listLopHoc);
    int chon;
    do{
        menu();
        cout << "chon: "; 
        cin >> chon;
        cin.ignore();
        switch(chon){
            case 1:
                addSinhVien_LopHoc(listLopHoc); break;
            case 2:
                printListSinhVien_LopHoc(listLopHoc); break;
            case 3:
                insertLopHoc(listLopHoc, inputLopHoc()); break;
            case 4:
                printListLopHoc(listLopHoc); break;
            case 5:
                timKiemLopHoc(listLopHoc); break;
            case 6:
                ReadFileLopHoc(listLopHoc, "lophoc.txt"); break;
            case 7:
                WriteFileLopHoc(listLopHoc, "lophoc.txt"); break;
            case 0:
                break;
            default :
                cout << "lỗi\n"; break; 
        }

    }while(chon != 0);
    return 0;
}


void menu(){
    cout << "1. them sinh vien.\n";
    cout << "2. hien list sinh vien.\n";
    cout << "3. them lop hoc.\n";
    cout << "4. hien danh sach lop hoc.\n";
    cout << "5. tim lop hoc\n";
    cout << "6. doc file\n";
    cout << "7. ghi file\n";
    cout << "0. thoat\n";
}

//sinhvien
void initializeSinhVien(BSTree &root){
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

void printListSinhVien(BSTree root){
    if(root != NULL){
        cout << left  << setw(20) << "Mã sinh viên" << setw(20) << "tên sinh viên" << endl;
        inOrder_LNR(root);
    }else{
        cout << "danh sách sinh viên rỗng!\n";
    }
}

SinhVien inputSinhVien(){
    SinhVien sv;
    cout << "Nhập mã sinh viên: "; cin >> sv.maSV; cin.ignore();
    cout << "Nhập tên sinh viên: "; cin.getline(sv.tenSV, 250);
    return sv;
}

//lophoc
void initializeLopHoc(DoubleLinkedList &list){
    list.pHead = NULL;
    list.pTail = NULL;
}

NodeLopHoc * createNodeLopHoc(LopHoc data){
    NodeLopHoc *pNode = new NodeLopHoc;
    if(pNode != NULL){
        pNode->data = data;
        pNode->pNext = NULL;
        pNode->pPrevious = NULL; 
        pNode->rootSinhVien = NULL;
    }else{
        cout << "cấp phát bộ nhớ thất bại!";
    }
    return pNode;
}

void insertLopHoc(DoubleLinkedList &list, LopHoc data){
    NodeLopHoc *pNode = createNodeLopHoc(data);
    if(list.pHead == NULL){
        list.pHead = list.pTail = pNode;
    }else{
        list.pTail->pNext = pNode;
        pNode->pPrevious = list.pTail;
        list.pTail = pNode;
    }
}

int sizeOfListLopHoc(DoubleLinkedList list){
    NodeLopHoc *pTmp = list.pHead;
    int count = 0;
    while(pTmp != NULL){
        count++;
        pTmp = pTmp->pNext;
    }
    return count;
}

void printListLopHoc(DoubleLinkedList list){
    NodeLopHoc *pTmp = list.pHead;
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

LopHoc inputLopHoc(){
    LopHoc lopHoc;
    cout << "Nhập mã lớp: "; cin >> lopHoc.maLop;
    cin.ignore();
    cout << "Nhập tên lớp: "; cin.getline(lopHoc.tenLop, 20);
    return lopHoc;
}

NodeLopHoc * searchLopById(DoubleLinkedList list, int maLop){
    NodeLopHoc *pTmp = list.pHead;
    while(pTmp != NULL){
        if(pTmp->data.maLop == maLop) break;
        pTmp = pTmp->pNext;
    }
    return pTmp;
}

void WriteFileLopHoc(DoubleLinkedList list, string fileName){
    ofstream file(fileName, ios::binary);
    
    if(file.is_open()){
        int n = sizeOfListLopHoc(list);
        file.write((char*)&n, sizeof(int));
        NodeLopHoc *pTmp = list.pHead;
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
            insertLopHoc(list, lopHoc);
        }
        file.close();
        cout << "đọc file " << fileName << " thành công!\n";
    }else{
        cout << "không thể mở file để đọc!\n";
    }
}

//custom
void timKiemLopHoc(DoubleLinkedList list){ //tim kiem lop hoc theo ma
    int maLop;
    cout << "Nhập mã lớp muốn tìm: "; cin >> maLop;

    NodeLopHoc *pNode = searchLopById(list, maLop);
    
    if(pNode == NULL){
        cout << "không tìm thấy.";
    }else{
        cout << left << setw(20) << "Mã lớp" << setw(20) << "Tên lớp" << endl;
        cout << left << setw(20) << pNode->data.maLop << setw(20) << pNode->data.tenLop << endl;
    }
}

void addSinhVien_LopHoc(DoubleLinkedList listLopHoc){ //thêm 1 sinh viên vô 1 lớp học
    int maLop, n = 0;
    cout << "nhập mã lớp để thêm sinh viên: "; cin >> maLop;
    NodeLopHoc *pNodeLopHoc = searchLopById(listLopHoc, maLop);
    while(pNodeLopHoc == NULL){
        n++;
        if(n == 3){
            cout << "Vui lòng thử lại!\n";
            break;
        }
        cout << "mã lớp không tồn tại. Vui lòng nhập lại!\n";
        cout << "nhập mã lớp để thêm sinh viên: "; cin >> maLop;
        pNodeLopHoc = searchLopById(listLopHoc, maLop);
    }
    if(pNodeLopHoc != NULL){
        SinhVien sinhVien = inputSinhVien();
        insertSinhVien(pNodeLopHoc->rootSinhVien, sinhVien);
        cout << "-> Thêm thành công sinh viên vào lớp " << pNodeLopHoc->data.maLop << "\n";
    }
}

BSTree getListSinhVien_LopHoc(DoubleLinkedList listLopHoc, int maLop){ // laay danh sách sinh viên từ 1 lớp
    NodeLopHoc *pNodeLopHoc = searchLopById(listLopHoc, maLop);
    if(pNodeLopHoc == NULL){
        cout << "không tìm thấy lớp học!\n";
        return NULL;
    }
    return pNodeLopHoc->rootSinhVien;
}

void printListSinhVien_LopHoc(DoubleLinkedList listLopHoc){ //hien danh sach sinh vien tu 1 lop
    int maLop;
    cout << "nhập mã lớp muốn xem danh sách sinh viên: ";
    cin >> maLop;
    BSTree rootSinhVien = getListSinhVien_LopHoc(listLopHoc, maLop);
    printListSinhVien(rootSinhVien);
}
