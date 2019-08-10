class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int N = nums.size();
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == target) ++cnt;
        }
        return cnt*2 > N;
    }
};
