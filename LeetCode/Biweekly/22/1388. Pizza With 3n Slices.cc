const int MAXN = 505;
int dp[2][MAXN];
int A[MAXN];
int K, N;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        // Maximize sum of K non-adjacent elements
        // Exclude A[1] or A[N] for circular constraint
        N = slices.size();
        K = N/3;
        for (int i = 0; i < N; ++i) {
            A[i+1] = slices[i];
        }
        return max(
            solve(1, N-1),
            solve(2, N)
        );
    }

private:
    int solve(int a, int b) {
        init();
        dp[a & 1][1] = A[a];
        for (int h = a+1; h <= b; ++h) {
            int i = h & 1;
            int J = ((h-a+1) + 1) / 2;
            int cap = min(J, K);
            for (int j = cap; j >= 1; --j) {
                dp[i][j] = max(dp[i^1][j], A[h] + dp[i][j-1]);
            }
        }
        return dp[b & 1][K];
    }
    
    void init () {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= K; ++j) {
                dp[i][j] = 0;
            }
        }
    }
};
