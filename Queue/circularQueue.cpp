#include <iostream>
#include <queue>

using namespace std;

class CircularQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int element) {
        if(front == 0 && rear == size - 1 || front - rear == 1) {
            // Overflow
            cout << "Queue overflow" << endl;
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

    void pop() {
        if(front == -1 && rear == -1) {
            cout << "Queue underflow" << endl;
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

    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSize() {
        if(front == -1 && rear == -1) {
            // Queue is empty
            return 0;
        }
        else {
            return rear - front + 1;
        }
    }

    int getFront() {
        if(front == -1) {
            // Queue is empty
            return -1;
        }
        else {
            return arr[front];
        }
    }

    int getRear() {
        if(rear == -1) {
            // Queue is empty
            return -1;
        }
        else {
            return arr[rear];
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

    CircularQueue q(5);

    q.print();
    q.push(4);
    q.print();
    q.push(6);
    q.print();
    q.push(2);
    q.print();
    q.push(8);
    q.print();
    q.push(9);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(100);
    q.print();
    q.push(200);
    q.print();
    q.push(300);
    q.print();
    q.push(700);
    q.print();

    cout << "Size: " << q.getSize() << endl;

    q.pop();
    q.print();

    cout << "Size: " << q.getSize() << endl;
    cout << "Empty: " << q.isEmpty() << endl;

    q.push(100);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout << "Front: " << q.getFront() << endl;
    q.pop();
    q.print();

    cout << "Size: " << q.getSize() << endl;
    
    return 0;
}