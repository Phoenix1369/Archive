const int MOD = 1e9+7;

class Solution {
public:
    int countOrders(int n) {
        int ret = 1;
        for (int i = 1; i < n; ++i) {
            int k = 2 * i + 1;
            ret = 1LL * ret * sum(k) % MOD;
        }
        return ret;
    }

private:
    int sum(int x) {
        return 1LL * x * (x + 1) / 2;
    }
};
