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
    int counter=0;

    TREE* insert_into_bst(TREE*, int);
    void inorder(TREE*);
    void preorder(TREE*);
    void postorder(TREE*);
    TREE* delete_from_bst(TREE*, int);

    /*1*/void in_degree_root(TREE*);
    /*2*/void out_degree_root(TREE*);
    /*3*/TREE* search_tree(TREE*,int);
    /*4*/void count_edges(TREE*);
    /*5*/int count_nodes(TREE*);
         void cinorder(TREE*);
    /*6*/TREE* delete_less_than_k(TREE*, int);
    /*7*/TREE* delete_more_than_k(TREE*, int);
    /*8*/int count_lesser_than_k(TREE*,int);
    /*9*/int count_greater_than_k(TREE*,int);
    /*10*/TREE* inorder_succesor(TREE*,int );
    /*11*/void inorder_predecessor(TREE*,int);
    /*12*/void minimum_tree(TREE*);
    /*13*/void maximum_tree(TREE*);
    /*14*/int count_external_nodes(TREE*);
    /*15*/void root_address(TREE*);
    /*16*/int search_comparisions(TREE*, int);
    /*17*/void nodes_in_level_1(TREE*);
    /*18*/int count_leaf(TREE*);
    /*19*/void tree_mem(TREE*);
    /*20*/int edges_from_root_to_max(TREE* );
    /*21*/void leaf_nodes_outdegree(TREE*);
    ///*22*/TREE* delete_duplicates(TREE*);
    /*23*/TREE* duplicate_tree(TREE* ,TREE*);
    /*24*/void comparisions_to_max(TREE*);
    /*25*/void load_into_array(TREE*,int [], int &);

    
};
void BST::load_into_array(TREE* root, int a[],int &index)
{
    load_into_array(root->left,a,index);
    index++;
    a[index]=root->data;
    load_into_array(root->right,a,index);
}
void BST::comparisions_to_max(TREE*root)
{
    TREE* curr=root;
    int c;
    while(curr->right!=NULL)
    {
        c++;
    }
    cout<<"Max element is always rightmost leaf node\n commparisions made to get to the last node = "<<c;
}
TREE* BST::duplicate_tree(TREE*root, TREE *new_root)
{
    new_root->data=root->data;
    new_root->left=root->left;
    new_root->right=root->right;

    return new_root;
}
int BST::edges_from_root_to_max(TREE* root)
{
    TREE* curr=root;
    int count=0;
    while(curr->right!=NULL)
    {
        count++;
    }
    return count;
}
int BST::count_leaf(TREE* root)
{
    int count = count_external_nodes(root)-1;
    return count;
}
int BST::search_comparisions(TREE* root, int k)
{
    int count = 1;
    TREE *curr =root;
    while(curr->data==k || (curr->right==NULL && curr->left==NULL))
    {
        count++;
        if(k > curr->data)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    return count;
}
int BST::count_external_nodes(TREE* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int count = 1;

    count = count + count_external_nodes(root->left);
    count = count + count_external_nodes(root->right);

    return count;
}

void BST::minimum_tree(TREE* root)
{
    TREE* curr=root;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    cout<<"Minimum valued element of tree = "<<curr->data<<endl;
}
void BST::maximum_tree(TREE* root)
{
    TREE* curr=root;
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    cout<<"Maximum valued element of tree = "<<curr->data<<endl;
}
int BST::count_lesser_than_k(TREE* root, int k)
{
    
    if (root == NULL) 
        return 0;
    int count = count_lesser_than_k(root->left, k);
    if (root->data < k) 
        count = count + 1 + count_lesser_than_k(root->right, k);
    return count;
    
}
int BST::count_greater_than_k(TREE* root, int k)
{
    
    if (root == NULL) 
        return 0;
    int count = count_greater_than_k(root->right, k);
    if (root->data > k) 
        count = count + 1 + count_greater_than_k(root->left, k);
    return count;
    
}
TREE* BST:: delete_less_than_k(TREE* root, int k)
{
    if(root==NULL)
        return root;
    root->left = delete_less_than_k(root->left, k);
    root->right = delete_less_than_k(root->right, k);
    if (root->data < k) 
    {
        TREE* right_subtree = root->right;
        delete root;
        return right_subtree;
    }
    return root;
}
TREE* BST::delete_more_than_k(TREE* root, int k)
{
    if(root==NULL)
        return root;
    root->left = delete_more_than_k(root->left, k);
    root->right = delete_more_than_k(root->right, k);
    if (root->data > k) 
    {
        TREE* left_subtree = root->left;
        delete root;
        return left_subtree;
    }
    return root;
}
void BST::leaf_nodes_outdegree(TREE* root)
{
    cout<<"Out degree of all leaf nodes = 0\n";
}
void BST::nodes_in_level_1(TREE* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        cout<<"nodes present in level 1 = 0\n";
        return;

    }
    else 
    {
        if(root->left==NULL || root->right == NULL)
        {
            cout<<"nodes present in level 1 = 1\n";
            return;
        }

    }
    cout<<"nodes present in level 1 = 2\n";
    return;
}
void BST::tree_mem(TREE* root)
{
    int nodes = count_nodes(root);
    double mem = sizeof(tree *)*nodes;
    cout<<"memory of tree = "<<mem;
}
void BST::root_address(TREE* root)
{
    cout<<"address of root = "<<root;
}
TREE* BST::inorder_succesor(TREE* root,int data)
{
    {
    if(root==NULL)
        return root;
    TREE* curr=root;
    TREE* succ=NULL;
    while(curr->data!=data)
    {
        if(data<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(curr->right==NULL)
        return NULL;
    succ=curr->right;
        while(succ->left!=NULL)
        {
            succ=succ->left;
        }
        return succ;
}
}

void BST::count_edges(TREE* root)
{
    int nodes = count_nodes(root);
    cout<<"Edges = "<<nodes-1;
}
void BST::cinorder(TREE *root)
{
    if (root != NULL) 
    {
        cinorder(root->left);
        counter++;
        cinorder(root->right);
    }
}
int BST::count_nodes(TREE *root)
{
    counter=0;
    cinorder(root);

    return(counter);
}
TREE* BST:: search_tree(TREE* current, int key)
{
    if(current == NULL || current->data==key)
    {
        return current;
    }
    else
    {
        if(key<current->data)
            return search_tree(current->left,key);
        else
            return search_tree(current->right,key);
    }
}

void BST::in_degree_root(TREE *root)
{
    cout<<"in degree = 0\n";

}

void BST::out_degree_root(TREE *root)
{
    int count=0;
    if(root->left!=NULL)
        count++;
    if(root->right!=NULL)
        count++;
    
    cout<<"out degree = "<<count<<endl;

}



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
        // Correct the assignment
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

// Function to perform inorder traversal
void BST::inorder(TREE* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void BST::preorder(TREE* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void BST::postorder(TREE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
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
    //If data not present in the tree
    if (currnode == NULL) {
        cout << "Item not found" << endl;
        return root;
    }

    // Case 1: left subtree absent or right subtree absent or both are present
    if (currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else {
    // Case 2: Node has two subtrees
        successor = currnode->right;
        //TREE* successorParent = currnode;

        // Find the in-order successor (smallest in right subtree)
        while (successor->left != NULL) {
            successor = successor->left;
        }
        successor->left=currnode->left;
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

int main() {
    BST bst;
    TREE* root = NULL;
    int choice = 0;
    int data = 0;

    while (1) {
        cout << "\n ** MENU **\n";
        cout << "1. Insert into BST\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Preorder traversal\n";
        cout << "4. Postorder traversal\n";
        cout << "5. Delete from BST\n";
        cout << "6. Print in-degree of root\n";
        cout << "7. Print out-degree of root\n";
        cout << "8. Search Tree\n";
        cout << "9. Count the number of edges\n";
        cout << "10. Count the number of nodes\n";
        cout << "11. Print address of root node\n";
        cout << "12. Print the inorder succesor\n";
        cout << "13. Memory taken by the tree\n";
        cout << "14. Print number of edges in level 1\n";
        cout << "15. Print outdegree of leaf nodes\n";
        cout << "16. Delete less than k\n";
        cout << "17. Delete more than k\n";
        cout << "18. Count nodes lesser than k\n";
        cout << "19. Count nodes greater than k\n";
        cout << "20. Minimum valued element of tree\n";
        cout << "21. Maximum valued element of tree\n";
        cout << "22. External roots\n";
        cout << "23. No.of comparisions for a search\n";
        cout << "24. No.of leaf nodes\n";
        cout << "25. No.of edges from root to maximum element\n";
        cout << "26. Duplicate tree\n";
        cout << "27. Comparisions to find maximum element\n";
        cout << "28. load into array\n";
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
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Preorder traversal is...\n";
                bst.preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Postorder traversal is...\n";
                bst.postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "Enter the item to be deleted: ";
            cin >> data;
            root = bst.delete_from_bst(root, data);
            break;
        case 6:
            if(root==NULL)
                cout<<"Tree is empty\n";
            else
                bst.in_degree_root(root);
            break;
        case 7:
            if(root == NULL)
                cout<<"Tree is empty\n";
            else
                bst.out_degree_root(root);
            break;
        case 8:
            int key;
            cout<<"enter value to be searched: \n";
            cin>>key;
            if(root == NULL)
                cout<<"Tree is empty\n";
            else
            {
                if(bst.search_tree(root,key))
                    cout<<"Search Sucessful!\n";
                else
                    cout<<"Search Unsuccesful\n";
            }
            break;
        case 9:
                if(root==NULL)
                cout<<"Edges = 0"<<endl;
            else
                bst.count_edges(root);
            break;
        case 10: 
            if(root==NULL)
                cout<<"nodes = 0"<<endl;
            else
                cout<<"nodes = "<<bst.count_nodes(root)<<endl;
            break;
        case 11:
            if(root==NULL)
                cout<<"Tree is empty\n";
            else
                bst.root_address(root);
            break;
        case 12:
             cout<<"Enter value:\n";
                cin>>data;
                TREE* temp;
                temp=bst.inorder_succesor(root,data);
                if(temp==root)
                    cout<<"Tree is empty\n";
                else if(temp==NULL)
                    cout<<"No successor available\n";
                else
                    cout<<"successor is: "<<temp->data<<endl;

            break;
        case 13:
        {
            if(root==NULL)
                cout<<"Memory of tree = 0"<<endl;
            else
                bst.tree_mem(root);
            break;
        }
            
        case 14:
        {
            if(root==NULL)
                cout<<"tree is empty\n";
            else
                bst.nodes_in_level_1(root);

            break;
        }
            

        case 15:
            if(root==NULL)
                cout<<"tree is empty\n";
            else
                bst.leaf_nodes_outdegree(root);


            break;
        case 16:
            if(root==NULL)
            {
                cout<<"TREE is empty\n";
                break;
            }
            int k;
            cout<<"Enter number k, to delete nodes less than k:\n";
            cin>>k;
            root=bst.delete_less_than_k(root,k);
            break;
        case 17:
            if(root==NULL)
            {
                cout<<"TREE is empty\n";
                break;
            }
            int c;
            cout<<"Enter number k, to delete nodes more than k:\n";
            cin>>c;
            root=bst.delete_more_than_k(root,c);
            break;
        case 18:
            int k2,count;
            cout<<"Enter number k, to count nodes less than k:\n";
            cin>>k2;
            count=bst.count_lesser_than_k(root,k2);
            cout<<"Nodes lesser than "<<k2<<" = "<<count<<endl;
            break;
        case 19:
            int k3,count3;
            cout<<"Enter number k, to count nodes greter than k:\n";
            cin>>k3;
            count3=bst.count_greater_than_k(root,k3);
            cout<<"Nodes greater than "<<k3<<" = "<<count3<<endl;
            break;
        case 20:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            bst.minimum_tree(root);
            break;
        case 21:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            bst.maximum_tree(root);
            break;
        case 22:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            int count4;
            count4 = bst.count_external_nodes(root);
            cout<<"No. of External nodes(root + leaf nodes) = "<<count4;
            break;
        case 23:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            int c1,a;
            cout<<"enter a search element to know how many search comparisions:\n";
            cin>>a;
            c1 =bst.search_comparisions(root,a);
            cout<<"no.of comparisions = "<<c1;
            break;
        case 24:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            cout<<"No.of leaf nodes in the tree = "<<bst.count_leaf(root);
            break;
        case 25:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            cout<<"No. of edges from root to maximum element = "<<bst.edges_from_root_to_max(root);
            break;
        case 26:
            TREE* new_root;
            new_root = bst.duplicate_tree(root,new_root);
            cout<<"Tree Successfully DUplicated\n";
            break;
        case 27:
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }
            bst.comparisions_to_max(root);
            break;
        case 28:
        {
            if(root==NULL)
            {
                cout<<"Tree is empty\n";
                break;
            }

            int x=bst.count_nodes(root);
            int array[20];
            int index=0;
            bst.load_into_array(root,array, index);
            cout<<"BST loaded into an array\n";
            for(int l=0;l<x;l++)
            {
                cout<<array[l]<<" ";
            }
            cout<<endl;

        } 
            break;
        case 0:
            cout << "Exiting...\n";
            exit(0);
            break;
        default:
            cout << "Error: Invalid choice\n";
        }
    }
    return 0;
}