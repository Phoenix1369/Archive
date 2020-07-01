template <typename T>
using vec = vector<T>;
vec<vec<int>> dp;

class Solution {
public:
    int uniquePaths(int m, int n) {
        dp.assign(m, vec<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) dp[i][j] += dp[i-1][j];
                if (j) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
