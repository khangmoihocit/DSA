#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct SinhVien{
	string name;
	int age;
	float point;
};

struct Node{
	SinhVien data;
	Node *pPre;
	Node *pNext;
};

struct DoubleLinkedList{
	Node *pHead;
	Node *pTail;
};

void Initialize(DoubleLinkedList &list){
	list.pHead = NULL;
	list.pTail = NULL;
}

//p: pointer
Node * CreateNode(SinhVien sv){
	Node *pNode = new Node;
	pNode->data.name = sv.name;
	pNode->data.age = sv.age;
	pNode->data.point = sv.point;
	pNode->pPre = NULL;
	pNode->pNext = NULL;
	return pNode;
}

void AddLast(DoubleLinkedList &list, SinhVien sv){
	Node *pNode = CreateNode(sv);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pPre = list.pTail;
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

void PrintList(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		cout << pTmp->data.name << " - " << pTmp->data.age << " - " 
		<< pTmp->data.point << endl;
		pTmp = pTmp->pNext;
	}
}

void SinhVienGioi(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	bool found = false;
	while(pTmp != NULL){
		if(pTmp->data.point >= 8){
			found = true;
			cout << pTmp->data.name << " - " << pTmp->data.age << " - "
			<< pTmp->data.point << endl;
		}
		pTmp = pTmp->pNext;
	}
	if(found == false){
		cout << "không có sinh viên nào có điểm trên 8.";
	}
}

double PointAvg(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	int n = 0, s = 0;
	while(pTmp != NULL){
		s += pTmp->data.point;
		n++;
	}
	return double(s)/double(n);
}

void RemoveSinhVien(DoubleLinkedList &list){
	Node *pDel = list.pHead;
	Node *pPrevious = NULL;
	while(pDel != NULL){
		if(pDel->data.point < 5){
			if(pDel == list.pHead){
				list.pHead = list.pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = list.pHead;
			}else{
				pPrevious->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = pPrevious->pNext;
			}
		}else{
			pPrevious = pDel;
			pDel = pDel->pNext;
		}
	}
}

int main(){
	int n; cin >> n;
	DoubleLinkedList list;
	Initialize(list);
	for(int i=0; i<n; ++i){
		cin.ignore();
		string name; getline(cin, name);
		int age; cin >> age;
		float point; cin >> point;
		SinhVien sv;
		sv.name = name;
		sv.age = age;
		sv.point = point;
		AddLast(list, sv);
	}
	PrintList(list);
	// cout << "danh sách sinh viên sau khi xóa là : \n";
	// RemoveSinhVien(list);
	// PrintList(list);
	cout << "danh sach sinh vien gioi" << endl;
	SinhVienGioi(list);
	// cout << endl << "diem trung binh: " << PointAvg(list); 
	return 0;
}