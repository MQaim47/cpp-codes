#include<iostream>
#include<string>
using namespace std;

class Stack {
public:
	string* arr;
	int top;
	int size;

	Stack(int size) {
		this->size = size;
		arr = new string[size];
		top = -1;
	}

	void push(string element) {
		if (size - top > 1) {
			top++;
			arr[top] = element;
		}
		else
			cout << "Stack overflow" << endl;
	}

	void pop() {
		if (top >= 0) {
			top--;
		}
		else
			cout << "Stack underflow" << endl;
	}

	string peek() {
		if (top >= 0) {
			return arr[top];
		}
		else {
			return ""; // return empty string instead of '\0' for consistency
		}
	}

	bool isEmpty() {
		return top == -1;
	}

	void clear() {
		top = -1;
	}
};

int main() {
	int size = 100;
	Stack undoStack(size);
	Stack redoStack(size);

	int choice;
	string line;

	while (true) {
		cout << "\n--- Menu ---\n";
		cout << "1. Type new line\n";
		cout << "2. Undo\n";
		cout << "3. Redo\n";
		cout << "4. View current line\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore(); // Clears leftover newline

		if (choice == 1) {
			cout << "Enter a line: ";
			getline(cin, line);
			undoStack.push(line);
			redoStack.clear(); // Clear redo on new action
		}
		else if (choice == 2) {
			if (!undoStack.isEmpty()) {
				string temp = undoStack.peek();
				undoStack.pop();            // remove from undo
				redoStack.push(temp);       // add to redo
				cout << "Undo performed.\n";
			}
			else {
				cout << "Nothing to undo.\n";
			}
		}
		else if (choice == 3) {
			if (!redoStack.isEmpty()) {
				string temp = redoStack.peek();
				redoStack.pop();            // remove from redo
				undoStack.push(temp);       // add back to undo
				cout << "Redo performed.\n";
			}
			else {
				cout << "Nothing to redo.\n";
			}
		}
		else if (choice == 4) {
			if (!undoStack.isEmpty()) {
				cout << "Current line: " << undoStack.peek() << endl;
			}
			else
				cout << "No current line.\n";
		}
		else if (choice == 5) {
			cout << "Exiting.\n";
			break;
		}
		else {
			cout << "Invalid choice. Try again.\n";
		}
	}

	return 0;
}

