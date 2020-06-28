using vin = vector<int>;
const int MAXP = 2e8+5;
deque<vin> D;
int ret;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        D.clear();
        ret = -MAXP;
        for (vin& p: points) {
            while (!D.empty() && (D.front()[0] + k < p[0])) {
                D.pop_front();
            }
            if (!D.empty()) {
                vin& q = D.front();
                ret = max(p[1] + q[1] + p[0] - q[0], ret);
            }
            while (!D.empty()) {
                vin& q = D.back();
                if (p[1] - q[1] >= p[0] - q[0]) {
                    D.pop_back();
                } else {
                    break;
                }
            }
            D.push_back(p);
        }
        return ret;
    }
};
