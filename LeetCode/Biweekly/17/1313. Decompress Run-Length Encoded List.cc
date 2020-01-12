class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int N = nums.size();
        vector<int> ret;
        for (int i = 0; i < N; i += 2) {
            int k = i + 1;
            for (int j = 0; j < nums[i]; ++j) {
                ret.push_back(nums[k]);
            }
        }
        return ret;
    }
};
