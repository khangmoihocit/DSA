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

int Pop(STACK &stack){
	int d = stack->data;
	Node *pDel = stack;
	stack = stack->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return d;
}

// Node * Pop(STACK &stack){
// 	if(stack == NULL){
// 		return NULL;
// 	}
// 	Node *pDel = stack;
// 	stack = stack->pLink;
// 	pDel->pLink = NULL;
// 	return pDel;
// }

Node * Top(STACK stack){
	return stack;
}

const int n = 7;

//duyet dfs bang de quy
void DFS(int u, int graph[n][n], multiset<int> &daDuyet){
	cout << u << " ";
	for(int v = 0; v < n; ++v){
		if(graph[u][v] == 1 && daDuyet.find(v)  == daDuyet.end()){
			daDuyet.insert(v);
			DFS(v, graph, daDuyet);
		}
	}
}

int main(){
	int a[n][n] = { { 0, 1, 0, 0, 0, 0, 0},
					{ 1, 0, 1, 1, 1, 0, 0},
					{ 0, 1, 0, 0, 0, 1, 0},
					{ 0, 1, 0, 0, 0, 1, 1},
					{ 0, 1, 0, 0, 0, 0, 1},
					{ 0, 0, 1, 1, 0, 0, 0},
					{ 0, 0, 0, 1, 1, 0, 0}
	            };
    //khai báo
    STACK stack;
	Initialize(stack);
    multiset<int> daDuyet;
    //khoi tao
    Push(stack, 0); //add đỉnh đầu vào stack
    daDuyet.insert(0);//đánh dấu đã duyệt đỉnh đầu

    // duyet theo stack
    while(stack != NULL){
        int u = Pop(stack);
        cout << u << " ";
        //add tất cả các đỉnh kề v với u mà chưa được duyệt vào stack
        for(int v = 0; v < 7; v++){ //tìm các đỉnh kề với u
        	if(a[u][v] == 1 && daDuyet.find(v) == daDuyet.end()){
        		Push(stack, v);
				//đánh dấu đã duyệt v
        		daDuyet.insert(v);
        	}
        }
    }
    cout << "DFS bang de quy";
    DFS(0, a, daDuyet);
	return 0;
}