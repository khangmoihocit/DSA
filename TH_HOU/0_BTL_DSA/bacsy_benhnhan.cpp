#include <bits/stdc++.h>
using namespace std;

struct BacSy{
	int maBS;
	char tenBS[30];
	char chuyenKhoa[250];
	char soDienThoai[30];
	char email[30];
};

struct BenhNhan{
	int maBN;
	char tenBN[30];
	int tuoiBN;
	char gioiTinh[30]; //chi nhan 'nam' hoac 'nu'
	char diaChi[250];
	char trieuChung[250];
};

//benh nhan: cay nhi phan tim kiem
struct NodeBenhNhan{
	BenhNhan data;
	NodeBenhNhan *pLeft;
	NodeBenhNhan *pRight;
};

typedef NodeBenhNhan *BSTree; 

//bac sy: danh sach lien ket doi
struct NodeBacSy{
	BacSy data;
	NodeBacSy *pNext;
	NodeBacSy *pPrevious;
	BSTree root; //danh sach benh nhan
};

struct DoubleLinkedList{
	NodeBacSy *pHead;
	NodeBacSy *pTail;
};

//benh nhan
void menuBenhNhan();
void quanLyBenhNhan(BSTree &root, int &chon);
void InitializeBenhNhan(BSTree &root);
void InsertBenhNhan(BSTree &root, BenhNhan data); //them benh nhan
void PrintListBenhNhan(BSTree root); //hien danh sach
BenhNhan InputBenhNhan();
void WriteFileBenhNhan(BSTree root, string fileName); //ghi file
void ReadFileBenhNhan(BSTree &root, string fileName); //doc file
NodeBenhNhan * SearchBenhNhanById(BSTree root, int maBN);
//bac sy
void menuBacSy();
void quanLyBacSy(DoubleLinkedList &list, int &chon);
void InitializeBacSy(DoubleLinkedList &list); 
void InsertBacSy(DoubleLinkedList &list, BacSy data); //them bac sy
void PrintListBacSy(DoubleLinkedList list); //hien danh sach bac sy
BacSy InputBacSy();
void PrintBacSy(BacSy data);
void WriteFileBacSy(DoubleLinkedList list, string fileName); //ghi file
void ReadFileBacSy(DoubleLinkedList &list, string fileName); //doc file
NodeBacSy * SearchBacSyById(DoubleLinkedList list, int maBS);
void RemoveBacSyByName(DoubleLinkedList &list, char tenBS[]);

int main(){
	BSTree root;
	InitializeBenhNhan(root);
	DoubleLinkedList list;
	InitializeBacSy(list);
	
	int chon = 0, chon1 = 0, chon2 = 0;
	do{
		if(chon1 == 0 && chon2 == 0){
			cout << "1. Quan ly bac sy.\n";
			cout << "2. Quan ly benh nhan.\n";
			cout << "chon: "; cin >> chon;
		}		
		if(chon == 1){
			menuBacSy();
			cout << "chon: "; cin >> chon1;
			quanLyBacSy(list, chon1);
		}else if(chon == 2){
			menuBenhNhan();
			cout << "chon: "; cin >> chon2;
			quanLyBenhNhan(root, chon2);
		}else{
			cout << "coming soon!\n";
		}
	}while(chon1 != 7 || chon2 != 10);
	return 0;
}

void menuBenhNhan(){
	cout << "1. them benh nhan cho bac sy.\n";
	cout << "2. hien danh sach benh nhan cua bac sy\n";
	cout << "3. doc file benhnhan.txt\n";
	cout << "4. ghi file benhnhan.txt\n";
	cout << "5. tim kiem benh nhan theo id\n";
	cout << "6. xoa benh nhan\n";
}

