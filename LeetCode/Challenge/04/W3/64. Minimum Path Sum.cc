class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (i && j) grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                else if (i) grid[i][j] += grid[i-1][j];
                else if (j) grid[i][j] += grid[i][j-1];
            }
        }
        return grid[N-1][M-1];
    }
};
