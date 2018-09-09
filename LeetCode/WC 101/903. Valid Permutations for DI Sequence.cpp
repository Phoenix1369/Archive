class Solution {
public:
    const static int MAXN = 205;
    const int MOD = 1e9+7;
    int dp[MAXN][MAXN]{ };
    
    int numPermsDISequence(string S) {
        int n = (int)S.size() + 1;
        for(int j = 1; j <= n; ++j) {
            dp[1][j] = 1;
        }
        for(int i = 2; i <= n; ++i) {
            if(S[i-2] == 'D') {
                for(int j = 1; j <= i; ++j) {
                    dp[i][j] = (1LL*dp[i-1][i-1] - dp[i-1][j-1] + MOD) % MOD;
                }
            } else {
                for(int j = 1; j <= i; ++j) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            for(int j = 2; j <= i; ++j) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
        return dp[n][n];
    }
};
