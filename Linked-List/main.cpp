#include <bits/stdc++.h>
using namespace std;

/**
 * node class
 */
struct Node {
    int data;
    Node* next;
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
    node->next = NULL;
    return node;
}

/**
 *  inserts all the nodes into the linkedlist
 *
 * @param root - root of the linked list
 * @param data - the data of the new node
 */
void insertNewNode(Node** root, int data) {
    Node* node = newNode(data);
    Node* ptr;
    if(*root == NULL) {
        *root = node;
    }
    else {
        ptr = *root;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next=node;
    }
}

/**
 * creates the linkedlist
 *
 * @param arr - array if integers
 * @param n - number of items in the linkedlist
 * @return the root of the linkedlist
 */
Node* createLinkedList(int arr[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        insertNewNode(&root,arr[i]);
    }
    return root;
}

/**
 *  prints out the length of the Linked list
 * @param root
 */
void printLinkedList(Node* root) {
    while(root != NULL) {
        cout << root -> data <<" -> ";
        root = root -> next;
    }
    cout<< "NULL" << endl;
}
/**
 *
 * @param root
 * @return length of the linked list
 */
int lengthLinkedList(Node* root) {
    int counter = 0;
    while(root != NULL) {
        counter++;
        root = root -> next;
    }
    return counter;
}

Node* removeLinkedList(Node*& root, int removal) {
    if (root->data == removal) {
        Node* temp = root->next;
        delete root;
        return temp;
    }
    Node *prev = NULL;
    Node *temp = root;
    while(root != NULL) {
        if (temp->data == removal) {
            prev->next = temp->next;
            return root;
        }
        prev = temp;
        temp = temp->next;
    }
    return NULL;
}


int main() {
    int arr[] = { 1, 2, 3, 4, 5 }, n = 5;
    Node* root = createLinkedList(arr, n);
    printLinkedList(root);
    std::cout << lengthLinkedList(root) << endl;
    printLinkedList(removeLinkedList(root,5));

    return 0;
}
