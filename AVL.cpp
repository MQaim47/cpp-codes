#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Node{
	public:
		int data;
		Node*left;
		Node*right;
		int height;
		Node(int d){
			this->data = d;
			this->left = NULL;
			this->right = NULL;
			height = 1;
		}

	};
	class AVL{
	private:
		Node* root;
	
		int getHeight(Node* n){
			if (n == NULL){ return 0; }
			else
				return n->height;

		}
		int getBalance(Node* n){
			if (n == NULL){ return 0; }
			else
				return getHeight(n->left)-getHeight(n->right);
		}
		int max(int a, int b){
			if (a > b){ return a; }
			else
				return b;
		}

		void inorder(Node* root){
			if (root == NULL){ return; }
			inorder(root->left);

			cout << root->data << " ";

			inorder(root->right);
		}

		Node* rightRotation(Node* y){
			Node* x = y->left;
			Node* t2 = x->right;

			x->right = y;
			y->left = t2;

			y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
			x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
			return x;
		}
		Node* leftRotation(Node* x){
			Node* y = x->right;
			Node* t2 = y->left;

			y->left= x;
			x->right= t2;

			x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
			y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
			return y;
		}
		Node* insert(Node*& root, int key){
			if (root == NULL){
				root = new Node(key);
				return root;
			}
			if (key > root->data){
				root->right = insert(root->right, key);
			}
			else if (key<root->data)
			{
				root->left = insert(root->left, key);

			}
			else{
				return root;
			}
				root->height = 1 + max(getHeight(root->left), getHeight(root->right));
				int balance = getBalance(root);
				//LL
				if (balance > 1 && key < root->left->data){ return rightRotation(root); }
				//RR
				if (balance  <-1 && key > root->right->data){ return leftRotation(root); }
				//LR
				if (balance > 1 && key > root->left->data){
					root->left = leftRotation(root->left);
					return rightRotation(root); 
				}
				//RL
				if (balance <- 1 && key < root->left->data){
					root->right = rightRotation(root->right);
					return leftRotation(root);
				}
				return root;
		}
		void display(Node *root){
			queue<Node*>q;
			q.push(root);
			q.push(NULL);
			while (!q.empty()){
				Node*temp = q.front();
				q.pop();
				if (temp == NULL)
				{
					cout << endl;
					if (!q.empty()){
						q.push(NULL);
					}
				}
				else{
					cout << temp->data << " ";
					if (temp->left){
						q.push(temp->left);
					}
					if (temp->right){
						q.push(temp->right);
					}
				}


			}
		}
public:
	AVL(){
		root = NULL;
	}
		void takeInput(){
			int data;
			cin >> data;
			while (data != -1){
				root = insert(root, data);
				cin >> data;
			}
		}
		void display(){
			cout << "Level order Traversal" << endl;
			display(root);
		}
	};
	int main(){
		
		AVL avl;
		
		cout << "Enter data to create AVL tree->->->(-1 to stop):" << endl;
		///avl.takeInput(root);
		avl.takeInput();
		cout << "AVL tree Level order:"  << endl;
		avl.display();

		//avl.inorder();
		//cout << endl;
	return 0;
}