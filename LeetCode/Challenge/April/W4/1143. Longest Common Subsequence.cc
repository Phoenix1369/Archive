const int MAXN = 1005;
int dp[MAXN][MAXN];
int M, N;

class Solution {
public:
    int longestCommonSubsequence(string S, string T) {
        N = S.size();
        M = T.size();
        for (int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= M; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (S[i-1] == T[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[N][M];
    }
};
