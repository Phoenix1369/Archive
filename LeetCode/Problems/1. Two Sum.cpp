class Solution {
    unordered_map<int,int> index;
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        index.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            if (index.count(nums[i])) {
                return { index.at(nums[i]), i };
            }
            index[target-nums[i]] = i;
        }
    }
};
