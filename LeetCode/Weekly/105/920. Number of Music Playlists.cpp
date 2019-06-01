const int MAXN = 105;
const int MOD = 1e9+7;
int dp[2][MAXN];

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int h = 1; h <= L; ++h) {
            int i = (h & 1);
            dp[i][0] = 0;
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = 1LL * dp[i^1][j-1] * j % MOD;
                if (j >= K) {
                    dp[i][j] = (dp[i][j] + 1LL * dp[i^1][j] * (j - K) % MOD) % MOD;
                }
                // dp[i][j] = dp[i-1][j-1] * j + dp[i-1][j] * (j - K);
                // Consider the i-th element:
                // j-1 unique types: (only remaining type) * (j types)
                // j   unique types: (j - K) possible types
            }
        }
        return dp[L & 1][N];
    }
};

