#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

typedef struct tree TREE;

class BST {
public:
    TREE* insert_into_bst(TREE*, int);
    void inorder(TREE*);
    TREE* delete_from_bst(TREE*, int);
    TREE* search_tree(TREE*, int);
};

// Function to insert a node into the BST
TREE* BST::insert_into_bst(TREE* root, int data) {
    TREE* newnode = (TREE*)malloc(sizeof(TREE));
    if (newnode == NULL) {
        cout << "Memory allocation failed" << endl;
        return root;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
        cout << "Root node inserted into tree" << endl;
        return root;
    }

    TREE* currnode = root;
    TREE* parent = NULL;

    while (currnode != NULL) {
        parent = currnode;
        if (newnode->data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }

    if (newnode->data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    cout << "Node inserted successfully" << endl;
    return root;
}

// Function for inorder traversal
void BST::inorder(TREE* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

// Function to delete a node from the BST
TREE* BST::delete_from_bst(TREE* root, int data) {
    TREE* currnode = root;
    TREE* parent = NULL;
    TREE* successor = NULL;
    TREE* p = NULL;

    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return root;
    }

    // Find the node to be deleted
    while (currnode != NULL && currnode->data != data) {
        parent = currnode;
        if (data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }
    // If data not found in the tree
    if (currnode == NULL) {
        cout << "Item not found" << endl;
        return root;
    }

    // Case 1: left subtree absent or right subtree absent
    if (currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else {
        // Case 2: Node has two subtrees
        successor = currnode->right;

        // Find the in-order successor (smallest in right subtree)
        while (successor->left != NULL) {
            successor = successor->left;
        }
        successor->left = currnode->left;
        p = currnode->right;
    }

    // If node to be deleted is root
    if (parent == NULL) {
        free(currnode);
        return p;
    }

    // Re-attach parent to the new subtree
    if (currnode == parent->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

// Function to search a node in the BST
TREE* BST::search_tree(TREE* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } else {
        if (key < root->data)
            return search_tree(root->left, key);
        else
            return search_tree(root->right, key);
    }
}

int main() {
    BST bst;
    TREE* root = NULL;
    int choice = 0;
    int data = 0;

    while (1) {
        cout << "\n ** MENU **\n";
        cout << "1. Insert into BST\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Delete from BST\n";
        cout << "4. Search Tree\n";
        cout << "0. Exit\n";
        cout << "*******\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the item to insert: ";
            cin >> data;
            root = bst.insert_into_bst(root, data);
            break;

        case 2:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Inorder traversal is...\n";
                bst.inorder(root);
                cout << endl;
            }
            break;

        case 3:
            cout << "Enter the item to be deleted: ";
            cin >> data;
            root = bst.delete_from_bst(root, data);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> data;
            if (bst.search_tree(root, data))
                cout << "Search Successful!\n";
            else
                cout << "Search Unsuccessful\n";
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
