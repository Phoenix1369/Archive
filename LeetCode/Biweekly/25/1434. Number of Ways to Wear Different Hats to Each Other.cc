#define ALL(x) (x).begin(), (x).end()
const int EXPN = 1<<10;
const int MAXK = 40;
const int MOD = 1e9+7;
int A[MAXK];
int dp[MAXK][EXPN];
int L, N;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        N = hats.size();
        L = (1 << N) - 1;
        init();
        // Transpose
        for (int j = 0; j < N; ++j) {
            for (int c: hats[j]) {
                A[c-1] |= (1 << j);
            }
        }
        return dfs(0, L);
    }

private:
    int dfs(int pos, int mask) {
        if (!mask) return 1;
        if (pos == MAXK) return 0;
        if (dp[pos][mask] != -1) {
            return dp[pos][mask];
        }
        // Use
        int ret = 0;
        for (int bit = 0; bit < N; ++bit) {
            if (test(A[pos], bit) && test(mask, bit)) {
                ret = (dfs(pos + 1, mask & ~(1 << bit)) + ret) % MOD;
            }
        }
        // Skip
        ret = (dfs(pos + 1, mask) + ret) % MOD;
        return dp[pos][mask] = ret;
    }
    
    void init() {
        for (int i = 0; i < MAXK; ++i) {
            for (int j = 0; j <= L; ++j) {
                dp[i][j] = -1;
            }
            A[i] = 0;
        }
    }
    
    bool test(int mask, int bit) {
        return (mask >> bit) & 1;
    }
};
