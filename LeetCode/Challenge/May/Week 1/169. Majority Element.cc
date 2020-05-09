class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        nth_element(nums.begin(), nums.begin() + N/2, nums.end());
        return nums[N/2];
    }
};
