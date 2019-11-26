const int MAXN = 255;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int col[MAXN]{ };
        int row[MAXN]{ };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                ++col[j];
                ++row[i];
            }
        }
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                if ((col[j] > 1) || (row[i] > 1)) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
