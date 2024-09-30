#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
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

void preOrderTraversal(Node *root) {
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

void leftViewUsingRecursion(Node *root, int level, vector<int> &leftView) {
    if(root == NULL) {
        return;
    }

    if(level == leftView.size()) {
        // Leftview ki node mil gayi hai, store karlo
        leftView.push_back(root->data);
    }

    leftViewUsingRecursion(root->left, level + 1, leftView);
    leftViewUsingRecursion(root->right, level + 1, leftView);
}

void rightViewUsingRecursion(Node *root, int level, vector<int> &rightView) {
    if(root == NULL) {
        return;
    }

    if(level == rightView.size()) {
        // Rightview ki node mil gayi hai, store karlo
        rightView.push_back(root->data);
    }

    rightViewUsingRecursion(root->right, level + 1, rightView);
    rightViewUsingRecursion(root->left, level + 1, rightView);
}

void topView(Node *root) {
    map<int, int> hdToNode;
    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node *front = temp.first;
        int hd = temp.second;

        // If there is no entry for hd in map, then create a new entry
        if(hdToNode.find(hd) == hdToNode.end()) {
            hdToNode[hd] = front->data;
        }

        if(front->left != NULL) {
            q.push(make_pair(front->left, hd - 1));
        }

        if(front->right != NULL) {
            q.push(make_pair(front->right, hd + 1));
        }
    }

    cout << "Printing top view: " << endl;

    for(auto i: hdToNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

void bottomView(Node *root) {
    map<int, int> hdToNode;
    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node *front = temp.first;
        int hd = temp.second;

        // Overwrite nodes in map so that deeper nodes can be stored
        hdToNode[hd] = front->data;

        if(front->left != NULL) {
            q.push(make_pair(front->left, hd - 1));
        }

        if(front->right != NULL) {
            q.push(make_pair(front->right, hd + 1));
        }
    }

    cout << "Printing bottom view: " << endl;

    for(auto i: hdToNode) {
        cout << i.second << " ";
    }
    cout << endl;
}

int main() {

    Node *root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    levelOrderTraversal(root);
    int level = 0;


    vector<int> leftView;
    leftViewUsingRecursion(root, level, leftView);

    cout << "Printing left view: " << endl;
    for(int i = 0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }
    cout << endl;


    vector<int> rightView;
    rightViewUsingRecursion(root, level, rightView);

    cout << "Printing right view: " << endl;
    for(int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }
    cout << endl;


    topView(root);

    bottomView(root);


    return 0;
}