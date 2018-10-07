class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int m = prices[0];
        int ret = 0;
        for (const auto& p: prices) {
            m = min(p, m);
            ret = max(p-m, ret);
        }
        return ret;
    }
};
