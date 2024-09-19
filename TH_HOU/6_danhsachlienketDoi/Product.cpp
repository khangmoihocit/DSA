#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct Product{
	int id;
	string name;
	float price;
};

struct Node{
	Product data;
	Node *pNext;
	Node *pPrevious;
};

struct DoubleLinkedList{
	Node *pHead;
	Node *pTail;
};

void Initialize(DoubleLinkedList &list){
	list.pHead = list.pTail = NULL;
}

Node * CreateNode(Product product){
	Node *pNode = new Node;
	pNode->data = product;
	pNode->pNext = pNode->pPrevious = NULL;
	return pNode;
}

void InsertFirst(DoubleLinkedList &list, Product product){
	Node *pNode = CreateNode(product);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pNext = list.pHead;
		list.pHead->pPrevious = pNode;
		list.pHead = pNode;
	}
}

void InsertLast(DoubleLinkedList &list, Product product){
	Node *pNode = CreateNode(product);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		list.pTail->pNext = pNode;
		pNode->pPrevious = list.pTail;
		list.pTail = pNode;
	}
}

void PrintList(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		cout << pTmp->data.id << "\t" << pTmp->data.name << "\t" << pTmp->data.price << endl;
		pTmp = pTmp->pNext;
	}
}

int SizeOfList(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	int count = 0;
	while(pTmp != NULL){
		count ++;
		pTmp = pTmp->pNext;
	}
	return count;
}

DoubleLinkedList ListFilter(DoubleLinkedList listGoc, float a, float b){
	DoubleLinkedList list;
	Initialize(list);
	Node *pTmp = listGoc.pHead;
	while(pTmp != NULL){
		if(pTmp->data.price >= a && pTmp->data.price <= b){
			InsertLast(list, pTmp->data);
		}
		pTmp = pTmp->pNext;
	}
	return list;
}

void SortListByPrice(DoubleLinkedList &list){
	for(Node *p1 = list.pHead; p1!=NULL; p1 = p1->pNext){
		for(Node *p2 = p1->pNext; p2!=NULL; p2 = p2->pNext){
			if(p1->data.price > p2->data.price){
				swap(p1->data, p2->data);
			}
		}
	}
}

void RemoveProductById(DoubleLinkedList &list, int id){
	Node *pDel = list.pHead;
	if(pDel == NULL){
		cout << "danh sach roong khoong xoa dc";
		return;
	}
	Node *pPre = NULL;
	while(pDel != NULL){
		if(pDel->data.id == id) break;
		pPre = pDel;
		pDel = pDel->pNext;
	}
	if(pDel == NULL){
		cout << "danh sach khong co id nay, khong the xoa!";
	}else{
		if(pDel == list.pHead){
			list.pHead = list.pHead->pNext;
			list.pHead->pPrevious = NULL;
			pDel->pNext = NULL;
		}else if(pDel->pNext == NULL){
			list.pTail = pPre;
			list.pTail->pNext = NULL;
			pDel->pPrevious = NULL;
		}else{
			pPre->pNext = pDel->pNext;
			pDel->pNext->pPrevious = pPre;
			pDel->pNext = NULL;
			pDel->pNext = NULL;
		}
		delete pDel;
		pDel = NULL;
	}
}

int main(){
	DoubleLinkedList list;
	Initialize(list);
	int n; cin >> n;
	for(int i=0; i<n; ++i){
		int id; cin >> id;
		cin.ignore();	
		string name; getline(cin, name);
		float price; cin >> price;
		Product product;
		product.id = id;
		product.name = name;
		product.price = price;
		InsertLast(list, product);
	}
	PrintList(list);

	DoubleLinkedList listFilter = ListFilter(list, 5000, 6000);
	cout << "danh sách sản phẩm: \n";
	PrintList(listFilter);

	SortListByPrice(list);
	cout << "Danh sách sau khi sắp xếp là: \n";
	PrintList(list);

	cout << "xoas :\n";
	RemoveProductById(list, 1001);
	RemoveProductById(list, 1003);
	PrintList(list);
	return 0;
}