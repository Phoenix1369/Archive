#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> data;
        int N = costs.size();
        int sum = 0;
        for (auto& cost: costs) {
            data.push_back(cost[1] - cost[0]);
            sum += cost[1];
        }
        sort(ALL(data));
        int half = N / 2;
        for (int i = 0; i < half; ++i) {
            sum -= data.back();
            data.pop_back();
        }
        return sum;
    }
};
