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

struct TNode{
	Product value;
	TNode *pLeft;
	TNode *pRight;
};

typedef TNode *BTree;

TNode *CreateNode(Product value){
	TNode *pNode = new TNode;
	pNode->value = value;
	pNode->pLeft = pNode->pRight = NULL;
	return pNode;
}

void InsertNode(BTree &root, Product value){
	TNode *pNode = CreateNode(value);
	if(root == NULL){
		root = pNode;
	}else{
		BTree tmp = root;
		BTree parent = NULL;
		while(tmp != NULL){
			parent = tmp;
			if(pNode->value.id < tmp->value.id){
				tmp = tmp->pLeft;
			}else{
				tmp = tmp->pRight;
			}
		}
		if(pNode->value.id < parent->value.id){
			parent->pLeft = pNode;
		}else{
			parent->pRight = pNode;
		}
	}
}

void PostOrder_LRN(BTree root){
	if(root != NULL){
		PostOrder_LRN(root->pLeft);
		PostOrder_LRN(root->pRight);
		cout << root->value.id << "  " << root->value.name << "  " << root->value.price << endl;
	}
}

TNode *SearchNode(BTree root, int id){
	if(root == NULL || root->value.id == id){
		return root;
	}else {
		if(root->value.id < id){
			return SearchNode(root->pLeft, id);
		}
		else{
			return SearchNode(root->pRight, id);
		}
	}
}

int main(){
	int n; cin >> n;
	BTree root = NULL;
	for(int i=0; i<n; ++i){
		int id; cin >> id;
		cin.ignore();
		string name; getline(cin, name);
		float price; cin >> price;
		Product product;
		product.id = id;
		product.name = name;
		product.price = price;
		InsertNode(root, product);
	}
	PostOrder_LRN(root);
	int id;
	cin >> id;
	TNode *pNode = SearchNode(root, id);
	if(pNode != NULL){
		cout << "tim thay";
	}else{
		cout << "k tim thay";
	}
	return 0;
}