class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        int one = 0;
        int ret = 0;
        unordered_map<int, int> diff;
        diff.reserve(N);
        diff[one] = -1;
        for (int i = 0; i < N; ++i) {
            if (nums[i]) ++one;
            else --one;
            if (diff.count(one)) {
                ret = max(i - diff.at(one), ret);
            }
            if (!diff.count(one)) {
                diff[one] = i;
            }
        }
        return ret;
    }
};
