const int MOD = 1e9+7;
const int MAXD = 35;
const int MAXT = 1005;
int dp[MAXD][MAXT];

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j <= target; ++j) if (dp[i][j]) {
                for (int k = 1; (k <= f) && (j+k <= target); ++k) {
                    dp[i+1][j+k] = (1LL * dp[i][j] + dp[i+1][j+k]) % MOD;
                }
            }
        }
        return dp[d][target];
    }
};
