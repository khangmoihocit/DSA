#include <bits/stdc++.h>
using namespace std;
using namespace std;

// Hàm kiểm tra toán tử
bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Hàm kiểm tra ưu tiên của toán tử
int getPrecedence(char c) {
	if (c == '^') {
		return 3;
	} else if (c == '*' || c == '/') {
		return 2;
	} else if (c == '+' || c == '-') {
		return 1;
	} else {
		return 0;
	}
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string infixToPostfix(string infix) {
	stack<char> operatorStack;
	string postfix = "";

	for (char c : infix) {
    	if (isalnum(c)) { // Kiểm tra xem ký tự là chữ số hoặc chữ cái
    		postfix += c;
    	} else if (c == '(') {
    		operatorStack.push(c);
    	} else if (c == ')') {
    		while (!operatorStack.empty() && operatorStack.top() != '(') {
    			postfix += operatorStack.top();
    			operatorStack.pop();
    		}
      	operatorStack.pop(); // Xóa dấu ngoặc mở
  		} else if (isOperator(c)) {
  			while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
  				postfix += operatorStack.top();
  				operatorStack.pop();
  			}
  		operatorStack.push(c);
  		}
	}

	while (!operatorStack.empty()) {
		postfix += operatorStack.top();
		operatorStack.pop();
	}

	return postfix;
}

int main() {
	string infixExpression;
  	getline(cin, infixExpression); // Nhập chuỗi biểu thức
  	string postfixExpression = infixToPostfix(infixExpression);
  	cout << postfixExpression << endl;
  	return 0;
}


