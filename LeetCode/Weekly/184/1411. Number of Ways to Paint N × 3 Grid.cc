const int MAXN = 5005;
const int MOD = 1e9+7;
int dp[MAXN][2];

class Solution {
public:
    int numOfWays(int n) {
        dp[0][0] = 6;  // aba
        dp[0][1] = 6;  // abc
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i-1][0] * 3LL + dp[i-1][1] * 2LL) % MOD;
            dp[i][1] = (dp[i-1][0] * 2LL + dp[i-1][1] * 2LL) % MOD;
        }
        return (dp[n-1][0] + dp[n-1][1]) % MOD;
    }
};
