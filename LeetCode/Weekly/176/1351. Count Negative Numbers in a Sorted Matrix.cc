class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int ret = 0;
        int tail = M-1;
        for (int i = 0; i < N; ++i) {
            while ((tail >= 0) && (grid[i][tail] < 0)) --tail;
            ret += (M - tail - 1);
        }
        return ret;
    }
};
