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

Node* createTreeUsingPreorderInorder(int postorder[], int inorder[], int size, int &postorderIndex, int inorderStart, int inorderEnd, map<int, int> &valueToIndex) {
    // Base case
    if(postorderIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // Preorder mein jis bhi index pe khade ho uske liye node create karo
    int element = postorder[postorderIndex];
    postorderIndex--;
    Node *root = new Node(element);

    // Element search karna padega inorder mein
    // int position = searchInorder(inorder, size, element);
    int position = valueToIndex[element];

    // Recursion sambhal lega
    // Right ki call pehle lagegi
    root->right = createTreeUsingPreorderInorder(postorder, inorder, size, postorderIndex, position + 1, inorderEnd, valueToIndex);
    root->left = createTreeUsingPreorderInorder(postorder, inorder, size, postorderIndex, inorderStart, position - 1, valueToIndex);

    return root;
}

int main() {

    int postorder[] = {8, 6, 14, 4, 10, 2};
    int inorder[] = {8, 14, 6, 2, 10, 4}; 
    int size = 6;
    int postorderIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    map<int, int> valueToIndex;
    
    createMapping(valueToIndex, inorder, size);

    Node *root = createTreeUsingPreorderInorder(postorder, inorder, size, postorderIndex, inorderStart, inorderEnd, valueToIndex);

    cout << "Printing tree: " << endl;
    levelOrderTraversal(root);

    return 0;
}