void quanLyBenhNhan(BSTree &root, int &chon){
	switch(chon){
		case 0:
			cout << "menu chinh.\n";
			break;
		case 1:
			InsertBenhNhan(root, InputBenhNhan());
			break;
		case 2:
			PrintListBenhNhan(root);
			break;
		case 3:
			ReadFileBenhNhan(root, "benhnhan.txt");
			break;
		case 4:
			WriteFileBenhNhan(root, "benhnhan.txt");
			break;
		case 5:{
			int maBN;
			cout << "nhap ma benh nhan: "; cin >> maBN;
			NodeBenhNhan *pNode = SearchBenhNhanById(root, maBN);
			if(pNode == NULL){
				cout << "khong tim thay benh nhan co ma la " << maBN << " !\n";
			}else{
				cout << setw(10) << "ma BN" << setw(20) << "ten BN" << setw(10) << "tuoi BN" << setw(10) << "gioi tinh" << setw(20) << "dia chi"
					<< setw(20) << "trieu chung" << endl;
				cout << setw(10) << pNode->data.maBN << setw(20) << pNode->data.tenBN << setw(10) << pNode->data.tuoiBN << setw(10) << pNode->data.gioiTinh
					<< setw(20) << pNode->data.diaChi << setw(20) << pNode->data.trieuChung << endl;
			}
			break;
		}
			
		case 6:{
			cout << "coming soon!\n";
			break;
		}
			

	}
}

void InitializeBenhNhan(BSTree &root){
	root = NULL;
}

NodeBenhNhan * CreateNodeBenhNhan(BenhNhan data){
	NodeBenhNhan *pNode = new NodeBenhNhan;
	if(pNode == NULL){
		cout << "cap phat bo nho that bai\n";
	}else{
		pNode->data = data;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
	}
	return pNode;
}

void InsertBenhNhan(BSTree &root, BenhNhan data){
	NodeBenhNhan *pNode = CreateNodeBenhNhan(data);
	if(root == NULL){
		root = pNode;
	}else{
		BSTree tmp = root;
		BSTree parent = NULL;
		while(tmp != NULL){
			parent = tmp;
			if(pNode->data.maBN < tmp->data.maBN){
				tmp = tmp->pLeft;
			}else{
				tmp = tmp->pRight;
			}
		}
		if(pNode->data.maBN < parent->data.maBN){
			parent->pLeft = pNode;
		}else{
			parent->pRight = pNode;
		}
	}
}

int SizeOfListBenhNhan(BSTree root){
	if(root == NULL){
		return 0;
	}else{
		return (1 + SizeOfListBenhNhan(root->pLeft) + SizeOfListBenhNhan(root->pRight));
	}	
}

void InOrder_LNR(BSTree root){
	if(root != NULL){
		InOrder_LNR(root->pLeft);
		cout << setw(10) << root->data.maBN << setw(20) << root->data.tenBN << setw(10) << root->data.tuoiBN << setw(10) << root->data.gioiTinh
		<< setw(20) << root->data.diaChi << setw(20) << root->data.trieuChung << endl;
		InOrder_LNR(root->pRight);
	}
}

void PrintListBenhNhan(BSTree root){
	if(root == NULL){
		cout << "danh sach benh nhan rong!";
	}else{
		cout << setw(10) << "ma BN" << setw(20) << "ten BN" << setw(10) << "tuoi BN" << setw(10) << "gioi tinh" << setw(20) << "dia chi"
		<< setw(20) << "trieu chung" << endl;
		InOrder_LNR(root);
	}
}

NodeBenhNhan * SearchBenhNhanById(BSTree root, int maBN){
	if(root == NULL || root->data.maBN == maBN){
		return root;
	}else{
		if((maBN < root->data.maBN)){
			return SearchBenhNhanById(root->pLeft, maBN);
		}else{
			return SearchBenhNhanById(root->pRight, maBN);
		}
	}
}

BenhNhan InputBenhNhan(){
	BenhNhan benhNhan;
	cout << "nhap ma benh nhan: "; cin >> benhNhan.maBN; cin.ignore();
	cout << "nhap ten benh nhan: "; cin.getline(benhNhan.tenBN, 30);
	cout << "nhap tuoi benh nhan: "; cin >> benhNhan.tuoiBN; cin.ignore();
	cout << "nhap gioi tinh: "; cin.getline(benhNhan.gioiTinh, 30);
	int n = 1;
	while(true){
		if(strcmp(benhNhan.gioiTinh, "nam") == 0 || strcmp(benhNhan.gioiTinh, "nu") == 0){
			break;
		}else if(n == 3){
			cout << "ban da nhap sai qua 3 lan! Vui long thu lai.";
			break;
		}else{
			cout << "gioi tinh chi nhan 'nam' hoac 'nu'! Vui long nhap lai.\n";
			cout << "nhap gioi tinh: "; cin.getline(benhNhan.gioiTinh, 30);
			n++;
		}
	}
	cout << "nhap dia chi: "; cin.getline(benhNhan.diaChi, 30);
	cout << "nhap trieu chung: "; cin.getline(benhNhan.trieuChung, 250);
	return benhNhan;
}

