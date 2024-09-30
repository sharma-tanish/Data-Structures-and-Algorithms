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
};

bool detectCycle(Node *head) {
    if(head == NULL) {
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }    
        if(fast == slow) {
            return true;
        }
    }
    return false;
}