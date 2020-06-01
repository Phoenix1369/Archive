template <typename T>
using vec = vector<T>;
vec<vec<int>> dp;

class Solution {
public:
    int minDistance(string S, string T) {
        int N = S.size();
        int M = T.size();
        dp.assign(2, vec<int>(M+1, 0));
        for (int j = 1; j <= M; ++j) dp[0][j] = j;
        for (int h=1, i=1; h <= N; ++h, i ^= 1) {
            dp[i][0] = h;
            for (int j = 1; j <= M; ++j) {
                if (S[h-1] == T[j-1]) {
                    dp[i][j] = dp[i^1][j-1];
                } else {
                    dp[i][j] = min(
                        min(dp[i^1][j], dp[i][j-1]),
                        dp[i^1][j-1]
                    ) + 1;
                }
            }
        }
        return dp[N&1][M];
    }
};
