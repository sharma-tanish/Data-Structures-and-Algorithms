#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
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
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    // Handling empty linked list
    if(tail == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data) {
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while(count < position - 1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position) {
    // Deleting first node
    if(position == 1) {
        Node *temp = head;
        head = head->next;
        temp->next->prev = NULL;
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
        if(curr->next == NULL) {
            curr->prev = NULL;
            prev->next = NULL;
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int getLength(Node *&head) {
    Node *temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node *head = NULL;
    Node *tail = NULL;

    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 26);
    print(head);
    insertAtHead(head, tail, 17);
    print(head);
    insertAtHead(head, tail, 35); 
    print(head);

    insertAtTail(head, tail, 21);
    print(head);

    insertAtPosition(head, tail, 3, 30);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 4);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}