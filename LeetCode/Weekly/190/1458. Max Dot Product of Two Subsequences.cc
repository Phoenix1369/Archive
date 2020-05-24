const int INFN = 1e8+5;
const int MAXN = 505;
vector<vector<int>> dp;
int M, N;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        N = nums1.size();
        M = nums2.size();
        dp.assign(N+1, vector<int>(M+1, -INFN));
        int ret = -INFN;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                int val = nums1[i-1] * nums2[j-1];
                if (dp[i-1][j-1] > 0) {
                    val += dp[i-1][j-1];
                }
                dp[i][j] = max(val, dp[i][j]);
                ret = max(dp[i][j], ret);
            }
        }
        return ret;
    }
};
