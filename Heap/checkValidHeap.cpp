#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};    

pair<int, bool> solve(Node *root) {
    // Base cases for NULL node and leaf node
    if (root == NULL) {
        return {INT_MAX, true};
    }
    if (root->left == NULL && root->right == NULL) {
        return {root->data, true};
    }
    auto leftAns = solve(root->left);
    auto rightAns = solve(root->right);
    // Checking if the current node is greater than its children
    if (root->data >= leftAns.first && root->data >= rightAns.first && leftAns.second && rightAns.second) {
        return {root->data, true};
    }
    else {
        return {max(root->data, max(leftAns.first, rightAns.first)), false};
    }
}