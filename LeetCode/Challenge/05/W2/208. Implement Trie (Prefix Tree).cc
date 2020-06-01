const int MAXA = 26;

class Trie {
    Trie* data[MAXA];
    bool end;

public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < MAXA; ++i) {
            data[i] = nullptr;
        }
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        return insert(word, 0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given
        prefix.
    */
    bool startsWith(string prefix) {
        return startsWith(prefix, 0);
    }

private:
    void insert(const string& s, unsigned pos) {
        if (pos == s.size()) {
            end = true;
            return;
        }
        int k = s[pos] - 'a';
        if (!data[k]) {
            data[k] = new Trie();
        }
        return data[k]->insert(s, pos + 1);
    }
    
    bool search(const string& s, unsigned pos) {
        if (pos == s.size()) {
            return end;
        }
        int k = s[pos] - 'a';
        if (!data[k]) {
            return false;
        }
        return data[k]->search(s, pos + 1);
    }
    
    bool startsWith(const string& s, unsigned pos) {
        if (pos == s.size()) {
            return pos || any_of(data, data + MAXA, [](Trie* cur) {
                return cur != nullptr;
            });
        }
        int k = s[pos] - 'a';
        if (!data[k]) {
            return false;
        }
        return data[k]->startsWith(s, pos + 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
