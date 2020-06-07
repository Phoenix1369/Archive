#define CLR(x) memset((x), -1, sizeof(x))
const int MAXM = 105;
const int MAXN = 25;
int dp[MAXM][MAXN][MAXM];
//  dp[i][j][k] = i-th house, j-th color, k blocks
int M, N;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost,
                int m, int n, int target
    ) {
        M = m;
        N = n;
        CLR(dp);
        for (int j = 1; j <= N; ++j) {
            dp[0][j][0] = 0;
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                int c = houses[i-1];
                for (int k = 1; k <= i; ++k) {
                    int res = -1;
                    if ((c == 0) || (j == c)) {
                        for (int l = 1; l <= N; ++l) {
                            int val = (l == j)
                                ? dp[i-1][j][k]
                                : dp[i-1][l][k-1];
                            if (val == -1) {
                                continue;
                            }
                            if (c == 0) {
                                val += cost[i-1][j-1];
                            }
                            if ((res == -1) || (val < res)) {
                                res = val;
                            }
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        int ret = -1;
        for (int j = 1; j <= N; ++j) {
            int val = dp[M][j][target];
            if (val == -1) {
                continue;
            }
            if ((ret == -1) || (val < ret)) {
                ret = val;
            }
        }
        return ret;
    }
};
