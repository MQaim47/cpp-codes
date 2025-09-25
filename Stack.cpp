
//using arrays
#include<iostream>
using namespace std;

class Stack{
public:
	int *arr;
	int top;
	int size;
	//behaviour
	Stack(int size){
		this->size = size;
		arr = new int[size];
		top = -1;
	}

	void push(int element){ //O(1)
		if (size - top > 1){
			top++;
			arr[top] = element;
		}
		else
			cout << "Stack overflow" << endl;
	}
	void pop(){				//O(1)
		if (top >= 0){
			top--;
		}
		else
			cout << "Stack undeflow" << endl;
	}
	int peek(){				//O(1)
		if (top >= 0){
			cout << "value is: ";
			return arr[top];
			cout << endl;
		}
		else
		{
			cout <<endl<< "Stack is empty" << endl;
			return -1;
			cout << endl;
		}
        cout<<endl;
	}
	bool isEmpty(){			//O(1)
		if (top == -1){
			return true;
		}
		else
			return false;
	}
};



//using linked list

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class Stack2 {
private:
	Node* top;

public:
	Stack2() {
		top = nullptr;
	}

	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Stack underflow" << endl;
			return;
		}
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	int peek() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		return top->data;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	~Stack2() {
		while (!isEmpty()) {
			pop();  // delete all nodes
		}
	}
};
int main(){
	Stack s1(5);
	s1.push(40);
	s1.push(42);
	s1.push(35);
	s1.push(98);
	s1.push(78);
	// s1.push(108); overflow
	cout << s1.peek()<<endl; // 78
	s1.pop();
	cout << s1.peek()<<endl;//98
	s1.pop();
	s1.pop();
	s1.pop();
	cout << s1.peek()<<endl;//40

	if (s1.isEmpty()){
		cout << "\n Stack is Empty" << endl;

	}
	else{
		cout << "\n Stack is not empty" << endl;
	}


    cout<<endl;
    cout<<"\t\t STACK USING LINKED LIST"<<endl;
    Stack2 s2;
	s2.push(10);
	s2.push(20);
	s2.push(30);

	cout << "\n Top element: " << s2.peek() << endl;

	s2.pop();
	cout << "\n Top after pop: " << s2.peek() << endl;

	s2.pop();
	s2.pop();

	if (s2.isEmpty())
		cout << "\n Stack is empty now." << endl;
	else
		cout << "\n Stack is not empty." << endl;

}



