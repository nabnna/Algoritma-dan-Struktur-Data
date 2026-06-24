#include <iostream>
#include <string>
#include <vector>
#include "RedBlackTree.h"

using namespace std;

void traversePreorder(const RedBlackTree::Node* node) {
    if (node->isNil) return; 
    cout << " " << node->key;
    traversePreorder(node->left);
    traversePreorder(node->right);
}

void traverseInorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    traverseInorder(node->left);
    cout << " " << node->key;
    traverseInorder(node->right);
}

void traversePostorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    traversePostorder(node->left);
    traversePostorder(node->right);
    cout << " " << node->key;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    RedBlackTree rbt;
    
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q = 0;
    vector<string> queryList;

    if (cin >> Q) {
        for (int i = 0; i < Q; i++) {
            string query;
            cin >> query;
            queryList.push_back(query);
        }
    }
    
    if (rbt.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0; 
    }

    for (int i = 0; i < Q; i++) {
        string query = queryList[i];

        if (query == "PREORDER" || query == "ALL") {
            cout << "[Preorder] :";
            traversePreorder(rbt.root());
            cout << "\n";
        }
        if (query == "INORDER" || query == "ALL") {
            cout << "[Inorder] :";
            traverseInorder(rbt.root());
            cout << "\n";
        }
        if (query == "POSTORDER" || query == "ALL") {
            cout << "[Postorder] :";
            traversePostorder(rbt.root());
            cout << "\n";
        }
    }

    return 0;
}