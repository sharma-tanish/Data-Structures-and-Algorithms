#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char value) {
        this->value = value;
        for(int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// Insertion
void insertWord(TrieNode* root, string word) {
    // Base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        // Child present
        child = root->children[index];
    }
    else {
        // Child absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

// Searching
bool searchWord(TrieNode* root, string word) {
    // Base case
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        // Child present
        child = root->children[index];
    }
    else {
        // Child absent
        return false;
    }

    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

// Deletion
void deleteWord(TrieNode* &root, string word) {
    // Base case
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        // Child present
        child = root->children[index];
    }
    else {
        // Child absent
        return;
    }

    deleteWord(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string> &ans, string &input, string &prefix) {
    if(root->isTerminal == true) {
        ans.push_back(prefix + input);
    }

    for(char ch = 'a'; ch <= 'z'; ch++) {
        int index = ch - 'a';
        TrieNode* next = root->children[index];
        if(next != NULL) {
            input.push_back(ch);
            storeString(next, ans, input, prefix);
            input.pop_back();
        }
    }
}

// Traversal to last character of input string
void findPrefixString(TrieNode* root, string input, vector<string> &ans, string &prefix) {
    if(input.length() == 0) {
        TrieNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return;
    }

    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string> > getSuggestions(TrieNode* root, string input) {
    vector<vector<string> > output;
    TrieNode* prev = root;
    string inputhelper = "";

    for(int i = 0; i < input.length(); i++) {
        char lastchar = input[i];
        int index = lastchar - 'a';
        TrieNode* curr = prev->children[index];
        if(curr != NULL) {
            vector<string> nicheKaAns;
            inputhelper.push_back(lastchar);
            string dummy = "";
            storeString(curr, nicheKaAns, inputhelper, dummy);
            output.push_back(nicheKaAns);
            prev = curr;
        }
        else {
            break;
        }
    }
    return output;
}

int main() {
    TrieNode* root = new TrieNode('-');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    // cout << searchWord(root, "lover") << endl;

    // deleteWord(root, "lover");
    // cout << searchWord(root, "lover") << endl;

    // string input = "c";
    // string prefix =  input;
    // vector<string> ans;

    // findPrefixString(root, input, ans, prefix);

    // for(auto i: ans) {
    //     cout << i << endl;
    // }

    vector<vector<string> > output = getSuggestions(root, "loa");
    for(int i = 0; i < output.size(); i++) {
        cout << i << ": ";
        for(auto str: output[i]) {
            cout << str << ", ";
        }
        cout << endl;
    }
    return 0;
}