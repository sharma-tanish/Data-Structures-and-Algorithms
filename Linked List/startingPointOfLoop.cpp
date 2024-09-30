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

Node* startingPointOfLoop(Node *&head) {
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
    return slow;
}