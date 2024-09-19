#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct Node{
	int data;
	Node *pLink;
};
typedef Node* STACK;

void Initialize(STACK &stack){
	stack = NULL;
}

Node *CreateNode(int d){
	Node *pNode = new Node;
	pNode->data = d;
	pNode->pLink = NULL;
	return pNode;
}

void Push(STACK &stack, int d){
	Node *pNode = CreateNode(d);
	if(pNode == NULL){
		stack = pNode;
	}else{
		pNode->pLink = stack;
		stack = pNode;
	}
}

// int Pop(STACK &stack){
// 	int d = stack->data;
// 	Node *pDel = stack;
// 	stack = stack->pLink;
// 	pDel->pLink = NULL;
// 	delete pDel;
// 	pDel = NULL;
// 	return d;
// }

Node * Pop(STACK &stack){
	if(stack == NULL){
		return NULL;
	}
	Node *pDel = stack;
	stack = stack->pLink;
	pDel->pLink = NULL;
	return pDel;
}

Node * Top(STACK stack){
	return stack;
}
int main(){
	STACK stack;
	Initialize(stack);
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	// cout << Pop(stack);
	Node *n = Pop(stack);
	cout << n->data;

	Node *m = Pop(stack);
	cout << m->data;

	return 0;
}