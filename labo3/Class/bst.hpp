#include "object.hpp"

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

using namespace std;

struct Node{
    Battalion data;
    Node *left;
    Node *right;
    Node *parent;
};

// Enumeration to represent the position of the node with respect to the parent
enum position
{
    ROOT,
    LEFT,
    RIGHT
};

// Class to represent a binary search tree
class BinarySearchTree{
    private:
        Node *root;
        int _size;

        void Inorder(Node *node);
        void Preorder(Node *node);
        void Postorder(Node *node);

        void Transplant(Node *u, Node *v);
        Node *NewNode(Battalion data); // Create a new node with given Battalion data

    public:
        BinarySearchTree();
        BinarySearchTree(Battalion *data, int size);

        //getter
        int size();

        // Queries
        Node *Minimum(Node *node);                            // returns the minimum value in the tree
        Node *Maximum(Node *node);                                    // returns the maximum value in the tre                            
        
        Node *Successor(Battalion data);
        Node *Predecessor(Battalion data);
        Node *TreeSearch(Battalion data, Node *pointer);          // returns the node with the given data
        Node *IterativeTreeSearch(Battalion data, Node *pointer); // returns the node with the given data in a non recursive way
        void Display(int order);
        Node *getRoot();

        void Insert(Battalion data);
        void Delete(Battalion data);
};

// Default constructor for BinarySearchTree
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

// Getter function to return the root of the tree
Node *BinarySearchTree::getRoot()
{
    return root;
}

// Constructor with initial data xd
BinarySearchTree::BinarySearchTree(Battalion *data, int size)
{
    root = NULL;
    _size = size;
    for (int i = 0; i < _size; ++i)
    {
        Insert(data[i]);
    }
}

// Public method to return the size of the tree
int BinarySearchTree::size()
{
    return _size;
}

// In-order traversal of the tree
void BinarySearchTree::Inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    Inorder(node->left);
    // Printing node data in a tabular format
    cout << node->data.getCode() << "\t$" << node->data.getId() << "\t$" << node->data.getManpower() << "\t$" << node->data.getArmoredEquipment() << "\t$" << node->data.getBudget() << "\n";
    Inorder(node->right);
}

// Pre-order traversal of the tree
void BinarySearchTree::Preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    // Printing node data in a tabular format
    cout << node->data.getCode() << "\t$" << node->data.getId() << "\t$" << node->data.getManpower() << "\t$" << node->data.getArmoredEquipment() << "\t$" << node->data.getBudget() << "\n";
    Preorder(node->left);
    Preorder(node->right);
}

// Post-order traversal of the tree
void BinarySearchTree::Postorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    // Printing node data in a tabular format
    cout << node->data.getCode() << "\t$" << node->data.getId() << "\t$" << node->data.getManpower() << "\t$" << node->data.getArmoredEquipment() << "\t$" << node->data.getBudget() << "\n";
}

// Create a new node with given Battalion data
Node *BinarySearchTree::NewNode(Battalion data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to check the position of a node in relation to its parent
position check_position(Node *node)
{
    if (node->parent == NULL)
    {
        return ROOT;
    }
    else if (node->parent->left == node)
    {
        return LEFT;
    }
    else
    {
        return RIGHT;
    }
}

// Function to replace a node in the tree with another node
void BinarySearchTree::Transplant(Node *u, Node *v)
{
    switch (check_position(u))
    {
    case ROOT:
        root = v;
        break;
    case LEFT:
        u->parent->left = v;
        break;
    case RIGHT:
        u->parent->right = v;
        break;
    }
    if (v != nullptr || v != NULL)
    {
        v->parent = u->parent;
    }
}

// Find and return the node with the minimum value in the tree
Node *BinarySearchTree::Minimum(Node *node)
{
    if (node == NULL)
    {
        node = root;
    }
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// Find and return the node with the maximum value in the tree
Node *BinarySearchTree::Maximum(Node *node)
{
    if (node == NULL)
    {
        node = root;
    }
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

// Find and return the predecessor node of a node with the given Battalion data
Node *BinarySearchTree::Predecessor(Battalion data)
{
    Node *node = TreeSearch(data, root);
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left != NULL)
    {
        return Maximum(node->left);
    }
    else
    {
        Node *pre = node->parent;
        while (pre != NULL && node == pre->left)
        {
            node = pre;
            pre = pre->parent;
        }
        return pre;
    }
}

// Find and return the successor node of a node with the given Battalion data
Node *BinarySearchTree::Successor(Battalion data)
{
    Node *node = TreeSearch(data, root);
    if (node == NULL)
    {
        return NULL;
    }
    if (node->right != NULL)
    {
        return Minimum(node->right);
    }
    else
    {
        Node *suc = node->parent;
        while (suc != NULL && node == suc->right)
        {
            node = suc;
            suc = suc->parent;
        }
        return suc;
    }
}

// Function to validate if a node's data matches a given Battalion data
bool validation(Node *node, Battalion data)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data.getCode() == data.getCode() && node->data.getId() == data.getId() && node->data.getManpower() == data.getManpower() && node->data.getArmoredEquipment() == data.getArmoredEquipment() && node->data.getBudget() == data.getBudget())
    {
        return true;
    }
    return false;
}

