class Solution {
    const int MAXA = 305;
    const int MAXN = 3005;
    const int MOD = 1e9+7;
public:
    int threeSumMulti(vector<int>& A, int target) {
        int twoSum[MAXN][MAXA]{ };
        int n = (int)A.size();
        for (int j = 1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                ++twoSum[j][A[j]+A[k]];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (A[i] <= target) {
                    ret = (1LL*twoSum[j][target-A[i]] + ret) % MOD;
                }
            }
        }
        return ret;
    }
};
