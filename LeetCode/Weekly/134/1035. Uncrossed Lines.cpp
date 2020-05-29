#define CLR(x) memset((x), 0, sizeof(x))
const int MAXN = 505;
int dp[2][MAXN];

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        CLR(dp);
        for (int h=1, i=1; h <= N; ++h, i ^= 1) {
            for (int j = 1; j <= M; ++j) {
                if (A[h-1] == B[j-1]) {
                    dp[i][j] = dp[i^1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i^1][j], dp[i][j-1]);
                }
            }
        }
        return dp[N&1][M];
    }
};
