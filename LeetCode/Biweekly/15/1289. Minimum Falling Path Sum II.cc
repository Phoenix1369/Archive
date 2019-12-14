const int MAXA = 105;
const int MAXN = 205;
int dp[2][MAXN];
int N;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        N = arr.size();
        for (int j = 0; j <= N; ++j) {
            dp[0][j] = 0;
        }
        for (int h = 1; h <= N; ++h) {
            int i = (h & 1);
            for (int j = 1; j <= N; ++j) {
                int prev = h * MAXA;
                for (int k = 1; k <= N; ++k) if (k != j) {
                    prev = min(dp[i^1][k], prev);
                }
                dp[i][j] = prev + arr[h-1][j-1];
            }
        }
        return *min_element(dp[N & 1] + 1, dp[N & 1] + N + 1);
    }
};
