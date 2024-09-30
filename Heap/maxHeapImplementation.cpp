#include <iostream>
using namespace std;

class Heap {
public:
    int* arr;
    int capacity;
    int size; // Current number of elements in heap

    Heap(int capacity) {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val) {
        if(size == capacity) {
            cout << "Heap Overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;

        // Place the value to its correct position
        while(index > 1) {
            int parentIndex = index / 2;
            if(arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    int del() {
        int ans = arr[1];
        // Replace root element with last element
        arr[1] = arr[size];
        // Delete last element from its original position
        size--;

        // Heapification
        int index = 1;
        while(index < size) {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // Find the maximum element among three
            int maxiIndex = index;
            // Check left child
            if(leftIndex <= size && arr[leftIndex] > arr[maxiIndex]) {
                maxiIndex = leftIndex;
            }
            // Check right child
            if(rightIndex <= size && arr[rightIndex] > arr[maxiIndex]) {
                maxiIndex = rightIndex;
            }

            // If no change in maxiIndex
            if(index == maxiIndex) {
                break;
            }
            // If maxiIndex got updated
            else {
                swap(arr[index], arr[maxiIndex]);
                index = maxiIndex;
            } 
        }
        return ans;
    }

    void printHeap() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int* arr, int size, int index) {
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int maxiIndex = index;

    // Find max among all three
    if(leftIndex <= size && arr[leftIndex] > arr[maxiIndex]) {
        maxiIndex = leftIndex;
    }
    if(rightIndex <= size && arr[rightIndex] > arr[maxiIndex]) {
        maxiIndex = rightIndex;
    }
    // After these two conditions, maxiIndex will be pointing to index of the largest element among three 
    
    if(index != maxiIndex) {
        swap(arr[index], arr[maxiIndex]);
        index = maxiIndex;
        heapify(arr, size, index);
    }
    else {
        return;
    }
}

void buildHeap(int* arr, int n) {
    for(int index = n / 2; index > 0; index--) {
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main() {

    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.printHeap();

    // int deletedElement = h.del();
    // cout << "Deleted Element: " << deletedElement << endl;

    // h.printHeap();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;

    buildHeap(arr, n);

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}