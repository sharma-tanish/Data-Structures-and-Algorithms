#include <iostream>
#include <queue>
#include <map>

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

Node *createTree() {
    cout << "Enter node value: ";
    int value;
    cin >> value;

    if(value == -1) {
        return NULL;
    }

    // Create node for value
    Node *root = new Node(value);

    cout << "Enter value to left of " << root->data << endl;
    root->left = createTree();

    cout << "Enter value to right of " << root->data << endl;
    root->right = createTree();

    return root;
}

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

void leftTraversal(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }

    cout << root->data << " ";
    if(root->left != NULL) {
        leftTraversal(root->left);
    }
    else {
        leftTraversal(root->right);
    }
}

void leafBoundary(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
}

void rightTraversal(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }

    if(root->right != NULL) {
        rightTraversal(root->right);
    }
    else {
        rightTraversal(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node *root) {
    if(root == NULL) {
        return;
    }

    leftTraversal(root);
    leafBoundary(root);
    if(root->right != NULL) {
        rightTraversal(root->right);
    }
    else {
        rightTraversal(root->left);
    }
}

int main() {

    Node *root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    levelOrderTraversal(root);

    boundaryTraversal(root);

    return 0;
}