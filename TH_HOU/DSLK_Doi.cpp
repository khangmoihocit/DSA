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

void AddFirst(DoubleLinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pNext = list.pHead;
		list.pHead->pPrevious = pNode;
		list.pHead = pNode;
	}
}

void AddLast(DoubleLinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pPrevious = list.pTail;
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

void OutputLeftToRight(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	while(pTmp != NULL){
		cout << pTmp->data << " ";
		pTmp = pTmp->pNext;
	}
}

int main(){
	DoubleLinkedList list;
	init(list);
	AddFirst(list, 10);
	AddFirst(list, 30);
	AddFirst(list, 20);
	AddFirst(list, 40);
	AddLast(list, 50);
	OutputLeftToRight(list);

	return 0;
}