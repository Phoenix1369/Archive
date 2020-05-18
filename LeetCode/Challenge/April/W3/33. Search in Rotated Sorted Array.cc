class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int lo = 0;
        int hi = N-1;
        while (lo < hi) {
            int x = (lo + hi) / 2;
            if (nums[hi] < nums[x]) {
                if ((nums[x] < target) || (target <= nums[hi])) {
                    lo = x+1;
                } else {
                    hi = x;
                }
            } else {
                if ((nums[x] < target) && (target <= nums[hi])) {
                    lo = x+1;
                } else {
                    hi = x;
                }
            }
        }
        if (!N || (nums[hi] != target)) {
            return -1;
        }
        return lo;
    }
};
