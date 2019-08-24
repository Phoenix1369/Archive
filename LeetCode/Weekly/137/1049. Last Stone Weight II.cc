#define ALL(x) (x).begin(), (x).end()
const int MAXS = 3005;
bitset<MAXS> dp;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        dp.reset();
        dp.set(0);
        for (auto s: stones) dp |= dp << s;
        return solve(accumulate(ALL(stones), 0));
    }

private:
    int solve(int sum) {
        int lo = sum / 2;
        int hi = (sum + 1) / 2;
        while ((0 <= lo) && (hi <= sum)) {
            if (dp[lo]) return sum - 2*lo;
            if (dp[hi]) return 2*hi - sum;
            --lo;
            ++hi;
        }
        return sum;
    }
};
