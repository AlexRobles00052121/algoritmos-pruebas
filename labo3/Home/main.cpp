#include <iostream>
#include <sstream>
#include "BST.hpp"

using namespace std;

int main()
{
    // Create an instance of BinarySearchTree
    BinarySearchTree bst;

    // Sample sentence to insert into the tree
    string sentence = "Elephant Elegant House Home Symphony Guitar Glitter Gazebo Enigma Eclipse Aviation Avengers Eclair November Nectar Harvest Hilarious Harmony";
    istringstream iss(sentence);
    string word;

    // Insert words from the sentence into the tree
    while (iss >> word)
    {
        bst.insert(word);
    }

    int choice = 0;
    string searchPrefix;

    while (true)
    {
        // Display menu options
        cout << "====================" << endl;
        cout << "Menu:\n";
        cout << "1. Insert a new word\n";
        cout << "2. Search words with a prefix\n";
        cout << "3. Show the tree InOrder \n";
        cout << "4. Exit\n";
        cout << "Choose an option: \n";
        cout << "====================" << endl;

        // Get user choice
        cin >> choice;

        vector<string> inOrderResult;
        vector<string> suggestions;

        switch (choice)
        {
        case 1:
            // Insert a new word
            cout << "Insert a new word: ";
            cin >> word;
            bst.insert(word);
            break;

        case 2:
            // Search for words with a given prefix
            cout << "Enter the prefix to search: ";
            cin >> searchPrefix;
            suggestions = bst.autocomplete(searchPrefix);
            cout << "Words with prefix: '" << searchPrefix << "': ";
            for (const string &word : suggestions)
            {
                cout << "\n"
                     << word;
            }
            cout << "\n";
            break;

        case 3:
            // Display the tree in InOrder traversal
            inOrderResult.clear();
            bst.inorder(bst.getRoot(), inOrderResult);
            cout << "Inorder result: ";
            for (const string &element : inOrderResult)
            {
                cout << "\n"
                     << element;
            }
            cout << "\n";
            break;

        case 4:
            // Exit the program
            cout << "Exiting the program.\n";
            return 0;

        default:
            // Invalid option
            cout << "Option is unavailable. Please, select a new option.\n";
        }
    }
}
