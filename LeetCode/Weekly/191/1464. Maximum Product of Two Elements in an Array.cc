class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                ret = max((nums[i] - 1) * (nums[j] - 1), ret);
            }
        }
        return ret;
    }
};
