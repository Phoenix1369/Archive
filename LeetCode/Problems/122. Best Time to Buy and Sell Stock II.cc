class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int buy, sell;
        buy = sell = prices[0];
        
        int ret = 0;
        for (int p: prices) {
            if (p <= sell) {
                ret += sell - buy;
                buy = sell = p;
            } else {
                sell = p;
            }
        }
        ret += sell - buy;
        return ret;
    }
};
