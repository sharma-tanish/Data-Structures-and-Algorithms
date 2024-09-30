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

void convertBSTtoDLL(Node* root, Node* &head) {
    if(root == NULL) {
        return;
    }

    // Reverse inorder traversal

    // R
    convertBSTtoDLL(root->right, head);
    // N
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }
    head = root;
    // L
    convertBSTtoDLL(root->left, head);
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

    int inorder[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = sizeof(inorder) / sizeof(int);
    int start = 0;
    int end = size - 1;
    Node* root = BSTFromInorder(inorder, start, end);

    levelOrderTraversal(root);

    Node* head = NULL;
    convertBSTtoDLL(root, head);
    printDLL(head);

    return 0;
}