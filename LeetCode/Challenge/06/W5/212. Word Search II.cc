const int MAXA = 26;
const int K = 4;
const int dir[K][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int M, N;

template <typename T>
using vec = vector<T>;
vec<vec<char>> A;
vec<vec<bool>> seen;
vec<string> ret;
string s;

struct Trie {
    Trie* t[MAXA];
    bool end;

    Trie() : end{false} {
        for (int i = 0; i < MAXA; ++i) {
            t[i] = nullptr;
        }
    }

    void insert(const string& s) {
        Trie* cur = this;
        for (char c: s) {
            int d = c - 'a';
            if (cur->t[d] == nullptr) {
                cur->t[d] = new Trie();
            }
            cur = cur->t[d];
        }
        cur->end = true;
    }
};
Trie* root;

class Solution {
public:
    vector<string> findWords(
        vector<vector<char>>& board, vector<string>& words
    ) {
        A = move(board);
        N = A.size();
        M = A[0].size();
        seen.assign(N, vec<bool>(M, false));
        ret.clear();
        root = new Trie();
        for (string& w: words) {
            root->insert(w);
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dfs(i, j, s, root);
            }
        }
        return ret;
    }

private:
    void dfs(int i, int j, string& s, Trie* u) {
        char c = A[i][j];
        int d = c - 'a';
        if (u->t[d] == nullptr) {
            return;
        }
        s.push_back(c);
        u = u->t[d];
        if (u->end) {
            ret.push_back(s);
            u->end = false;
        }
        seen[i][j] = true;
        for (int k = 0; k < K; ++k) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (!in_range(ni, nj) || seen[ni][nj]) {
                continue;
            }
            dfs(ni, nj, s, u);
        }
        seen[i][j] = false;
        s.pop_back();
    }

    bool in_range(int r, int c) {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }
};
