#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

//Cây nhị phân tìm kiếm:

//duyệt theo thứ tự trước(Preorder): NLR
//duyệt theo thứ tự giữa(Inorder): LNR
//duyệt theo thứ tự sau(Posorder): LRN
/*
	  (node)
		/\
	   /  \
    pLeft  pRight
*/
struct TNode{
	int value;
	TNode *pLeft;
	TNode *pRight;
};
typedef TNode * BTree; //gốc cây

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
	TNode *node = CreateNode(value);
	if(root == NULL){
		root = node;
	}else{
		BTree tmp = root;
		BTree parent = NULL;
		while(tmp != NULL){
			parent = tmp; //tìm ra vị trí cha để nối node vô;
			if(node->value < tmp->value){
				tmp = tmp->pLeft;
			}else{
				tmp = tmp->pRight;
			}
		}
		if(node->value < parent->value){
			parent->pLeft = node;
		}else{
			parent->pRight = node;
		}
	}
}

void PreOrder_NLR(BTree root){
	if(root != NULL){
		cout << root->value << " ";
		PreOrder_NLR(root->pLeft);
		PreOrder_NLR(root->pRight);
	}
}

void PosOrder_LRN(BTree root){
	if(root != NULL){
		PosOrder_LRN(root->pLeft);
		PosOrder_LRN(root->pRight);
		cout << root->value << " ";
	}
}

void InOrder_LNR(BTree root){
	if(root != NULL){
		InOrder_LNR(root->pLeft);
		cout << root->value << " ";
		InOrder_LNR(root->pRight);
	}
}

//đếm node trên cây
int CountNode(BTree root){
	if(root == NULL){
		return 0;
	}else{
		return (1 + CountNode(root->pLeft) + CountNode(root->pRight));
	}
}

//đếm node lá trên cây
int CountLeaf(BTree root){
	if(root != NULL){
		if(root->pLeft == NULL && root->pRight == NULL){
			return 1;
		}else{
			return CountLeaf(root->pLeft) + CountLeaf(root->pRight);
		}
	}else{
		return 0;
	}
}

int max(int a, int b){
	return a>b?a:b;
}

//chiều cao của cây: là node gốc(1) + chiều cao lớn nhất của nhánh bên trái(phải)
int Height(BTree root){
	if(root == NULL){
		return 0;
	}else{
		return 1 + max(Height(root->pLeft), Height(root->pRight));
	}
}

//tìm kiếm node trên cây
TNode *Search(BTree root, int value){
	if(root == NULL || root->value == value){ //tìm thấy thì sẽ trả về node đó
		return root;
	}else{
		if(value < root->value){ //giá trị nhỏ hơn -> tìm bên cây con trái
			return Search(root->pLeft, value);
		}else{ //tìm bên cây con phải
			return Search(root->pRight, value);
		}
	}
}

//xóa node: có 3 TH
void RemoveNode(BTree &root, int value){
	if(root == NULL){
		cout << "cây rỗng\n";
			return;
	}
	TNode *pParent = NULL;
	TNode *pDel = NULL;
	TNode *pTmp = root;
	while(pTmp != NULL){ //tìm node cha của node cần xóa, và node cần xóa
		pParent = pTmp;
		if(value < pTmp->value){
			pTmp = pTmp->pLeft;
		}else if(value > pTmp->value){
			pTmp = pTmp->pRight;
		}
		if(pTmp->value == value){
			pDel = pTmp; //tìm thấy node cần xóa
			break;
		}
	}
	if(pDel == NULL){
		cout << "khong tim thay node de xoa\n";
		return;
	}
	if(pDel->pLeft == NULL && pDel->pRight == NULL){ //TH1: node cần xóa là node lá
		if(pDel->value < pParent->value){
			pParent->pLeft = NULL;
		}else{
			pParent->pRight = NULL;
		}
		delete pDel;
		pDel = NULL;
	//TH2: node cần xóa có 1 node con	
	}else if(pDel->pLeft != NULL && pDel->pRight == NULL){ //node xóa có node con bên trái
		if(pDel->value < pParent->value){
			pParent->pLeft = pDel->pLeft;
		}else{
			pParent->pRight = pDel->pLeft;
		}
		pDel->pLeft = NULL;
		delete pDel;
		pDel = NULL;
	}else if(pDel->pLeft == NULL && pDel->pRight != NULL){ //node xóa có node con bên phải
		if(pDel->value < pParent->value){
			pParent->pLeft = pDel->pRight;
		}else{
			pParent->pRight = pDel->pRight;
		}
		pDel->pRight = NULL;
		delete pDel;
		pDel = NULL;
	}else{ //TH3: node cần xóa có 2 nút con
		/*ta không thể hủy trực tiếp x do x có đủ 2 con -> ta sẽ hủy dán tiếp. Thay vì hủy x
		ta sẽ tìm phần tử thế mạng y. Phần tử này có tối đa 1 con. Thông tin lưu tại y sẽ được
		chuyển lên lưu tại x. Sau đó, nút bị hủy thật sự là y giống như 2 TH đầu. */
		/*
		phần tử thế mạng thỏa mãn:
			-Phần tử nhỏ nhất (trái nhất) trên cây con phải.
			-Phần tử lớn nhất (phải nhất) trên cây con trái.
		*/
		TNode *pMinOfRight = pDel->pRight;
		TNode *pParentMinOfRight = NULL;
		while(pMinOfRight->pLeft != NULL){
			pParentMinOfRight = pMinOfRight;
			pMinOfRight = pMinOfRight->pLeft;
		}
		pDel->value = pMinOfRight->value;
		if(pParentMinOfRight == NULL){
			pDel->pRight = NULL;
		}else if(pMinOfRight->value < pParentMinOfRight->value){
			pParentMinOfRight->pLeft = pMinOfRight->pRight;
		}
		delete pMinOfRight;
		pMinOfRight = NULL;
	}
}

int main(){
	BTree root = NULL;
	// Initialize(root);
	InsertNode(root, 10);
	InsertNode(root, 20);
	InsertNode(root, 5);
	InsertNode(root, 8);
	InsertNode(root, 15);
	InsertNode(root, 30);
	InsertNode(root, 6);

	PreOrder_NLR(root);
	cout << endl;
	InOrder_LNR(root);
	cout << endl;
	PosOrder_LRN(root);
	cout << endl << CountNode(root);
	cout << endl << CountLeaf(root);
	cout << endl << Height(root);
	BTree node = Search(root, 9);
	if(node != NULL){
		cout << endl << "found\n";
	}else{
		cout << "\nnot found\n";
	}

	RemoveNode(root, 20);
	PreOrder_NLR(root);

	return 0;
}