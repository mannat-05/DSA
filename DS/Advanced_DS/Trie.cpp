#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];  // assuming lowercase a–z
    bool isEnd;              // marks end of a word

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Search for a complete word
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() 
{
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << "\n";    // true
    cout << trie.search("app") << "\n";      // false
    cout << trie.startsWith("app") << "\n";  // true

    trie.insert("app");
    cout << trie.search("app") << "\n";      // true
}
