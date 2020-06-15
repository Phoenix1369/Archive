const int LOGN = 16;
const int MAXN = 5e4+5;
int up[LOGN][MAXN];
int N;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        N = n;
        for (int i = 0; i < N; ++i) {
            up[0][i] = parent[i];
        }
        for (int k = 1; k < LOGN; ++k) {
            for (int i = 0; i < N; ++i) {
                int pre = up[k-1][i];
                if (pre != -1) {
                    pre = up[k-1][pre];
                }
                up[k][i] = pre;
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int cur = node;
        for (int i = 0; ((1 << i) <= k) && (cur != -1); ++i) {
            if ((k >> i) & 1) {
                cur = up[i][cur];
            }
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
