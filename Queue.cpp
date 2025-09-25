
//queue implementation using arrays 
#include<iostream>
#include<string>
using namespace std;
class Queue{
	int *arr;
	int front;
	int rear;
	int size;
public:
	Queue(){
		size = 100001;
		arr = new int[size];
		front = 0;
		rear = 0;
	}
	void enqeue(int data){
		if (rear == size){
			cout << "Queue is full" << endl;
		}
		else
		{
			arr[rear] = data;
			rear++;
		}
	}
	int dequeue(){ //O(1)
		if (front == rear){
			return -1;
		}
		else{
			arr[front] = -1;
			front++;
			if (front == rear)//to avoid free memory go waste
			{
				front = 0;
				rear = 0;
			}
		}
	}
	int qfront(){ //O(1)
		if (front == rear){
			return -1;
		}
		else{
			return arr[front];
		}
	}
	bool isEmpty(){   //O(1)
		if (front == rear){
			return true;
		}
		else{
			return false;
		}
	}


	
	
};

//USING LINKED LIST
class Node {
public:
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = nullptr;
	  }
};

// Queue class using linked list
class Queue2 {
	Node* front;
	Node* rear;

public:
	Queue2() {
		front = rear = nullptr;
	}

	// Enqueue operation (Insert at rear)
	void enqueue2(int val) {
		Node* newNode = new Node(val);
		if (rear == nullptr) { // First element
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	// Dequeue operation (Remove from front)
	int dequeue2() {
		if (front == nullptr) {
			cout << "Queue is empty\n";
			return -1;
		}

		int val = front->data;
		Node* temp = front;
		front = front->next;

		// If queue becomes empty
		if (front == nullptr) {
			rear = nullptr;
		}

		delete temp;
		return val;
	}

	// Peek front element
	int qfront2() {
		if (front == nullptr) {
			cout << "Queue is empty\n";
			return -1;
		}
		return front->data;
	}

	// Check if queue is empty
	bool isEmpty2() {
		return front == nullptr;
	}
};

int main(){
	Queue q;
	q.enqeue(11);
	cout << "Front of queue is " << q.qfront() << endl;
	q.enqeue(15);
	cout << "Front of queue is " << q.qfront() << endl;
	q.enqeue(23);
	q.dequeue();
	cout << "Front of queue is " << q.qfront() << endl;
	
	
	if (q.isEmpty()){
		cout << "queue is empty<<<" << endl;
	}
	else
		cout << "queue is not empty" << endl;


	cout<<endl;
	cout<<"\t\t USING LINKED LIST"<<endl;
	Queue2 q2;
	q2.enqueue2(8);
	cout << "Front of queue: " << q2.qfront2() << endl;

	q2.enqueue2(55);
	cout << "Front of queue: " << q2.qfront2() << endl;

	q2.enqueue2(24);
	cout << "Front of queue: " << q2.qfront2() << endl;

	q2.dequeue2();
	cout << "After 1 dequeue, front is: " << q2.qfront2() << endl;

	if (q2.isEmpty2()) {
		cout << "Queue is empty\n";
	}
	else {
		cout << "Queue is not empty\n";
	}

	return 0; 
}








