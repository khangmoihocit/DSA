#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;
typedef FILE_STACK = "data.bin" 
struct Class{
	string name;
	int numberOfStudents;
};

struct Node{
	Class data;
	Node *pLink;
};

typedef Node * STACK;
void Initialize(STACK &stack){
	stack = NULL;
}

Node * CreateNode(Class d){
	Node *pNode = new Node;
	if(pNode == NULL){
		cout << "Cấp phát bộ nhớ thất bại.";
	}else{
		pNode->data = d;
		pNode->pLink = NULL;
	}
	return pNode;
}

void Push(STACK &stack, Class d){
	Node *pNode = CreateNode(d);
	if(stack == NULL){
		stack = pNode;
	}else{
		pNode->pLink = stack;
		stack = pNode;
	}
}

Class Pop(STACK &stack){
	Class d = stack->data;
	Node *pDel = stack;
	stack = stack->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return d;
}

//nếu tên lớp đã có thì sẽ không thêm mới và chỉ cộng thêm số lượng sinh viên trong lớp
void them(STACK &stack, Class d){
	Node *pTmp = stack;
	bool isCheck = false;
	while(pTmp != NULL){
		if(pTmp->data.name == d.name){
			pTmp->data.numberOfStudents += d.numberOfStudents;
			isCheck = true;
			break;
		}
		pTmp= pTmp->pLink;
	}
	if(!isCheck){
		Push(stack, d);
	}
}


void PrintStack(STACK stack){
	while(stack != NULL){
		Class device = Pop(stack);
		cout << device.name << " " << device.numberOfStudents << endl;
	}
}

void FileOutput(){

}

int main(){
	// fstream fileOutput("data.bin", ios::out | ios::binary);
	// if(fileOutput.is_open()){
	// 	string n = "pham van khang";
	// 	fileOutput.write((char*)&n, sizeof(n));
	// 	fileOutput.close();
	// 	cout << "ghi file thanh cong\n";
	// }else{
	// 	cout << "loi khong ghi dc file";
	// }

	fstream fileInput(FILE_STACK, ios::in | ios::binary);
	if(fileInput.is_open()){
		string number;
		fileInput.read((char*)&number, sizeof(number));
		fileInput.close();
		cout << number;
	}else{
		cout << "loi khong doc dc file";
	}
	// STACK stack;
	// Initialize(stack);
	// int n; cin >> n;
	// for(int i=0; i<n; ++i){
	// 	cin.ignore();
	// 	string name; getline(cin, name);
	// 	int numberOfStudents; cin >> numberOfStudents;
	// 	Class cla;
	// 	cla.name = name;
	// 	cla.numberOfStudents = numberOfStudents;
	// 	them(stack, cla);
	// }

	// PrintStack(stack);

	return 0;
}