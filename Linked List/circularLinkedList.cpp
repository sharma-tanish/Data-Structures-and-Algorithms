#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int refElement, int data) {
    // Empty list
    if(tail == NULL) {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }

    else {
        Node *curr = tail;
        while(curr->data != refElement) {
            curr = curr->next;
        }
        // Reference element found
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int refElement) {
    // Empty list
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    else {
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != refElement) {
            prev = curr;
            curr = curr->next;
        }

        // Single node
        if(curr == prev) {
            tail = NULL;
        }
        
        // Relocating tail to print the linked list
        if(tail == curr) {
            tail = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail) {
    Node *temp = tail;

    // Empty list
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while(tail != temp); 
    cout << endl;
}
 
int main() {

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 3, 8);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}