void WriteFileBenhNhan(BSTree root, string fileName){
	ofstream file(fileName, ios::binary);
	if(file.is_open()){
		int n = SizeOfListBenhNhan(root);
		file.write((char*)&n, sizeof(int));
		
		stack<NodeBenhNhan *> s;
		NodeBenhNhan *pTmp = root;
		while(!s.empty() || pTmp != NULL){
			if(pTmp != NULL){
				s.push(pTmp);
				pTmp = pTmp->pLeft;
			}else{
				pTmp = s.top();
				s.pop();
				file.write((char*)&pTmp->data, sizeof(BenhNhan));
				
				pTmp = pTmp->pRight;
			}
		}
		cout << "ghi file thanh cong.\n";
	}else{
		cout << "khong the mo file de ghi!\n";
	}
}

void ReadFileBenhNhan(BSTree &root, string fileName){
	ifstream file(fileName, ios::binary);
	if(file.is_open()){
		int n;
		file.read((char*)&n, sizeof(int));
		
		for(int i=0; i<n; ++i){
			BenhNhan benhNhan;
			file.read((char*)&benhNhan, sizeof(BenhNhan));
			InsertBenhNhan(root, benhNhan);
		}
		cout << "doc file thanh cong.\n";
	}else{
		cout << "khong the mo file de doc.\n";
	}
}

void RemoveBenhNhanByMaBN(BSTree &root, int maBN){
	
}
//code bac sy
void menuBacSy(){
	cout << "1. them bac sy.\n";	
	cout << "2. hien danh sach bac sy\n";
	cout << "3. doc file bacsy.txt\n";
	cout << "4. ghi file bacsy.txt\n";	
	cout << "5. tim kiem bac sy.\n";
	cout << "6. xoa bac sy\n";
}

void quanLyBacSy(DoubleLinkedList &list, int &chon){
	switch(chon){
		case 0:
			cout << "menu chinh!\n";
			break;
		case 1:
			InsertBacSy(list, InputBacSy());
			break;
		case 2:
			PrintListBacSy(list);
			break;
		case 3:
			ReadFileBacSy(list, "bacsy.txt");
			break;
		case 4:
			WriteFileBacSy(list, "bacsy.txt");
			break;
		case 5:{
			int maBacSy;
			cout << "nhap ma bac sy: "; cin >> maBacSy;
			NodeBacSy *pNode = SearchBacSyById(list, maBacSy);
			if(pNode == NULL){
				cout << "khong tim thay bac sy co ma " << maBacSy << " !\n";
			}else{
				cout << setw(10) << "ma BS" << setw(20) << "ten bac sy" << setw(30) << "chuyen khoa" << setw(20) << "so dien thoai" << setw(20) << "email" << endl;
				PrintBacSy(pNode->data);
			}
			break;
		}
		case 6:{
			cin.ignore();
			char tenBS[30];
			cout << "nhập tên bác sỹ cần xóa: "; cin.getline(tenBS, 30);
			RemoveBacSyByName(list, tenBS);
			break;
		}
			
	}
}

void InitializeBacSy(DoubleLinkedList &list){
	list.pHead = list.pTail = NULL;
}

NodeBacSy * CreateNodeBacSy(BacSy data){
	NodeBacSy *pNode = new NodeBacSy;
	if(pNode == NULL){
		cout << "cap phat bo nho that bai\n.";
	}else{
		pNode->data = data;
		pNode->pNext = NULL;
		pNode->pPrevious = NULL;
		pNode->root = NULL;
	}
	return pNode;
}

void InsertBacSy(DoubleLinkedList &list, BacSy data){ 
	NodeBacSy *pNode = CreateNodeBacSy(data);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		list.pTail->pNext = pNode;
		pNode->pPrevious = list.pTail;
		list.pTail = pNode;
	}
}

