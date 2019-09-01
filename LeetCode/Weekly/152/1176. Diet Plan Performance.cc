class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int N = calories.size();
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            sum += calories[i];
            if (i >= k) {
                sum -= calories[i-k];
            }
            if (i+1 >= k) {
                if (sum < lower) {
                    --ret;
                } else if (sum > upper) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
