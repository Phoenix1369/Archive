template <typename T>
using vec = vector<T>;

vec<bool> dp;

class Solution {
public:
    bool winnerSquareGame(int n) {
        dp.assign(n+1, false);
        for (int i = 1; i <= n; ++i) {
            dp[i] = winning(i);
        }
        return dp[n];
    }

private:
    bool winning(int i) {
        for (int j=1, d=3; j <= i; ) {
            if (!dp[i-j]) {
                return true;
            }
            j += d;
            d += 2;
        }
        return false;
    }
};
