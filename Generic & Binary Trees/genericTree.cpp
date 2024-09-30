#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    int children_count;
    Node** children;

    Node(int data) {
        this->data = data;
        this->children_count = 0;
        this->children = NULL;
    }
};

Node* createTree() {
    int data, count;
    cout << "Enter root data: ";
    cin >> data;
    cout << "Enter children count for " << data << "node: ";
    cin >> count;

    Node* root = new Node(data);
    root->children_count = count;
    root->children = new Node*[count]; // Array to store links to children

    // Linking node to its children
    for(int i = 0; i < count; i++) {
        root->children[i] = createTree();
    }

    return root;
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
            for(int i = 0; i < front->children_count; i++) {
                if(front->children[i]) {
                    q.push(front->children[i]);
                }
            }
        }
    }
}

int main() {
    
    Node* root = createTree();
    levelOrderTraversal(root);

    return 0;
}