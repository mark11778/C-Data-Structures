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
 *  inserts the nodes into the binary sreach tree
 *
 * @param root - root of the binary sreach tree
 * @param data - the data of the new node
 */
void insertNewNode(Node* &root, int data) {
    Node* node = newNode(data);
    if(root == NULL) {root = node; return;}
    else {
        if(root->data > data)
            if (root->left == NULL) {root->left = node; return;}
            else insertNewNode(root->left, data);
        else
        if (root->right == NULL) {root->right = node; return;}
        else insertNewNode(root->right, data);}

}

Node* createdRBTree(int arr[], int n) {
    Node *root = NULL;
    for(int i = 0; i < n; i++) insertNewNode(root, arr[i]);
    return root;
}

void printBST(Node* root, int space = 0, int height = 0) {
    if (root == NULL) {
        return;
    }
    space += height;

    printBST(root->right, space, height);

    cout << endl;
    for (int i = height; i < space; i++) {
        cout << " ";
    }
    cout << root->data ;

    printBST(root->left, space, height);
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}


int main() {
    int arr[] = { 7, 3, 9, 1, 5,3,7,23, 2,7,5,8,53}, n = 12;
    Node* root = createdRBTree(arr,n);
    inOrderTraversal(root);
    return 0;
}
