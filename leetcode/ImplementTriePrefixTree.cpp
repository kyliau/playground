struct TrieNode {
    bool      isWord;
    TrieNode *next[26];
    TrieNode()
    : isWord(false)
    , next({0}) {
    }
};

class Trie {
  private:
    TrieNode *root;

    TrieNode *find(const string& key) {
        TrieNode *curr = root;
        for (char c : key) {
            if (!curr) {
                return nullptr;
            }
            int index = c - 'a';
            curr = curr->next[index];
        }
        return curr;
    }
  public:
    /** Initialize your data structure here. */
    Trie()
    : root(new TrieNode())
    {
    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode *curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
        }
        curr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        TrieNode *node = find(word);
        return node && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        return find(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */