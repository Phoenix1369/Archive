const int MAXN = 505;
// dp[i][j] = maxiumum sum of first i elements with current segment starting at j.
int dp[MAXN][MAXN];
int mx[MAXN][MAXN];

class Solution {
    int N;

public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = 0;
            }
            mx[i][i] = A[i];
            for (int j = i+1; j < N; ++j) {
                mx[i][j] = max(mx[i][j-1], A[j]);
            }
        }
        dp[0][0] = A[0];
        for (int i = 1; i < N; ++i) {
            // Create new segment.
            for (int j = max(i-K, 0); j < i; ++j) {
                dp[i][i] = max(dp[i-1][j], dp[i][i]);
            }
            dp[i][i] += A[i];
            // Extend previous segment.
            for (int j = max(i-K+1, 0); j < i; ++j) {
                int diff = max(A[i] - mx[j][i-1], 0);
                dp[i][j] = max(dp[i-1][j] + mx[j][i-1] + diff * (i-j+1), dp[i][j]);
            }
        }
        return *max_element(dp[N-1] + (N-K), dp[N-1] + N);
    }
};

