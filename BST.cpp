#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Node{
public:
	int data;
	Node*left;
	Node*right;
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}

};
class BST{
private:
	Node* root;
public:
	BST(){}
	void takeInput(Node*& root){
		int data;
		cin >> data;
		while (data != -1){
			root = insertBST(root, data);
			cin >> data;
		}
	}
	Node* insertBST(Node*& root, int data){
		if (root == NULL){
			root = new Node(data);
			return root;
		}
		if (data > root->data){
			root->right = insertBST(root->right, data);
		}
		else
			root->left = insertBST(root->left, data);
		return root;
	}
	bool find(Node*root, int d){
		if (root == NULL){ return false; }
		if (root->data == d){ return true; }
		if (root->data > d){
			return (find(root->left, d));
		}
		else
			return (find(root->right, d));
	}
	void inorder(Node* root){
		if (root == NULL){ return; }
		inorder(root->left);

		cout << root->data << " ";

		inorder(root->right);
	}
	void preorder(Node* root){
		if (root == NULL){ return; }
		cout << root->data << " ";

		preorder(root->left);

		preorder(root->right);
	}
	void postorder(Node* root){
		if (root == NULL){ return; }
		postorder(root->left);

		postorder(root->right);

		cout << root->data << " ";
	}
	Node* getMin(Node*root){
		Node* temp = root;
		while (temp->left!= nullptr){
			temp = temp->left;
		}
		return temp;
	}
	Node* getMax(Node*root){
		Node* temp = root;
		while (temp->right!= nullptr){
			temp = temp->right;
		}
		return temp;
	}
	Node* deletefromBST(Node*root, int val){
		
		if (root == nullptr){
			return root;
		}
		if (root->data == val){
			//0child
			if (root->left == nullptr && root->right == nullptr){
				delete root;
				return nullptr;
			}
			//1child
			if (root->left != nullptr && root->right == nullptr){
				Node*temp = root->left;
				delete root;
				return temp;
			}
			if (root->left == nullptr && root->right != nullptr){
				Node*temp = root->right;
				delete root;
				return temp;
			}

			//2child
			if (root->left != nullptr && root->right != nullptr){
				int mini = getMin(root->right)->data;
				root->data = mini;
				root->right = deletefromBST(root->right, mini);
				return root;
			}
		}
			else if (root->data > val){
				root->left = deletefromBST(root->left, val);
				return root;
			}
			else {
				root->right = deletefromBST(root->right, val);
				return root;
			}
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
};


int main(){
	Node*root = NULL;
	BST b;
	cout << "Enter data to create BST" << endl;
	b.takeInput(root); //10 8 21 7 27 5 4 3 -1
	cout << "Printing BST: " << endl;
	b.display(root);


	cout << "Inorder traversal is: ";
	b.inorder(root);

	cout << endl;
	cout << "Preorder traversal is: ";
	b.preorder(root);
	cout << endl;
	cout << "Postorder traversal is: ";
	b.postorder(root);
	cout << endl;
	cout << "Enter num you want to delete:";

	b.deletefromBST(root, 1);
	b.display(root);
	return 0;
}