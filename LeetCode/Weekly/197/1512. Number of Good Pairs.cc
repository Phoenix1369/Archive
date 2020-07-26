class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int N = nums.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (nums[i] == nums[j]) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
