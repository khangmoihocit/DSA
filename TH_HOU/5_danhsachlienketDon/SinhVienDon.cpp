#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;


struct SinhVien{
	string hoTen;
	int namSinh;
	float diem;
};

struct Node{
	SinhVien data;
	Node *pNext;
};

struct SVList{
	Node *pHead;
};

void CreateList(SVList &list){
	list.pHead = NULL;
}
Node* CreateNode(SinhVien sv){
	Node *newNode = new Node;
	if(newNode != NULL){
		newNode->data = sv;
		newNode->pNext = NULL;
	}else{
		cout << "cấp phát bộ nhớ thất bại";
	}
	return newNode;
}

void Them(SVList &list, Node *q){
	if(list.pHead == NULL){
		list.pHead = q;
	}else{
		q->pNext = list.pHead;
		list.pHead = q;
	}
}

void HienDanhSach(SVList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		cout << pTmp->data.hoTen << " - " << pTmp->data.namSinh << " - "
		<< pTmp->data.diem << endl;
		pTmp = pTmp->pNext;
	}
}

//sinh viên điểm trên 8
void SinhVienGioi(SVList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		if(pTmp->data.diem >= 8){
			cout << pTmp->data.hoTen << " - " << pTmp->data.namSinh << " - "
		<< pTmp->data.diem << endl;
		}
		pTmp = pTmp->pNext;
	}
}

double DiemTrungBinh(SVList list){
	Node *pTmp = list.pHead;
	double res = 0;
	int n = 0;
	while(pTmp != NULL){
		res += pTmp->data.diem;
		n++;
		pTmp = pTmp->pNext;
	}
	return res/n;
}

void XoaSVTrungBinh(SVList &list){
	Node *pDel = list.pHead;
	Node *pPre = NULL;
	while(pDel != NULL){
		if(pDel->data.diem > 5){
			if(pDel == list.pHead){
				list.pHead = list.pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = list.pHead;
			}else{
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = pPre->pNext;
			}
		}else{
			pPre = pDel;
			pDel = pDel->pNext;
		}	
	}
}

// 3
// nguyen van a
// 2005
// 8
// pham van b
// 2004
// 5.6
// ngiyen rhi a
// 324
// 1.333
int main(){
	int n; cin >> n;
	SVList list;
	CreateList(list);
	for(int i=0; i<n; ++i){
		cin.ignore();
		string hoTen; getline(cin, hoTen);
		int namSinh; cin >> namSinh;
		float diem; cin >> diem;
		SinhVien sv;
		sv.hoTen = hoTen;
		sv.namSinh = namSinh;
		sv.diem = diem;
		Them(list, CreateNode(sv));
	}
	HienDanhSach(list);
	// SinhVienGioi(list);
	// cout << DiemTrungBinh(list);
	cout << endl << "danh sach sau khi xoa\n";
	XoaSVTrungBinh(list);
	HienDanhSach(list);
	return 0;
}