class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int best = 0;
        for (int i = 0; i < N; ++i) {
            if (best < i) {
                return false;
            }
            best = max(i + nums[i], best);
        }
        return true;
    }
};
