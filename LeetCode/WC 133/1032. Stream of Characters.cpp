#define ALL(x) (x).begin(), (x).end()
const int MAXA = 26;
const int MAXN = 2019;

struct Node {
    bool isend;
    Node* next[MAXA];

    Node() {
        isend = false;
        for (int i = 0; i < MAXA; ++i) {
            next[i] = nullptr;
        }
    }

    void build(const string& S, int pos) {
        if (pos == S.size()) {
            isend = true;
            return;
        }
        int chr = S[pos]-'a';
        if (next[chr] == nullptr) {
            next[chr] = new Node();
        }
        return next[chr]->build(S, pos+1);
    }

    void clear() {
        for (int i = 0; i < MAXA; ++i) if (next[i]) {
            next[i]->clear();
            delete next[i];
        }
    }

    bool rfind(const string& S, int pos) {
        if (isend) {
            return true;
        }
        if (pos < 0) {
            return false;
        }
        int chr = S[pos]-'a';
        if (next[chr] == nullptr) {
            return false;
        }
        return next[chr]->rfind(S, pos-1);
    }
};

class StreamChecker {
    Node* root = nullptr;
    string stream;

public:
    StreamChecker(vector<string>& words) {
        if (root) {
            root->clear();
            delete root;
        }
        root = new Node();
        for (auto& word: words) {
            reverse(ALL(word));
            root->build(word, 0);
        }
        stream.clear();
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        int N = stream.size();
        return root->rfind(stream, N-1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
