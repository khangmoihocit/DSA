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

struct QUEUE{
	Node *pFront; //dung dau
	Node *pRear; //dung cuoi
};

void Initialize(QUEUE &queue){
	queue.pFront = NULL;
	queue.pRear = NULL;
}

Node * CreateNode(int d){
	Node *pNode = new Node;
	pNode->data = d;
	pNode->pLink = NULL;
	return pNode;
}

void Enqueue(QUEUE &queue, int d){
	Node *pNode = CreateNode(d);
	if(queue.pFront == NULL){
		queue.pFront = queue.pRear = pNode;
	}else{
		queue.pRear->pLink = pNode;
		queue.pRear = pNode;
	}
}

int Dequeue(QUEUE &queue){
	int d = queue.pFront->data;
	Node *pDel = queue.pFront;
	queue.pFront = queue.pFront->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return d;
}

const int n = 7;
int main(){
	int a[n][n] = { { 0, 1, 0, 0, 0, 0, 0},
					{ 1, 0, 1, 1, 1, 0, 0},
					{ 0, 1, 0, 0, 0, 1, 0},
					{ 0, 1, 0, 0, 0, 1, 1},
					{ 0, 1, 0, 0, 0, 0, 1},
					{ 0, 0, 1, 1, 0, 0, 0},
					{ 0, 0, 0, 1, 1, 0, 0}
	            };
	QUEUE queue;
	Initialize(queue);
	set<int> se; //danh dau cac phan tu da duyet
	Enqueue(queue, 0);
	se.insert(0);

	while(queue.pFront != NULL){
		int u = Dequeue(queue);
		cout << u << " ";
		for(int v = 0; v < n; ++v){
			if(a[u][v] == 1 && se.find(v) == se.end()){ //các đỉnh v liền kề với u và chưa đc duyệt
				Enqueue(queue, v);
				se.insert(v);
			}
		}
	}
	return 0;
}