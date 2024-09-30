#include <iostream>
#include <queue>

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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    // Not the first node
    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    }
    else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    // NLR
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    // LNR
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    // LRN
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int minValue(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;

    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;

    while(temp->right) {
        temp = temp->right;
    }

    return temp->data;
}

bool searchInBST(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    if(root->data == target) {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if(target < root->data) {
        leftAns = searchInBST(root->left, target);
    }
    else { 
        rightAns = searchInBST(root->right, target);
    }
    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target) {
    if(root == NULL) {
        return NULL;
    }
    // Find target
    // Delete target
    if(root->data == target) {
        // Do deletion
        // 4 cases

        // Case 1
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2
        else if(root->left != NULL && root->right == NULL) {
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        // Case 3
        else if(root->left == NULL && root->right != NULL) {
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        // Case 4: root->left != NULL && root->right != NULL
        else {
            // Find max value in left subtree OR find min value in right subtree
            int maxi = maxValue(root->left);
            // Replacement
            root->data = maxi;
            // Delete maxi from subtree and attach changed subtree to left of root
            root->left = deleteFromBST(root->left, maxi);
            return root;
        }
    }
    else if(target < root->data) {
        root->left = deleteFromBST(root->left, target);
    }
    else {
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

int main() {

    Node* root = NULL;
    createBST(root);
    // 50 30 60 25 40 70 80 55 -1

    cout << "Level order taversal: " << endl;
    levelOrderTraversal(root);

    cout << "Preorder traversal: " << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: " << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: " << endl;
    postorder(root);
    cout << endl;

    cout << "Minimum value: " << minValue(root) << endl;
    cout << "Maximum value: " << maxValue(root) << endl;

    // int target;
    // cout << "Enter target: ";
    // cin >> target;
    // while(target != -1) { 
    //     int ans = searchInBST(root, target);
    //     if(ans == true) {
    //         cout << "Found" << endl;
    //     }
    //     else {
    //         cout << "Not found" << endl;
    //     }
    //     cout << "Enter target: ";
    //     cin >> target;
    // }
    
    int target;
    cout << "Enter target: ";
    cin >> target;
    while(target != -1) {
        root = deleteFromBST(root, target);
        levelOrderTraversal(root);
        cout << "Enter target: ";
        cin >> target;
    }

    return 0;
}