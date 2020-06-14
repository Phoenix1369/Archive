class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};