// Recursive tree search function
Node *BinarySearchTree::TreeSearch(Battalion data, Node *pointer)
{
    if (pointer == NULL || validation(pointer, data))
    {
        return pointer;
    }
    else if (data.getBudget() > pointer->data.getBudget())
    {
        return TreeSearch(data, pointer->right);
    }
    else
    {
        return TreeSearch(data, pointer->left);
    }
}

// Iterative tree search function
Node *BinarySearchTree::IterativeTreeSearch(Battalion data, Node *pointer)
{
    while (pointer != NULL)
    {
        if (validation(pointer, data))
        {
            return pointer;
        }
        else if (pointer->data.getBudget() > data.getBudget())
        {
            pointer = pointer->left;
        }
        else
        {
            pointer = pointer->right;
        }
    }
    return NULL;
}

// Display the tree in a specific order (in-order, pre-order, or post-order)
void BinarySearchTree::Display(int order)
{
    switch (order)
    {
    case 1:
        cout << "Inorder tree: \n";
        cout << "code \t id   manpower  equipment  budget \n";
        Inorder(root);
        break;
    case 2:
        cout << "Preorder tree: \n";
        Preorder(root);
        break;
    case 3:
        cout << "Inorder tree: \n";
        Postorder(root);
        break;
    default:
        cout << "Invalid option: " << order << endl;
        break;
    }
}

// Insert a new node with the given Battalion data into the binary search tree
void BinarySearchTree::Insert(Battalion data)
{
    Node *newNode = NewNode(data);
    Node *aux = NULL;
    Node *root_aux = root;
    while (root_aux != NULL)
    {
        aux = root_aux;
        if (data.getBudget() < root_aux->data.getBudget())
        {
            root_aux = root_aux->left;
        }
        else
        {
            root_aux = root_aux->right;
        }
    }
    newNode->parent = aux;
    if (aux == NULL)
    {
        root = newNode;
    }
    else if (data.getBudget() < aux->data.getBudget())
    {
        aux->left = newNode;
    }
    else
    {
        aux->right = newNode;
    }
}

// Delete a node with the given Battalion data from the binary search tree
void BinarySearchTree::Delete(Battalion data)
{
    Node *root_aux = root;
    Node *data_aux = TreeSearch(data, root);
    if (data_aux == NULL)
    {
        return;
    }
    if (data_aux->left == NULL)
    {
        Transplant(data_aux, data_aux->right);
    }
    else if (data_aux->right == NULL)
    {
        Transplant(data_aux, data_aux->left);
    }
    else
    {
        Node *minimum = Minimum(data_aux->right);
        if (minimum != data_aux->right)
        {
            Transplant(minimum, minimum->right);
            minimum->right = data_aux->right;
            minimum->right->parent = minimum->right;
        }
        Transplant(data_aux, minimum);
        minimum->left = data_aux->left;
        minimum->left->parent = minimum;
    }
}

#endif