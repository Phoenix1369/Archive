const int MAXN = 1e3+5;
int A[MAXN];
int dp[MAXN];

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int N = arr.size();
        for (int i = 0; i < N; ++i) {
            A[i] = i;
            dp[i] = 1;
        }
        sort(A, A+N, [&arr](int i, int j) {
            return (arr[i] < arr[j]);
        });
        
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1;
                    (j <= d) &&
                    (A[i] - j >= 0) &&
                    (arr[A[i]] > arr[A[i] - j]); ++j) {
                dp[A[i]] = max(dp[A[i] - j] + 1, dp[A[i]]);
            }
            for (int j = 1;
                    (j <= d) &&
                    (A[i] + j < N) &&
                    (arr[A[i]] > arr[A[i] + j]); ++j) {
                dp[A[i]] = max(dp[A[i] + j] + 1, dp[A[i]]);
            }
            ret = max(dp[A[i]], ret);
            
        }
        return ret;
    }
};
