#include <iostream>
#include <deque>

using namespace std;

class CircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularDeque(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int element) {
        if(front == 0 && rear == size - 1 || front - rear == 1) {
            // Overflow
            cout << "Deque overflow" << endl;
            return;
        }
        else if(front == -1 && rear == -1) {
            // Single element
            front++;
            rear++;
            arr[rear] = element;
        }
        else if(rear == size - 1 && front != 0) {
            // Circular
            rear = 0;
            arr[0] = element;
        }
        else {
            rear++;
            arr[rear] = element; 
        }
    }

    void pushFront(int element) {
        if(front == 0 && rear == size - 1 || front - rear == 1) {
            cout << "Deque overflow" << endl;
            return;
        }
        else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[front] = element;
        }
        else if(front == 0 && rear != size - 1) {
            // Circular
            front = size - 1;
            arr[front] = element;
        }
        else {
            front--;
            arr[front] = element;
        }
    }

    void popFront() {
        if(front == -1 && rear == -1) {
            cout << "Deque underflow" << endl;
            return;
        }
        else if(front == rear) {
            // Single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size - 1) {
            // Circular
            arr[front] = -1;
            front = 0;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }

    void popBack() {
        if(front == -1 && rear == -1) {
            cout << "Deque underflow" << endl;
        }
        else if(front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0) {
            // Circular
            arr[rear] = -1;
            rear = size - 1;
        }
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    CircularDeque dq(5);

    dq.pushBack(32);
    dq.print();
    dq.pushBack(73);
    dq.print();
    dq.pushFront(81);
    dq.print();
    dq.pushBack(69);
    dq.print();
    dq.popFront();
    dq.print();

    return 0;
}