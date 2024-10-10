#include <bits/stdc++.h>
using namespace std;
#define MAX 20

struct Node{
    char value[MAX];
    Node *pLink;
};

typedef Node * STACK;

void initialize(STACK &stack){
    stack = NULL;
}

Node * createNode(const char value[]){
    Node *pNode = new Node;
    strncpy(pNode->value, value, MAX-1); // copy value sang pNode->value, tối đa max-1 ki tu
    pNode->value[MAX-1] = '\0'; //chuoi phai ket thuc bang NULL
    pNode->pLink = NULL;
    return pNode;
}

void push(STACK &stack, char value[]){
    Node *pNode = createNode(value);
    if(stack == NULL){
        stack = pNode;
    }else{
        pNode->pLink = stack;
        stack = pNode;
    }
}

char * pop(STACK &stack){
    char *value = new char[MAX];
    strncpy(value, stack->value, MAX); //value = stack->value
    Node *pDel = stack;
    stack = stack->pLink;
    pDel->pLink = NULL;
    delete pDel;
    pDel = NULL;
    return value;
}
//hàm strtok(): trả về con trỏ đến token đầu tiên theo kí tự phân tách
/*Khi strtok nhận NULL làm tham số đầu tiên, nó không bắt đầu từ đầu chuỗi mới.
Thay vào đó, nó tiếp tục từ vị trí sau token cuối cùng đã tìm thấy trong lần gọi trước.*/
bool checkOperator(char op[]){
    return strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0;
}

void cal(char s[]){
    STACK stack;
    initialize(stack);
    char *p = strtok(s, " "); // cắt xâu s theo dấu cách
    int result = 0;

    while(p != NULL){
        if(checkOperator(p)){
            int b = atoi(pop(stack));
            int a = atoi(pop(stack));
            if(strcmp(p, "+") == 0){
                result = a + b;
            }else if(strcmp(p, "-")){
                result = a - b;
            }else if(strcmp(p, "*")){
                result = a * b;
            }else if(strcmp(p, "/")){
                result = a / b;
            }
            char tmp[MAX]; //cần phải khai 1 mảng đủ lớn để chứa cả kí tự '\0'
            sprintf(tmp, "%d", result); //chuyển result(int) sang tmp(xâu);
            push(stack, tmp);
        }else{
            push(stack, p);
        }
        p = strtok(NULL, " "); 
    }

    cout << "ket qua cua bieu thuc la: " << result << endl;
}

int main(){
    char s[] = "5 10 + 2 * 3 /"; //k cần khai báo kích thước trước, cách lấy kích thước mảng char size_t s = sizeof(s)
    cal(s);
}
