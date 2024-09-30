#include <iostream>

using namespace std;

class KQueue {
public:
    int n;
    int k;
    int freeSpot;
    int *arr;
    int *front;
    int *rear;
    int *next;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        for(int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    // Push val into qith queue
    bool push(int val, int qi) {
        // Overflow
        if(freeSpot == -1) {
            return false;
        }

        // Find first free index
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index]; 

        // If first element in qi
        if(front[qi] == -1) {
            front[qi] = index;
        }
        else {
            // Link new element to that q's rearest element
            next[rear[qi]] = index;
        }

        // Update next
        next[index] = -1;

        // Update rear
        rear[qi] = index;

        arr[index] = val;

        return true;
    }

    // Pop element from qith queue
    int pop(int qi) {
        //Underflow
        if(front[qi] == -1) {
            return -1;
        }

        // Find index to pop
        int index = front[qi];

        // Update front
        front[qi] = next[index];

        // Manage freeSpot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main() {

    KQueue kq(8, 3);
    cout << kq.push(1, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;
    cout << kq.pop(1) << endl;
    cout << kq.pop(1) << endl;
    cout << kq.pop(0) << endl;

    return 0;
}