#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;

class Solution {
    int sqr(int x) { return x*x; }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res = points;
        sort(ALL(res), [&](const vin& lhs, const vin& rhs) {
            return sqr(lhs[0])+sqr(lhs[1]) < sqr(rhs[0])+sqr(rhs[1]);
        });
        while (res.size() > K) {
            res.pop_back();
        }
        return res;
    }
};
