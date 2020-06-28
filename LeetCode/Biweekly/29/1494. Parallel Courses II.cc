//  dp[i] = minimum semesters taking mask "i" courses
vector<int> dp;
vector<int> up;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int m = (1 << n);
        dp.assign(m, n);
        up.assign(n, 0);
        for (auto& e: dependencies) {
            int x = e[0];
            int y = e[1];
            --x;
            --y;
            up[y] |= (1 << x);
        }
        dp[0] = 0;
        for (int mask = 0; mask < m; ++mask) {
            int next = 0;
            for (int bit = 0; bit < n; ++bit) {
                if ((mask >> bit) & 1) {
                    continue;
                }
                if ((mask & up[bit]) == up[bit]) {
                    next |= (1 << bit);
                }
            }
            for (int s = next; s; s = (s-1) & next) {
                if (__builtin_popcount(s) > k) {
                    continue;
                }
                dp[mask | s] = min(dp[mask | s], dp[mask] + 1);
            }
        }
        return dp[m-1];
    }
};
