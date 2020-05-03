#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int N = nums.size();
        sort(ALL(nums), greater<int>());
        int tot = accumulate(ALL(nums), 0);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (sum * 2 > tot) {
                nums.erase(nums.begin() + i, nums.end());
                break;
            }
            sum += nums[i];
        }
        return nums;
    }
};
