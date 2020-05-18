class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> output = nums;
        for (int i = 1; i < N; ++i) {
            output[i] *= output[i-1];
        }
        int suffix = 1;
        for (int i = N-1; i > 0; --i) {
            output[i] = output[i-1] * suffix;
            suffix *= nums[i];
        }
        output[0] = suffix;
        return output;
    }
};
