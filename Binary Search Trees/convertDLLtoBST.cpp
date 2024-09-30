#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root) {
    queue<Node*> q; 
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";

            if(front->left != NULL) {
                q.push(front->left);
            }

            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

Node* BSTFromInorder(int inorder[], int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    int element = inorder[mid];

    Node* root = new Node(element);
    root->left = BSTFromInorder(inorder, start, mid - 1);
    root->right = BSTFromInorder(inorder, mid + 1, end);

    return root;
}

Node* convertDLLtoBST(Node* &head, int n) {
    if(head == NULL || n <= 0) {
        return NULL;
    }

    // L
    Node* leftSubTree = convertDLLtoBST(head, n / 2);
    // N
    Node* root = head;
    root->left = leftSubTree;
    head = head->right;
    // R
    root->right = convertDLLtoBST(head, n - (n / 2) - (1));

    return root;
}

void printDLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
}

int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    first->left = NULL;

    second->right = third;
    second->left = first;

    third->right = NULL;
    third->left = second;

    printDLL(first);

    Node* root = convertDLLtoBST(first, 3);

    levelOrderTraversal(root);

    return 0;
}