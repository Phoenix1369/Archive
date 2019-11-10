class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (auto itr: indices) {
            int ri = itr[0];
            int ci = itr[1];
            ++rows[ri];
            ++cols[ci];
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = rows[i] + cols[j];
                if (cur & 1) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
