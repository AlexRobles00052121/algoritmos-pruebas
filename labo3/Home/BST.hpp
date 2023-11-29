#ifndef BST_HPP
#define BST_HPP

#include <string>
#include <vector>

using namespace std;

// Class representing a node in the binary search tree
class TreeNode
{
public:
    TreeNode(string val);

    string data;
    TreeNode *left;
    TreeNode *right;
};

// Class representing a Binary Search Tree
class BinarySearchTree
{
private:
    TreeNode *root;

    // Helper function to insert a node with given data into the tree
    void insert(TreeNode *&node, const string &data);

    // Helper function for autocomplete starting from a given node
    void autocomplete(TreeNode *node, const string &prefix, vector<string> &suggestions);

public:
    BinarySearchTree();

    // Get the root of the tree
    TreeNode *getRoot();

    // Insert a node with given data into the tree
    void insert(const string &data);

    // Perform autocomplete based on a given prefix
    vector<string> autocomplete(const string &prefix);

    // Perform in-order traversal of the tree and store the result in a vector
    void inorder(TreeNode *node, vector<string> &result);
};

// Constructor for TreeNode class
TreeNode::TreeNode(string val)
{
    data = val;
    left = nullptr;
    right = nullptr;
}

// Function to get the root of the tree
TreeNode *BinarySearchTree::getRoot()
{
    return root;
}

// Constructor for BinarySearchTree class
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

// Recursive function to insert a node with given data into the tree
void BinarySearchTree::insert(TreeNode *&node, const string &data)
{
    if (node == nullptr)
    {
        node = new TreeNode(data);
        return;
    }

    if (data < node->data)
    {
        insert(node->left, data);
    }
    else
    {
        insert(node->right, data);
    }
}

// Recursive function for autocomplete starting from a given node
void BinarySearchTree::autocomplete(TreeNode *node, const string &prefix, vector<string> &suggestions)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->data.find(prefix) == 0)
    {
        suggestions.push_back(node->data);
    }

    if (prefix < node->data)
    {
        autocomplete(node->left, prefix, suggestions);
    }
    autocomplete(node->right, prefix, suggestions);
}

// Public function to insert a node with given data into the tree
void BinarySearchTree::insert(const string &data)
{
    insert(root, data);
}

// Public function to perform autocomplete based on a given prefix
vector<string> BinarySearchTree::autocomplete(const string &prefix)
{
    vector<string> suggestions;
    autocomplete(root, prefix, suggestions);
    return suggestions;
}

// Public function to perform in-order traversal of the tree and store the result in a vector
void BinarySearchTree::inorder(TreeNode *node, vector<string> &result)
{
    if (node == nullptr)
    {
        return;
    }

    inorder(node->left, result);
    result.push_back(node->data);
    inorder(node->right, result);
}

#endif
