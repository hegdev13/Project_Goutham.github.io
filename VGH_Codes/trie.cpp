// This is an implementatoin of trie data structure as a dictionary

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>

using namespace std;

class TrieNode 
{
public:
    unordered_map<char, TrieNode*> children;
    int is_EOW; // End Of Word

    TrieNode() 
    {
        is_EOW = 0;
    }
};

class Trie 
{
private:
    TrieNode* root;

    int del_checker(TrieNode* node, const string& word, int i) 
    {
        if (i == word.length()) 
        {
            if (node->is_EOW == 0) 
            {
                return 0; 
            }
            node->is_EOW = 0;
            return node->children.empty(); 
        }

        char ch = word[i];
        TrieNode* child = node->children[ch];

        if (!child) 
        {
            return 0; 
        }

        if (del_checker(child, word, i + 1)) 
        {
            node->children.erase(ch); 
            return node->children.empty() && node->is_EOW == 0; 
        }
        return 0;
    }

public:
    Trie() 
    {
        root = new TrieNode();
    }


    void insert(const string& word) 
    {
        TrieNode* node = root;
        for (char c : word) 
        {
            if (node->children.find(c) == node->children.end()) 
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->is_EOW = 1;
        cout << "Word '" << word << "' inserted successfully!" << endl;
    }

    int search(const string& word) 
    {
        TrieNode* node = root;
        for (char c : word) 
        {
            if (node->children.find(c) == node->children.end()) 
                return 0; 
            node = node->children[c];
        }
        return node->is_EOW; 
    }

    void delete_w(const string& word) 
    {
        if (del_checker(root, word, 0)) 
        {
            cout << "Word '" << word << "' deleted successfully!" << endl;
        } 
        else 
        {
            cout << "Word '" << word << "' not found!" << endl;
        }
    }
};

int main() 
{
    Trie trie;
    int choice;
    string word;

    while (true) 
    {
        cout << "\n--- Trie Menu ---\n";
        cout << "1. Insert word\n";
        cout << "2. Search word\n";
        cout << "3. Delete word\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter word to insert: "; cin >> word; 
                trie.insert(word);
                break;

            case 2:
                cout << "Enter word to search: "; cin >> word;
                if (trie.search(word)) 
                    cout << "Word '" << word << "' found!" << endl;
                else
                    cout << "Word '" << word << "' not found!" << endl;
                break;

            case 3:
                cout << "Enter word to delete: ";cin >> word;
                trie.delete_w(word);
                break;

            case 0:
                cout << "Exiting program..." << endl;
                return 0; 

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
