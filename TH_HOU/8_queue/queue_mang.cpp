#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
using ll = long long;

#define MAX_OF_QUEUE 10
int que[MAX_OF_QUEUE];
int rear = -1;
int front = -1;
//prototype
void enqueue(int value);
int dequeue();


int main(){

	enqueue(10);
	enqueue(30);
	enqueue(20);
	cout << dequeue();
	cout << dequeue();
	cout << dequeue();
	

	return 0;
}

void enqueue(int value){
	if(rear < MAX_OF_QUEUE-1){
		rear++;
		que[rear] = value;
	}else{
		cout << "queue is full";
		exit(0);
	}
}

int dequeue(){
	if(front == rear){
		cout << "queue is full";
		exit(0);
	}
	front++;
	int value = que[front];
	return value;
}