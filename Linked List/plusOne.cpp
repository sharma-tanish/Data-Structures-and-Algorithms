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
        cout << "Memory freed for node with data " << this->data << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data) {
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

Node* reverse(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL) {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node *plusOne(Node *&head) {
    // Reverse
    head = reverse(head);
    // Add 1
    int carry = 1;
    Node *temp = head;
    while(temp->next != NULL) {
        int sum = temp->data + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        temp->data = lastDigit;
        temp = temp->next;
        if(carry == 0) {
            break;
        }
    }
    // Loop stopped at last node
    if(carry != 0) {
        int sum = temp->data + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        temp->data = lastDigit;
        if(carry != 0) {
            Node *newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    // Reverse again
    head = reverse(head);
    return head;
}

void print(Node *&head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    print(head);
    head = plusOne(head);
    print(head);

}