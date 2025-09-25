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
		void inorder(Node* root){
			if (root == NULL){ return; }
			inorder(root->left);

			cout << root->data << " ";

			inorder(root->right);
		}
		bool search(Node*root, int d){
			if (root == NULL){ return false; }
			if (root->data == d){ return true; }
			if (root->data > d){
				return (search(root->left, d));
			}
			else
				return (search(root->right, d));
		}
		int countNodes(Node* root){
			if (root == NULL){ return 0; }
			int left = countNodes(root->left);
			int right = countNodes(root->right);
			return 1 + left + right;
		}
		int getMin(Node*root){
			if (root == NULL){ return -1; }
			while (root->left != NULL){
				root = root->left;
				return root->data;
			}
		}
			int getMax(Node*root){
				if (root == NULL){ return -1; }
				while (root->right != NULL){
					root = root->right;
					return root->data;
				}
			}
		
			int sumScores(Node* root){
				if (root == NULL){ return 0; }
				int left = sumScores(root->left);
				int right = sumScores(root->right);
				return root->data + left + right;
			}
			void printInRange(Node*root, int low, int high){
				if (root == NULL){ return; }
				if (root->data > low){
					printInRange(root->left, low, high);
				}
				if (root->data >= low&& root->data <= high){
					cout << root->data << " ";
				}
				if (root->data < high){
					printInRange(root->right, low, high);
				}
			}
			int countGreater(Node*root, int x){
				if (root == NULL){ return 0; }
				if (root->data <= x){
					return countGreater(root->right, x);
				}
				return 1+ countGreater(root->right, x) + countGreater(root->left, x);
			}
			int countSmaller(Node* root, int x){
				if (root == NULL){ return 0; }
				if (root->data >= x){
					return countGreater(root->left, x);
				}
				return 1 + countGreater(root->left, x) + countGreater(root->right, x);
			}
			void printLeaf(Node* root){ 
				if (root == NULL){ return ; }
				if (root->left == NULL && root->right == NULL){
					cout << root->data << " ";
					return;
				}
				printLeaf(root->left);
				printLeaf(root->right);
			}
			int findLevel(Node* root, int key, int level){
				if (root == NULL){ return -1; }
				if (root->data == key){ return level; }
				if (key < root->data){
					return findLevel(root->left, key, level + 1);
				}
				return findLevel(root->right, key, level + 1);
			}
			int kthSmallest(Node*root, int k, int& count){
				if (root == NULL){ return -1; }
				int left = kthSmallest(root->left, k, count);
				if (left != -1){ return left; }
				count++;
				if (count == k){ return root->data; }
				return kthSmallest(root->right, k, count);
			}
		void levelOrderTraversal(Node *root){
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
			levelOrderTraversal (root);
		}
		void printOrder(){
			cout << "Sorted Leaderboard: ";
			inorder(root);
			cout << endl;
		}
		void printTotalPlayers(){
			cout << "Total Players are: " << countNodes(root) << endl;
		}
		void printMinScore(){
			cout << "Lowest Score: " << getMin(root) << endl;
		}
		void printMaxScore(){
			cout << "Highest Score: " << getMax(root) << endl;
		}
		void printSum(){
			cout << "Total Score sum: " << sumScores(root) << endl;
		}
		void checkScore(int score){
			bool found = search(root, score);
			if (found){
				cout <<"Score " <<score << " is in leaderboard" << endl;
			}
			else
				cout << score << " not found" << endl;
		}
		void printScoresinRange(int l, int r){
			cout << "Scores in range [" << l << "," << r << "]: ";
			printInRange(root, l, r);
			cout << endl;
		}
		void printCountGreater(int x){
			cout << "Scores greater than " << x << ": " << countGreater(root, x) << endl;
		}
		void printCountSmaller(int x){
			cout << "Scores smaller than " << x << ": " << countSmaller(root, x) << endl;
		}
		void printLeaves(){
			cout << "Players with no children: ";
			printLeaf(root);
			cout << endl;
		}
		void printLevelofScore(int score){
			int level = findLevel(root, score, 1);
			if (level != -1){
				cout << score << " is at level " << level << endl;
			}
			else
				cout << "Score not found" << endl;
		}
		void printKthSmallest(int k){
			int count = 0;
			int result = kthSmallest(root, k, count);
			if (result != -1){
				cout << k << "rd smallest score is:" << result << endl;
			}
			else
				cout << "Invalid k" << endl;
		}
	};
	int main(){
		cout << "					WELCOME TO LEADERBOARD            " << endl;
		AVL leaderboard;

		cout << "Enter scores (-1 to end): ";
		leaderboard.takeInput();

		leaderboard.display();
		leaderboard.printOrder();
		leaderboard.printTotalPlayers();
		leaderboard.printMinScore();
		leaderboard.printMaxScore();
		leaderboard.printSum();

		leaderboard.checkScore(35);
		leaderboard.printScoresinRange(20, 100);
		leaderboard.printCountGreater(40);
		leaderboard.printCountSmaller(30);
		leaderboard.printLeaves();
		leaderboard.printLevelofScore(35);
		leaderboard.printKthSmallest(3);

		return 0;
	
}