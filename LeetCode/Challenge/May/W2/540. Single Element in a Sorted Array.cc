class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        int lo = 0;
        int hi = N-1;
        while (lo < hi) {
            int x = (lo + hi) / 2;
            // (x != N-1)
            bool u = (nums[x] == nums[x+1]);
            bool v = (x & 1);
            if (u ^ v) {
                lo = x+1;
            } else {
                hi = x;
            }
        }
        return nums[lo];
    }
};
