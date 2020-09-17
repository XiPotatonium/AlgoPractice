#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
    struct TrieNode {
        unordered_map<char, TrieNode *> next_map;
        bool is_word;

        TrieNode() : is_word(false) {}
    };

    TrieNode root;

    TrieNode *_prefix(const string &s) {
        TrieNode *cur = &root;
        for (char ch : s) {
            auto next = cur->next_map.find(ch);
            if (next == cur->next_map.end()) {
                return nullptr;
            }
            cur = next->second;
        }
        return cur;
    }

public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = &root;
        for (char ch : word) {
            auto next = cur->next_map.find(ch);
            if (next == cur->next_map.end()) {
                next = cur->next_map.emplace(ch, new TrieNode()).first;
            }
            cur = next->second;
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tail = _prefix(word);
        return tail != nullptr && tail->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tail = _prefix(prefix);
        return tail != nullptr;
    }
};

int main(void) {
    Trie trie;

    trie.insert("apple");
    cout << (trie.search("apple") ? "true" : "false") << endl;   // returns true
    cout << (trie.search("app") ? "true" : "false") << endl;     // returns false
    cout << (trie.startsWith("app") ? "true" : "false") << endl; // returns true
    trie.insert("app");
    cout << (trie.search("app") ? "true" : "false") << endl; // returns true
    return 0;
}