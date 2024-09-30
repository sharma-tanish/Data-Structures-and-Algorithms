#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void maxHeapUsingPostorder(Node *root, vector<int> v, int &index)
{
    if (root == NULL)
    {
        return;
    }
    // LRN
    maxHeapUsingPostorder(root->left, v, index);
    maxHeapUsingPostorder(root->right, v, index);
    root->data = v[index];
    index++;
}

void convertToMaxHeapUtil(Node *root)
{
    // Store inorder in a vector
    vector<int> v;
    inorder(root, v);
    // Fill tree using postorder
    int index = 0;
    maxHeapUsingPostorder(root, v, index);
}