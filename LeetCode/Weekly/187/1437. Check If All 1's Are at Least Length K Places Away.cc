class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int N = nums.size();
        int last = -N;
        for (int i = 0; i < N; ++i) {
            if (nums[i] != 1) continue;
            if (last + k >= i) {
                return false;
            }
            last = i;
        }
        return true;
    }
};
