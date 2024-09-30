#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    // Constructor
    Node() {
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // Freeing memory for first node
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data) {
    // Handling empty linked list
    if(head == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    // Handling empty linked list
    if(head == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data) {
    // Handling first node
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // Traversing to insertion point
    Node *temp = head;
    int count = 1;
    while(count < position - 1) {
        temp = temp->next;
        count++;
    }

    // Handling last node
    if(temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    // Creating a new node for insertion
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position) {
    // Deleting first node
    if(position == 1) {
        Node *temp = head;
        head = head->next;
        // Freeing memory for first node
        temp->next = NULL;
        delete temp;
    }
    // Deleting middle or last node
    else {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr->next; 
            count++;
        }
        // Handling tail if deleting last node
        if(curr->next == NULL) {
            prev->next = NULL;
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; 
}


int main() {

    // Created a new node
    Node *node1 = new Node(10);  
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    
    // Head pointed to node1
    Node *head = node1;
    // Tail pointed to node1
    Node *tail = node1;
    
    print(head);
    insertAtHead(head, tail, 12);
    print(head);
    insertAtHead(head, tail, 15);
    print(head);
    insertAtTail(head, tail, 31);
    print(head);
    insertAtTail(head, tail,17);
    print(head);
    insertAtPosition(head, tail, 3, 24);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 6);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}