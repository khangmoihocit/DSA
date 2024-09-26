#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct TNode{
	int value;
	TNode *pLeft;
	TNode *pRight;
};

typedef TNode *BTree;

void Initialize(BTree &root){
	root = NULL;
}

TNode * CreateNode(int value){
	TNode *pNode = new TNode;
	pNode->value = value;
	pNode->pLeft = pNode->pRight = NULL;
	return pNode;
}

void InsertNode(BTree &root, int value){
	TNode *pNode = CreateNode(value);
	if(root == NULL){
		root = pNode;
	}else{
		BTree tmp = root;
		BTree parent = NULL;
		while(tmp != NULL){
			parent = tmp;
			if(pNode->value < tmp->value){
				tmp = tmp->pLeft;
			}else{
				tmp = tmp->pRight;
			}
		}
		if(pNode->value < parent->value){
			parent->pLeft = pNode;
		}else{
			parent->pRight = pNode;
		}
	}
}

void InOrder_LNR(BTree root){
	if(root != NULL){
		InOrder_LNR(root->pLeft);
		cout << root->value << " ";
		InOrder_LNR(root->pRight);
	}
}

int main(){
	int a[7];
	BTree tree;
	Initialize(tree);

	for(int i=0; i<7; ++i) cin >> a[i];

	for(int x : a){
		InsertNode(tree, x);
	}

	InOrder_LNR(tree);
	return 0;
}