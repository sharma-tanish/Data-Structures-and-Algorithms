#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) {
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* findSuccessor(Node *root, Node *x) {
    Node* succ = NULL;
    Node* curr = root;
    while(curr) {
        if(curr->data > x->data) {
            succ = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return succ;
}

Node* findPredecessor(Node* root, Node* p) {
	Node* pred = NULL;
	Node* curr = root;
	while(curr) {
		if(curr->data < p->data) {
			pred = curr;
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	return pred;
}