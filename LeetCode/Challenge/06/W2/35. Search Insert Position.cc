#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(ALL(nums), target) - nums.begin();
    }
};
