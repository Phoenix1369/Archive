#define ALL(x) (x).begin(), (x).end()
const int K = 4;
int n;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        n = nums.size();
        if (n <= K) {
            return 0;
        }
        sort(ALL(nums));
        int ret = nums.back() - nums.front();
        for (int i = 0; i < K; ++i) {
            ret = min(nums.end()[i-K] - nums[i], ret);
        }
        return ret;
    }
};
