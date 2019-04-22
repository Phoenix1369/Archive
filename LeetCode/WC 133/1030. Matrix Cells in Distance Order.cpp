#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
typedef vector<vin> vvi;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vvi ret;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ret.push_back({ i, j });
            }
        }
        std::sort(ALL(ret), [&](const vin& lhs, const vin& rhs) {
            int ldis = abs(lhs[0] - r0) + abs(lhs[1] - c0);
            int rdis = abs(rhs[0] - r0) + abs(rhs[1] - c0);
            return (ldis < rdis);
        });
        return ret;
    }
};
