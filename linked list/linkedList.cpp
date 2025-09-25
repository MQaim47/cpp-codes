#include<iostream>
using namespace std;

class Node {
	
public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		this->next = nullptr;
	}
	~Node(){
		int val = this->data;
		if (this->next != nullptr){
			delete next;
			this-> next = nullptr;
		}
		cout << "Memory free for:: " << val << endl;
	}
};
void insertAtHead(Node* &head, int d){//can be said stack also
	Node * temp = new Node(d);
	temp->next = head;
	head = temp;
}
void insertAtTail(Node* &tail, int d){//can be said queue
	Node *temp = new Node(d);
	tail->next = temp;
	tail = temp;
}
void insertAtPoistion(Node* &head, Node*&tail, int pos, int d){
	if (pos == 1){
		insertAtHead(head, d);
		return;
	}
	Node *temp = head;
	if (temp->next == nullptr){
		insertAtTail(tail, d);
		return;
	}
	int count = 1;
	while (count < pos - 1){
		temp = temp->next;
		count++;
	}
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp ->next;
	temp->next = nodeToInsert;
}
void print(Node* &head){
	if (head == nullptr){ cout << "Empty" << endl; return; }
	Node*temp = head;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void deleteNode(Node* &head, int pos){
	if (pos == 1){
		Node*temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
	}
	else{
		Node* curr = head;
		Node* prev = nullptr;
		int count = 1;
		while (count < pos){
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = curr->next;
		curr->next = nullptr;
		delete curr;
	}
};
int main(){

	Node* node1 = new Node(10);

	Node *head = node1;
	Node *tail= node1;
	print(head);
	insertAtHead(head, 12);
	print(head);
	insertAtHead(head, 89);
	print(head);
	insertAtHead(head, 47);
	print(head);

	insertAtTail(tail, 9);
	print(head);

	insertAtPoistion(head,tail, 3, 99);
	print(head);



	

}
