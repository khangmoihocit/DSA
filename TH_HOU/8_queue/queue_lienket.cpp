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
	Node *pFront;
	Node *pRear;
};

void Initialize(QUEUE &queue){
	queue.pFront = NULL;
	queue.pRear = NULL;
}

Node * CreateNode(int d){
	Node *pNode = new Node;
	if(pNode == NULL){
		cout << "cấp phát bộ nhớ thất bại";
		exit(0);
	}
	pNode->data = d;
	pNode->pLink = NULL;
	return pNode;
}

void enqueue(QUEUE &queue, int d){
	Node *pNode = CreateNode(d);
	if(queue.pRear == NULL){
		queue.pRear = queue.pFront = pNode;
	}else{
		queue.pRear->pLink = pNode;
		queue.pRear = pNode;
	}
}

int dequeue(QUEUE &queue){
	if(queue.pFront == NULL){
		cout << "queue is empty";
	}
	int d = queue.pFront->data;
	Node *pDel = queue.pFront;
	queue.pFront = queue.pFront->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return d;
}

int main(){
	QUEUE queue;
	Initialize(queue);

	enqueue(queue, 10);
	enqueue(queue, 40);
	enqueue(queue, 30);

	cout << dequeue(queue) << " ";
	cout << dequeue(queue) << " ";
	cout << dequeue(queue) << " ";


	return 0;
}