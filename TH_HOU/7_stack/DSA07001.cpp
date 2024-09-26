#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* pLink;
};

typedef Node* STACK;

void Initialize(STACK &stack) {
    stack = NULL;
}

Node* CreateNode(int d) {
    Node* pNode = new Node;
    pNode->data = d;
    pNode->pLink = NULL;
    return pNode;
}

void Push(STACK &stack, int d) {
    Node* pNode = CreateNode(d);
    if (stack == NULL) {
        stack = pNode;
    } else {
        pNode->pLink = stack;
        stack = pNode;
    }
}

void Pop(STACK &stack) {
    if (stack != NULL) {
        Node* pDel = stack;
        stack = stack->pLink;
        delete pDel;
    }
}

void Show(STACK stack) {
    if (stack == NULL) {
        cout << "empty" << endl;
    } else {
        while (stack != NULL) {
            cout << stack->data << " ";
            stack = stack->pLink;
        }
        cout << endl;
    }
}

int main() {
    STACK stack;
    Initialize(stack);
    string s;

    // Đọc đầu vào cho đến khi hết
    while (getline(cin, s)) {
        if (s.substr(0, 4) == "push") {
            // Tách phần số từ chuỗi lệnh
            stringstream ss(s);
            string command;
            int n;
            ss >> command >> n;
            Push(stack, n);
        } else if (s == "pop") {
            Pop(stack);
        } else if (s == "show") {
            Show(stack);
        }
    }

    return 0;
}
