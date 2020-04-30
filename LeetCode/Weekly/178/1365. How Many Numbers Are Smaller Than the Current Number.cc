const int MAXA = 101;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[MAXA]{ };
        for (int x: nums) ++cnt[x];
        for (int i = 1; i < MAXA; ++i) {
            cnt[i] += cnt[i-1];
        }
        vector<int> ret;
        ret.reserve(nums.size());
        for (int x: nums) {
            if (x) ret.push_back(cnt[x-1]);
            else   ret.push_back(0);
        }
        return ret;
    }
};
