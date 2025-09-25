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
Node* buildTree() {
	int data;
	cout << "Enter data: ";
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	Node* root = new Node(data); 

	cout << "Enter data to insert at left of " << data << endl;
	root->left = buildTree(); 

	cout << "Enter data to insert at right of " << data << endl;
	root->right = buildTree(); 

	return root;
}

void levelOrderTraversal(Node *root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()){
		Node*temp = q.front();
		q.pop();
		if (temp == NULL)//purana level complete hogya
		{
			cout << endl;
			if (!q.empty()){//q still has some child nodes
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
void inorderTraversal(Node* root){
	if (root == NULL){ return; }
	inorderTraversal(root->left);//LEFT

	cout << root->data << " " ;//NODE(PRINT IT),MIDDLE

	inorderTraversal(root->right);//RIGHT
}
void preorderTraversal(Node* root){
	if (root == NULL){ return; }
	cout << root->data << " ";

	preorderTraversal(root->left);
	
	preorderTraversal(root->right);
}
void postorderTraversal(Node* root){
	if (root == NULL){ return; }
	postorderTraversal(root->left);

	postorderTraversal(root->right);

	cout << root->data << " ";
}
int main(){
	Node*root = NULL;
	root = buildTree();

	cout << "" << endl;
	levelOrderTraversal(root);
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	
	cout << "Inorder traversal is: ";
	inorderTraversal(root);

	cout<< endl;
	cout << "Preorder traversal is: ";
	preorderTraversal(root);
	cout << endl;
	cout << "Postorder traversal is: ";
	postorderTraversal(root);
	cout << endl;
	return 0;
}