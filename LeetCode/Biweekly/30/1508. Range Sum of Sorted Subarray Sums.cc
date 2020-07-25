#define ALL(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
vector<int> A;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        --left;
        --right;
        A.clear();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                A.push_back(sum);
            }
        }
        sort(ALL(A));
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            ret = (1LL * ret + A[i]) % MOD;
        }
        return ret;
    }
};
