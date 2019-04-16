const int MAXA = 1e4+5;
const int MAXB = MAXA*2;
const int MAXN = 2019;
int dp[MAXN][MAXB]{ };

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < MAXB; ++j) {
                dp[i][j] = 0;
            }
        }
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                int k = A[i] - A[j] + MAXA;
                dp[i][k] = max(dp[j][k] + 1, dp[i][k]);
                ret = max(dp[i][k], ret);
            }
        }
        ++ret;
        return ret;
    }
};
