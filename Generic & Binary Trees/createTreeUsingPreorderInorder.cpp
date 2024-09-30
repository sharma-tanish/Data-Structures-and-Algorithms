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

int searchInorder(int inorder[], int size, int element) {
    for(int i = 0; i < size; i++) {
        if(inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

void createMapping(map<int, int> &valueToIndex, int inorder[], int size) {
    for(int i = 0; i < size; i++) {
        valueToIndex[inorder[i]] = i;
    }
}

Node* createTreeUsingPreorderInorder(int preorder[], int inorder[], int size, int &preorderIndex, int inorderStart, int inorderEnd, map<int, int> &valueToIndex) {
    // Base case
    if(preorderIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    // Preorder mein jis bhi index pe khade ho uske liye node create karo
    int element = preorder[preorderIndex];
    preorderIndex++;
    Node *root = new Node(element);

    // Element search karna padega inorder mein
    // int position = searchInorder(inorder, size, element);
    int position = valueToIndex[element];

    // Recursion sambhal lega
    root->left = createTreeUsingPreorderInorder(preorder, inorder, size, preorderIndex, inorderStart, position - 1, valueToIndex);
    root->right = createTreeUsingPreorderInorder(preorder, inorder, size, preorderIndex, position + 1, inorderEnd, valueToIndex);

    return root;
}

int main() {

    int preorder[] = {2, 8, 10, 6, 4, 12};
    int inorder[] = {10, 8, 6, 2, 4, 12};
    int size = 6;
    int preorderIndex = 0;
    int inorderStart = 0;
    int inorderEnd = 5;
    map<int, int> valueToIndex;
    
    createMapping(valueToIndex, inorder, size);

    Node *root = createTreeUsingPreorderInorder(preorder, inorder, size, preorderIndex, inorderStart, inorderEnd, valueToIndex);

    cout << "Printing tree: " << endl;
    levelOrderTraversal(root);

    return 0;
}