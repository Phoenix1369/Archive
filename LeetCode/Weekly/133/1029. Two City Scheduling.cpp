#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(ALL(costs), [](const vector<int>& lhs, const vector<int>& rhs) {
            return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
        });
        int N = costs.size();
        N /= 2;
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ret += costs[i][0] + costs[i+N][1];
        }
        return ret;
    }
};
