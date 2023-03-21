#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    double data;
};

/**
 * creates a Node with given data as an input
 *
 * @param data - integer
 * @return created node
 */
struct Node* newNode(int data) {
    Node* node = new Node;
    node->data=data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 *  recursive helper class for insert
 * @param current - current node being compared to
 * @param adding - the new node that is being added
 */
void insertHelper(Node*** current, Node *adding) {
    if(**current->data > adding->data)
        if (**current->left == NULL) {**current->left = adding; return;}
        else insertHelper(current->left, adding);
    else
    if (current->right == NULL) {current->right = adding; return;}
    else insertHelper(current->right, adding);
}

/**
 *  inserts the nodes into the binary sreach tree
 *
 * @param root - root of the binary sreach tree
 * @param data - the data of the new node
 */
void insertNewNode(Node** root, int data) {
    Node* node = newNode(data);
    if(*root == NULL) {*root = node; return;}
    else {insertHelper(&root, node); return;}

}

Node* createdRBTree(int arr[], int n) {
    Node *root = NULL;
    for(int i = 0; i < n; i++) insertNewNode(&root, arr[i]);
    return root;
}

void printRBTree(Node* root) {
    while(root != NULL) {
        cout << root -> data <<" -> ";
        root = root -> right;
    }
    cout<< "NULL" << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5}, n = 5;
    Node* root = createdRBTree(arr,n);
    std::cout << root->data << endl;
    printRBTree(root);
    return 0;
}
