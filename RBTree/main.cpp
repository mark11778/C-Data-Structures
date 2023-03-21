#include <iostream>

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
void insertHelper(Node *current, Node *adding) {
    if(current->data > adding->data)
        if (current->left == NULL) current->left = adding;
        else insertHelper(current->left, adding);
    else
    if (current->right == NULL) current->right = adding;
    else insertHelper(current->right, adding);
}

/**
 *  inserts the nodes into the binary sreach tree
 *
 * @param root - root of the binary sreach tree
 * @param data - the data of the new node
 */
void insertNewNode(Node* root, int data) {
    Node* node = newNode(data);
    if(root == NULL) root = node;
    else insertHelper(root, node);

}



int main() {

    return 0;
}
