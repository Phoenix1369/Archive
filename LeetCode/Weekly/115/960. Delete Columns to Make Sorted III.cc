const int MAXN = 105;
vector<string> A;
int dp[MAXN];
int M, N;

class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        A = move(arr);
        N = A.size();
        M = A[0].size();
        for (int i = 0; i < M; ++i) dp[i] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < i; ++j) {
                if (leq(j, i)) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        int ret = M - *max_element(dp, dp+M);
        return ret;
    }

private:
    bool leq(int a, int b) {
        for (int i = 0; i < N; ++i) {
            if (A[i][a] > A[i][b]) {
                return false;
            }
        }
        return true;
    }
};
