#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

void removeLoop(Node *&head) {
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) {
            slow = head;
            break;
        }
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node *startingPoint = slow;
    Node *temp = slow;
    while(temp->next != startingPoint) {
        temp = temp->next;
    }
    temp->next = NULL;
}