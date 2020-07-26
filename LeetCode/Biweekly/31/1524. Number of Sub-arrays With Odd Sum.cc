const int MOD = 1e9+7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cur[2]{ };
        int sum[2]{ };
        for (auto& x: arr) {
            x &= 1;
            if (x) {
                swap(cur[0], cur[1]);
            }
            ++cur[x];
            sum[0] = (1LL * sum[0] + cur[0]) % MOD;
            sum[1] = (1LL * sum[1] + cur[1]) % MOD;
        }
        return sum[1];
    }
};
