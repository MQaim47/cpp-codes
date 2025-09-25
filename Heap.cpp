#include<iostream>
#include<string>
#include<queue>
using namespace std;
class MaxHeap{
	int *arr;
	int size;//how many elements are present at the moment
	int total_size;//total size of an array;
public:
	MaxHeap(int n){
		arr = new int[n];
		size = 0;
		total_size = n;
	}
	void insert(int val){
		if (size == total_size){
			cout << "Heap Overflow" << endl;
			return;
		}

		arr[size] = val;
		int index = size;
		size++;
		//compare with its parent using formula (index-1)/2
		while (index > 0 && arr[(index - 1) / 2] < arr[index])//will run jbtk parent>child node 
		{
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1 )/ 2;
		}
	}
	void deleteHeapElements(){
		if (size == 0){ cout << "Heap underflow" << endl;
		return;
		}
		cout << arr[0] << "  deleted" << endl;
		arr[0] = arr[size - 1];//because always delete top most node and replace it wid last node
		size--;
		if (size == 0)
			return;
		heapify(0);
	}
	void heapify(int index){
		int largest = index; //it will store index of element which is greater b/w parent and child node
		int left = 2 * index + 1;//incase of left child
		int right = 2 * index + 2;
		if (left < size && arr[left]>arr[largest]){
			largest = left;
		}
		if (right < size && arr[right]>arr[largest]){
			largest = right;
		}
		if (largest != index){
			swap(arr[index], arr[largest]);
			heapify(largest);
		}
	}
	void print(){
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "  ";
		}
	}
};

class MinHeap{
	int *arr;
	int size;//how many elements are present at the moment
	int total_size;//total size of an array;
public:
	MinHeap(int n){
		arr = new int[n];
		size = 0;
		total_size = n;
	}
	void insert(int val){
		if (size == total_size){
			cout << "Heap Overflow" << endl;
			return;
		}

		arr[size] = val;
		int index = size;
		size++;
		//compare with its parent using formula (index-1)/2
		while (index > 0 && arr[(index - 1) / 2] > arr[index])//will run jbtk parent <child node 
		{
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	void deleteHeapElements2(){
		if (size == 0){
			cout << "Heap underflow" << endl;
			return;
		}
		cout << arr[0] << "  deleted" << endl;
		arr[0] = arr[size - 1];//because always delete top most node and replace it wid last node
		size--;
		if (size == 0)
			return;
		heapify(0);
	}
	void heapify(int index){
		int smallest = index; //it will store index of element which is greater b/w parent and child node
		int left = 2 * index + 1;//incase of left child
		int right = 2 * index + 2;
		if (left < size && arr[left]<arr[smallest]){
			smallest = left;
		}
		if (right < size && arr[right]<arr[smallest]){
			smallest = right;
		}
		if (smallest != index){
			swap(arr[index], arr[smallest]);
			heapify(smallest);
		}
	}
	void print(){
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "  ";
		}
	}
};


int main(){
	MinHeap m1(6);
	m1.insert(4);
	m1.insert(14);
	m1.insert(11);
	m1.insert(118);
	m1.insert(23);
	m1.insert(6);
	
	m1.print();

	m1.deleteHeapElements2();
	m1.print();
	return 0;
}