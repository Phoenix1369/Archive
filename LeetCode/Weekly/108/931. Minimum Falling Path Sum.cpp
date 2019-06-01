const int MAXN = 105;
int dp[MAXN][MAXN]{ };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = (int)A.size();
        for (int j = 0; j < n; ++j) {
            dp[0][j] = A[0][j];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) {
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                }
                if (j < n-1) {
                    dp[i][j] = min(dp[i-1][j+1], dp[i][j]);
                }
                dp[i][j] += A[i][j];
            }
            for (int j = 0; j < n; ++j) {
                printf("%d ", dp[i][j]);
            }
            putchar('\n');
        }
        int ret = dp[n-1][0];
        for (int j = 1; j < n; ++j) {
            ret = min(dp[n-1][j], ret);
        }
        return ret;
    }
};
