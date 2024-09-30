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

// Returns root note of tree created
Node* createTree() {
    cout << "Enter node value: ";
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    // Create node
    Node *root = new Node(data);

    // Create left subtree
    cout << "Enter value to left of " << root->data << endl;
    root->left = createTree();

    // Create right subtree
    cout << "Enter value to right of " << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node *root) {
    // Base case
    if(root == NULL) {
        return;
    }

    // N
    cout << root->data << " ";

    // L
    preOrderTraversal(root->left);

    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
    // Base case
    if(root == NULL) {
        return;
    }

    // L
    inOrderTraversal(root->left);

    // N
    cout << root->data << " ";

    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    // Base case
    if(root == NULL) {
        return;
    }

    // L
    postOrderTraversal(root->left);

    // R
    postOrderTraversal(root->right);

    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";

        if(front->left != NULL) {
            q.push(front->left);
        }

        if(front->right != NULL) {
            q.push(front->right);
        }
    }
}

void levelOrderTraversalSeparately(Node *root) {
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

int main() {

    Node *root = createTree();

    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal separately: " << endl;
    levelOrderTraversalSeparately(root);
    cout << endl;

    return 0;
}