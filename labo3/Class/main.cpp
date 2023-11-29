#include <iostream>
using namespace std;

#include "reader.hpp"
#include "bst.hpp"

// Function to display the tree in inorder
void display_inorder(BinarySearchTree &BST)
{
    cout << "Inorder: \n";
    BST.Display(1); // Display the tree in inorder traversal
    cout << "\n \n";
}

// Function to display the tree in preorder
void display_preorder(BinarySearchTree &BST)
{
    cout << "Preorder: \n";
    BST.Display(2); // Display the tree in preorder traversal
    cout << "\n \n";
}

// Function to display the tree in postorder
void display_postorder(BinarySearchTree &BST)
{
    cout << "Postorder: \n";
    BST.Display(3); // Display the tree in postorder traversal
    cout << "\n \n";
}

// Function to display the minimum node
void display_minimum(BinarySearchTree &BST)
{
    cout << "MIN: \n";
    Node *minNode = BST.Minimum(NULL); // Find the node with the minimum value
    cout << minNode->data.getCode() << "\t" << minNode->data.getBudget() << endl;
    cout << "\n \n";
}

// Function to display the maximum node
void display_maximum(BinarySearchTree &BST)
{
    cout << "MAX: \n";
    Node *maxNode = BST.Maximum(NULL); // Find the node with the maximum value
    cout << maxNode->data.getCode() << "\t" << maxNode->data.getBudget() << endl;
    cout << "\n \n";
}

// Function to search for a node
void display_search(BinarySearchTree &BST, const Battalion &example)
{
    cout << "Tree Search: \n";
    Node *node = BST.TreeSearch(example, BST.getRoot()); // Search for a node with the given data
    cout << node->data.getCode() << "\t" << node->data.getId() << "\t" << node->data.getManpower() << "\t" << node->data.getArmoredEquipment() << "\t" << node->data.getBudget() << endl;
    cout << "\n \n";
}

// Function to search for a node iteratively
void display_iterative_search(BinarySearchTree &BST, const Battalion &example)
{
    cout << "Iterative Tree Search: \n";
    Node *nodeI = BST.IterativeTreeSearch(example, BST.getRoot()); // Search for a node iteratively with the given data
    cout << nodeI->data.getCode() << "\t" << nodeI->data.getId() << "\t" << nodeI->data.getManpower() << "\t" << nodeI->data.getArmoredEquipment() << "\t" << nodeI->data.getBudget() << endl;
    cout << "\n \n";
}

// Function to insert a new node
void insert_node(BinarySearchTree &BST, const Battalion &insert)
{
    cout << "Insert new: \n";
    BST.Insert(insert); // Insert a new node with the given data
    cout << "Check insertion" << endl;
    display_inorder(BST); // Display the tree after insertion
}

// Function to delete a node
void delete_node(BinarySearchTree &BST, const Battalion &insert)
{
    cout << "Delete: \n";
    BST.Delete(insert); // Delete a node with the given data
    cout << "Check elimination" << endl;
    display_inorder(BST); // Display the tree after deletion
}

// Main function xd
int main(){
    
    Battalion data[1000];
    load_data(data);

    BinarySearchTree BST(data, 10);

    display_inorder(BST);
    display_preorder(BST);
    display_postorder(BST);
    display_minimum(BST);
    display_maximum(BST);

    Battalion example = Battalion("Victor", 190, 380, 66, 33500.97);
    display_search(BST, example);
    display_iterative_search(BST, example);

    Battalion insert = Battalion("Fabios", 8923804, 929358025, 84015, 90505092.849);
    insert_node(BST, insert);
    delete_node(BST, insert);


    return 0;
}