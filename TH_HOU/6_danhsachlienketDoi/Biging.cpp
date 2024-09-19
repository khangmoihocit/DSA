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

void Initialize(DoubleLinkedList &list){
	list.pHead = list.pTail = NULL;
}

Node * CreateNode(int data){
	Node *pNode = new Node;
	if(pNode == NULL){
		cout << "cấp phát bộ nhớ thất bại!";
	}else{
		pNode->data = data;
		pNode->pNext = NULL;
		pNode->pPrevious = NULL;
	}
	return pNode;
}

void InsertLast(DoubleLinkedList &list, int d){
	Node *pNode = CreateNode(d);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		list.pTail->pNext = pNode;
		pNode->pPrevious = list.pTail;
		list.pTail = pNode;
	}
}

void InsertFirst(DoubleLinkedList &list, int d){
	Node *pNode = CreateNode(d);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}else{
		pNode->pNext = list.pHead;
		list.pHead->pPrevious = pNode;
		list.pHead = pNode;
	}
}

void PrintList(DoubleLinkedList list){
	Node *pTmp = list.pHead;
	if(pTmp == NULL){
		cout << "The list is empty!";
	}
	while(pTmp != NULL){
		cout << pTmp->data << " ";
		pTmp = pTmp->pNext;
	}
}

DoubleLinkedList TaoBigInteger(string s){
	DoubleLinkedList list;
	Initialize(list);
	istringstream iss(s);
	char tmp;
	while(iss >> tmp){
		int d = tmp - '0'; //chuyển từ kí tự tmp sang số int
		InsertLast(list, d);
	}
	return list;
}

bool isPrime(int n){
	if(n<2) return false;
	for(int i=2; i<=sqrt(n); ++i){
		if(n%i == 0) return false;
	}
	return true;
}

DoubleLinkedList LayDayNguyenTo(DoubleLinkedList listGoc){
	DoubleLinkedList list;
	Initialize(list);
	Node *pTmp = listGoc.pHead;
	while(pTmp != 0){
		if(isPrime(pTmp->data)){
			InsertLast(list, pTmp->data);
		}
		pTmp = pTmp->pNext;
	}
	return list;
}

//cộng 2 số lớn
DoubleLinkedList Cong2So(DoubleLinkedList list1, DoubleLinkedList list2){
	DoubleLinkedList list3;
	Initialize(list3);
	Node *tail1 = list1.pTail;
	Node *tail2 = list2.pTail;
	int v2 = 0; //số dư
	while(tail1 != NULL || tail2 != NULL){
		int v1 = 0;
		if(tail1 != NULL && tail2 != NULL){
			v1 = tail1->data + tail2->data;
		}else if(tail1 != NULL){
			v1 = tail1->data;
		}else if(tail2 != NULL){
			v1 = tail2->data;
		}
		v1 = v1 + v2;
		if(v1 >= 10){
			v2 = v1/10;
			v1%=10;
		}else{
			v2 = 0;
		}
		InsertFirst(list3, v1);
		if(tail1 != NULL) tail1 = tail1->pPrevious;
		if(tail2 != NULL) tail2 = tail2->pPrevious;
	}
	if(v2 != 0){
		InsertFirst(list3, v2);
	}
	return list3;
}

int main(){
	DoubleLinkedList list;
	list = TaoBigInteger("12345323129352668163248774324873");
	
	// DoubleLinkedList listPrime = LayDayNguyenTo(list);

	// PrintList(list);
	// cout << "\nList Prime: \n";
	// PrintList(listPrime);

	DoubleLinkedList list1 = TaoBigInteger("123456");
	DoubleLinkedList list2 = TaoBigInteger("690");
	DoubleLinkedList list3 = Cong2So(list1, list2);

	PrintList(list3);



	return 0;
}