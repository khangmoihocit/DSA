#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct Node{
	int data;
	Node *pNext;
};

struct LinkedList{
	Node *pHead;
	Node *pTail;
};

Node * CreateNode(int x){
	Node *pNode = new Node;
	if(pNode != NULL){
		pNode->data = x;
		pNode->pNext = NULL;
	}else{
		cout << "cấp phát bộ nhớ thất bại!";
	}
	return pNode;
}

void Initialize(LinkedList &list){
	list.pHead = list.pTail = NULL;
}

int SizeOfList(LinkedList list){
	Node *pTmp = list.pHead;
	int count = 0;
	while(pTmp != NULL){
		count++;
		pTmp = pTmp->pNext;
	}
	return count;
}

void InsertFirst(LinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void InsertLast(LinkedList &list, int x){
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}


int main(){
	LinkedList list;
	Initialize(list);

	return 0;
}