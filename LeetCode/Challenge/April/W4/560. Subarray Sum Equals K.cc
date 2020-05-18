unordered_map<int,int> cnt;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        cnt.clear();
        cnt.reserve(N + 1);
        cnt[0] = 1;
        int sum = 0;
        int ret = 0;
        for (int x: nums) {
            sum += x;
            if (cnt.count(sum - k)) {
                ret += cnt.at(sum - k);
            }
            ++cnt[sum];
        }
        return ret;
    }
};
