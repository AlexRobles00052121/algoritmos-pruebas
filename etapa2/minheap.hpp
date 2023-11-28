#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode *parent;
    TreeNode *leftChild;
    TreeNode *rightChild;
    string symbol;
    double probability;

    TreeNode(string s, double p) : parent(nullptr), leftChild(nullptr), rightChild(nullptr), symbol(s), probability(p) {}
};

class SymbolPriorityQueue
{
private:
    TreeNode *root;
    int size;

    void swap(TreeNode *a, TreeNode *b);
    void heapify(TreeNode *node);
    void heapifyUp(TreeNode *node);
    void heapifyDown(TreeNode *node);

public:
    SymbolPriorityQueue() : root(nullptr), size(0) {}

    // Funciones principales
    void insert(TreeNode *node);
    TreeNode *extractMin();
    TreeNode *peek();
    int getSize();
    bool isEmpty();
};

// swap function: swaps the values of two nodes
void SymbolPriorityQueue::swap(TreeNode *a, TreeNode *b)
{
    string tempSymbol = a->symbol;
    double tempProbability = a->probability;
    a->symbol = b->symbol;
    a->probability = b->probability;
    b->symbol = tempSymbol;
    b->probability = tempProbability;
}

// heapify function: heapifies the subtree with root node
void SymbolPriorityQueue::heapify(TreeNode *node)
{
    // Base case
    if (node == nullptr)
    {
        return;
    }

    // Initialize min as root and initialize left and right children as min
    TreeNode *min = node;

    // If left child is smaller than root, update min
    if (node->leftChild != nullptr && node->leftChild->probability < min->probability)
    {
        min = node->leftChild;
    }

    // If right child is smaller than min so far, update min
    if (node->rightChild != nullptr && node->rightChild->probability < min->probability)
    {
        min = node->rightChild;
    }

    // If min is not root, swap it with root
    if (min != node)
    {
        swap(node, min);
        heapify(min); // Recursively heapify the affected sub-tree
    }
}

// heapifyUp function: heapifies the subtree with root node
void SymbolPriorityQueue::heapifyUp(TreeNode *node)
{
    // Base case
    if (node == nullptr)
    {
        return;
    }

    // If node is not root and its parent is greater than it, swap
    if (node->parent != nullptr && node->parent->probability > node->probability)
    {
        swap(node, node->parent);
        heapifyUp(node->parent);
    }
}

// heapifyDown function: heapifies the subtree with root node
void SymbolPriorityQueue::heapifyDown(TreeNode *node)
{
    // Base case
    if (node == nullptr)
    {
        return;
    }

    // Initialize min as root and initialize left and right children as min
    TreeNode *min = node;

    // If left child is smaller than root, update min
    if (node->leftChild != nullptr && node->leftChild->probability < min->probability)
    {
        min = node->leftChild;
    }

    // If right child is smaller than min so far, update min
    if (node->rightChild != nullptr && node->rightChild->probability < min->probability)
    {
        min = node->rightChild;
    }

    // If min is not root, swap it with root
    if (min != node)
    {
        swap(node, min);
        heapifyDown(min); // Recursively heapify the affected sub-tree
    }
}

// insert function: inserts a node into the priority queue
void SymbolPriorityQueue::insert(TreeNode *node)
{
    // If the queue is empty, insert the node as root
    if (root == nullptr)
    {
        root = node;
        size++;
        return;
    }

    // If the queue is not empty, insert the node as the last node
    TreeNode *temp = root;
    while (temp->leftChild != nullptr && temp->rightChild != nullptr)
    {
        temp = temp->leftChild;
    }

    // Insert the node as the left child of the last node
    if (temp->leftChild == nullptr)
    {
        temp->leftChild = node;
    }
    // Insert the node as the right child of the last node
    else
    {
        temp->rightChild = node;
    }

    // Update the parent of the node
    node->parent = temp;

    // Heapify up the node
    heapifyUp(node);

    // Increase the size of the queue
    size++;
}

// extractMin function: extracts the node with minimum probability
TreeNode *SymbolPriorityQueue::extractMin()
{
    // If the queue is empty, return nullptr
    if (root == nullptr)
    {
        return nullptr;
    }

    // If the queue has only one node, return the root
    if (root->leftChild == nullptr && root->rightChild == nullptr)
    {
        TreeNode *temp = root;
        root = nullptr;
        size--;
        return temp;
    }

    // If the queue has more than one node, extract the root
    TreeNode *temp = root;
    TreeNode *lastNode = nullptr;

    // Find the last node in the tree
    while (temp->leftChild != nullptr || temp->rightChild != nullptr)
    {
        if (temp->rightChild != nullptr)
        {
            temp = temp->rightChild;
        }
        else
        {
            temp = temp->leftChild;
        }
    }

    // Swap the root with the last node
    lastNode = temp;
    swap(root, lastNode);

    // Update the parent's child pointer
    if (lastNode->parent != nullptr && lastNode->parent->leftChild == lastNode)
    {
        lastNode->parent->leftChild = nullptr;
    }
    else if (lastNode->parent != nullptr && lastNode->parent->rightChild == lastNode)
    {
        lastNode->parent->rightChild = nullptr;
    }

    // Heapify down the root
    heapifyDown(root);

    size--;
    return lastNode;
}

// peek function: returns the node with minimum probability
TreeNode *SymbolPriorityQueue::peek()
{
    // If the queue is empty, return nullptr
    if (root == nullptr)
    {
        return nullptr;
    }

    // If the queue is not empty, return the root
    return root;
}

// getSize function: returns the size of the queue
int SymbolPriorityQueue::getSize()
{
    return size;
}

// isEmpty function: returns true if the queue is empty
bool SymbolPriorityQueue::isEmpty()
{
    return size == 0;
}

#endif