int SizeOfListBacSy(DoubleLinkedList list){
	int count = 0;
	NodeBacSy *pTmp = list.pHead;
	while(pTmp != NULL){
		count ++;
		pTmp = pTmp->pNext;
	}
	return count;
}

void PrintBacSy(BacSy data){
	cout << setw(10) << data.maBS << setw(20) << data.tenBS << setw(30) << data.chuyenKhoa << setw(20) << data.soDienThoai << setw(20) << data.email << endl;
}

void PrintListBacSy(DoubleLinkedList list){
	if(list.pHead == NULL){
		cout << "danh sach bac sy rong!\n";
	}else{
		NodeBacSy *pTmp = list.pHead;
		cout << setw(10) << "ma BS" << setw(20) << "ten bac sy" << setw(30) << "chuyen khoa" << setw(20) << "so dien thoai" << setw(20) << "email" << endl;
		while(pTmp != NULL){			
			PrintBacSy(pTmp->data);
			pTmp = pTmp->pNext;
		}
	}
}

NodeBacSy * SearchBacSyById(DoubleLinkedList list, int maBS){
	NodeBacSy *pTmp = list.pHead;
	if(list.pHead == NULL){
		return NULL;
	}else{
		while(pTmp != NULL){
			if(pTmp->data.maBS == maBS){
				break;
			}
			pTmp = pTmp->pNext;
		}
	}
	return pTmp;
}

BacSy InputBacSy(){
	BacSy bacSy;
	cout << "nhap ma bac sy: "; cin >> bacSy.maBS; cin.ignore();
	cout << "nhap ten bac sy: "; cin.getline(bacSy.tenBS, 30);
	cout << "nhap chuyen khoa bac sy: "; cin.getline(bacSy.chuyenKhoa, 250);
	cout << "nhap so dien thoai bac sy: "; cin.getline(bacSy.soDienThoai, 30);
	cout << "nhap email bac sy: "; cin.getline(bacSy.email, 30);
	return bacSy;
}

void WriteFileBacSy(DoubleLinkedList list, string fileName){
	ofstream file(fileName, ios::binary);
	if(file.is_open()){
		int n = SizeOfListBacSy(list);
		file.write((char*)&n, sizeof(int));

		NodeBacSy *pTmp = list.pHead;
		while(pTmp != NULL){
			file.write((char*)&pTmp->data, sizeof(BacSy));
			pTmp = pTmp->pNext;
		}
		cout << "ghi file thanh cong.\n";
	}else{
		cout << "khong the mo file bacsy.txt de ghi.\n";
	}	
}
 
void ReadFileBacSy(DoubleLinkedList &list, string fileName){
	ifstream file(fileName, ios::binary);
	if(file.is_open()){
		int n;
		file.read((char*)&n, sizeof(int));
		
		for(int i=0; i<n; ++i){
			BacSy bacSy;
			file.read((char*)&bacSy, sizeof(bacSy));
			InsertBacSy(list, bacSy);
		}
		cout << "doc file thanh cong.\n";
	}else{
		cout << "khong the mo file bacsy.txt de doc.\n";
	}
}

void RemoveBacSyByName(DoubleLinkedList &list, char tenBS[]){
	NodeBacSy *pDel = list.pHead;
	if(pDel == NULL){
		cout << "danh sach rong! khong the xoa.\n";
		return;
	}
	NodeBacSy *pPre = NULL;
	while(pDel != NULL){
		if(strcmp(pDel->data.tenBS, tenBS) == 0) break;
		pPre = pDel;
		pDel = pDel->pNext;
	}
	if(pDel == NULL){
		cout << "khong ton tai ten bac sy muon xoa!\n";
	}else{
		if(pDel == list.pHead){
			list.pHead = list.pHead->pNext;
			pDel->pNext = NULL;
			list.pHead->pPrevious = NULL;
		}else if(pDel->pNext == NULL){
			list.pTail = pPre;
			pPre->pNext = NULL;
			pDel->pPrevious = NULL;
		}else{
			pPre->pNext = pDel->pNext;
			pDel->pNext->pPrevious = pPre;
			pDel->pNext = NULL;
			pDel->pPrevious = NULL;
		}
		cout << "xoa thanh cong!\n";
	}
	delete pDel;
	pDel = NULL;
}


