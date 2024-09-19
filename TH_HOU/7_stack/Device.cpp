#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

struct Device{
	int id;
	string name;
};

struct Node{
	Device data;
	Node *pLink;
};

typedef Node * STACK;

void Initialize(STACK &stack){
	stack = NULL;
}

Node * CreateNode(Device d){
	Node *pNode = new Node;
	pNode->data = d;
	pNode->pLink = NULL;
	return pNode;
}

void Push(STACK &stack, Device d){
	Node *pNode = CreateNode(d);
	if(stack == NULL){
		stack = pNode;
	}else{
		pNode->pLink = stack;
		stack = pNode;
	}
}

Device Pop(STACK &stack){
	Device device = stack->data;
	if(stack == NULL){
		Device emptyDevice;
		emptyDevice.id = -1;
		emptyDevice.name = "";
		return emptyDevice;
	}
	Node *pDel = stack;
	stack = stack->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return device;
}

int main(){
	STACK stack;
	Initialize(stack);
	int n; cin >> n;
	for(int i=0; i<n; ++i){
		Device device;
		int id; cin >> id;
		cin.ignore();
		string name; getline(cin, name);
		device.id = id;
		device.name = name;
		Push(stack, device);
	}

	while(stack != NULL){
		Device device = Pop(stack);
		cout << device.id << " " << device.name << endl;
	}
	return 0;
}