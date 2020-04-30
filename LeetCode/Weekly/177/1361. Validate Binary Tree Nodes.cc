const int MAXN = 1e4+5;
bool seen[MAXN];
vector<int> L;
vector<int> R;
int P[MAXN];
int cnt, N;

class Solution {
public:
    bool validateBinaryTreeNodes(
            int n,
            vector<int>& leftChild,
            vector<int>& rightChild
    ) {
        N = n;
        L = move(leftChild);
        R = move(rightChild);
        init();
        for (int i = 0; i < N; ++i) {
            if (L[i] != -1) P[L[i]] = i;
            if (R[i] != -1) P[R[i]] = i;
        }
        int root = -1;
        for (int i = 0; i < N; ++i) {
            if (P[i] == -1) {
                root = i;
                break;
            }
        }
        cnt = 0;
        return dfs(root) && (cnt == n);
    }

private:
    bool dfs(int u) {
        if (u == -1) return true;
        if (seen[u]) return false;
        seen[u] = true;
        ++cnt;
        return dfs(L[u]) && dfs(R[u]);
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            seen[i] = false;
            P[i] = -1;
        }
    }
};
