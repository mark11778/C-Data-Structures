#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
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

/**
 * finds the predecessor and assigns the node to be that one
 * @param node - starts as the node to be removed
 * @return the data that is stored in the predecessor node
 */
int predecessor(Node* &node) {
    if (node->left == NULL) {
       int temp = node->data;
       node = node->right;
       return temp;
    } else return predecessor(node->left);
}

/**
 * method to remove a Node, calls the predescessor if the node has a right child
 * @param root - the top of the tree
 * @param data - the int val of the Node to be removed
 */
void removeNode(Node* &root, int data) {
    if (root == NULL) return;
    if (root->data == data) {
        if(root->right == NULL) {
            root = root->left;
            return;
        } else {
            root->data = predecessor(root->right);
            return;
        }
    }
    else if (root -> data > data) removeNode(root->left, data);
    else removeNode(root->right, data);
}

/**
 * prints out the contents of the BST in an inorder traversal
 * @param root - top of the tree
 */
void inOrderTraversal(Node* root) {
    if (root == NULL)return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int test() {
    // Define test cases
    int arr1[] = { 7, 3, 9, 1, 5, 8, 23, 2, 53};
    int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr3[] = { 5, 4, 3, 2, 1};

    // Test case 1: Removing a leaf node
    Node* root1 = createdRBTree(arr1, 9);
    std::cout << "Before removing: ";
    inOrderTraversal(root1);
    removeNode(root1, 23);
    std::cout << "\nAfter removing: ";
    inOrderTraversal(root1);

    // Test case 2: Removing a node with two children
    Node* root2 = createdRBTree(arr2, 9);
    std::cout << "\nBefore removing: ";
    inOrderTraversal(root2);
    removeNode(root2, 2);
    std::cout << "\nAfter removing: ";
    inOrderTraversal(root2);

    // Test case 3: Removing the root node
    Node* root3 = createdRBTree(arr3, 5);
    std::cout << "\nBefore removing: ";
    inOrderTraversal(root3);
    removeNode(root3, 5);
    std::cout << "\nAfter removing: ";
    inOrderTraversal(root3);

    return 0;
}


int main() {
//    int arr[] = { 7, 3, 9, 1, 5,3,7,23, 2,7,5,8,53}, n = 12;
//    Node* root = createdRBTree(arr,n);
//    inOrderTraversal(root);
//    removeNode(root,7);
//    std::cout << endl;
//    inOrderTraversal(root);
    test();
    return 0;
}
