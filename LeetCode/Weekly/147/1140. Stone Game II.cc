const int MAXN = 105;
const int NOPE = -1;
int dp[MAXN][MAXN];
int A[MAXN];

class Solution {
    int N;

public:
    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        A[N] = 0;
        for (int i = N-1; i >= 0; --i) {
            A[i] = piles[i] + A[i+1];
        }
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i][j] = NOPE;
            }
        }
        return dfs(0, 1);
    }

private:
    int dfs(int i, int m) {
        if (dp[i][m] != NOPE) {
            return dp[i][m];
        }
        if (i + 2*m >= N) {
            return dp[i][m] = A[i];
        }
        int ret = A[0];
        for (int j = 1; j <= 2*m; ++j) {
            ret = min(dfs(i + j, max(j, m)), ret);
        }
        return dp[i][m] = A[i] - ret;
    }
};
