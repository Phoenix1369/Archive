class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = nums[0];
        while (cur != nums[cur]) {
            swap(cur, nums[cur]);
        }
        return cur;
    }
};
