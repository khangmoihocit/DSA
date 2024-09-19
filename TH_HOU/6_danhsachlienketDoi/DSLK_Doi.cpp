#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;


struct Node{
	int data;
	Node *pNext;
	Node *pPrevious;
};

struct DoubleLinkedList{
	Node *pHead;
	Node *pTail;
};

void init(DoubleLinkedList &list){
	list.pHead = NULL;
	list.pTail = NULL;
}

Node * CreateNode(int x){
	Node *pNode = new Node;
	pNode->data = x;
	pNode->pNext = NULL;
	pNode->pPrevious = NULL;
	return pNode;
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

void OutputLeftToRight(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		cout << pTmp->data << " ";
		pTmp = pTmp->pNext;
	}
}

void InsertFirst(DoubleLinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pNext = list.pHead;
		list.pHead->pPrevious = pNode;
		list.pHead = pNode;
	}
}

void InsertLast(DoubleLinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pPrevious = list.pTail;
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

void InsertMid(DoubleLinkedList &list, int pos, int x){
	Node *pNode = CreateNode(x);
	if(pos<0 || pos >= SizeOfList(list)){
		cout << "not valid position do insert!";
	}
	if(pos == 0){
		InsertFirst(list, x);
	}else if(pos == SizeOfList(list) - 1){
		InsertLast(list, x);
	}else{
		Node *pNode = CreateNode(x);
		Node *pIns = list.pHead;
		Node *pPre = NULL;
		int i = 0;
		while(pIns != NULL){
			if(i == pos) break;
			i++;
			pPre = pIns;
			pIns = pIns->pNext;
		}
		pNode->pNext = pIns;
		pPre->pNext = pNode;
		pIns->pPrevious = pNode;
		pNode->pPrevious = pPre;
	}
}

void RemoveNode(DoubleLinkedList &list, int x){
	Node *pDel = list.pHead;
	if(pDel == NULL){
		cout << "The list id empty!";
		return;
	}
	Node *pPre = NULL;
	while(pDel != NULL){
		if(pDel->data == x) break;
		pPre = pDel;
		pDel = pDel->pNext;
	}
	if(pDel == NULL){
		cout << "Could not found number!";
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
		delete pDel;
		pDel = NULL;
	}
}

int main(){
	DoubleLinkedList list;
	init(list);
	InsertFirst(list, 10);
	InsertFirst(list, 30);
	InsertFirst(list, 20);
	InsertFirst(list, 40);
	InsertLast(list, 50);

	InsertMid(list, 2, 100);
	RemoveNode(list, 9);
	cout << endl;
	OutputLeftToRight(list);

	return 0;
}