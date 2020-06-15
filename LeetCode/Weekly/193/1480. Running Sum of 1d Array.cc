class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; ++i) {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};
