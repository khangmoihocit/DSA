#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;
#define MAX_OF_STACK 10

int sta[MAX_OF_STACK];
int top = -1;
//prototype
void push(int value);
int pop();

void chuyennhiphan(int n){
	while(n > 0){
		int x = n%2;
		push(x);
		n/=2;
	}
	while(top!=-1){
		cout << pop();
	}
}

int main(){
	int n; cin >> n;
	chuyennhiphan(n);
	return 0;
}

void push(int value){
	if(top < MAX_OF_STACK - 1){
		top++;
		sta[top] = value;
	}else{
		cout << "stack đã đầy";
		exit(0);
	}
}

int pop(){
	int value;
	if(top >= 0){
		value = sta[top];
		top--;
	}else{
		cout << "stack rong";
		exit(0);
	}
	return value;
}