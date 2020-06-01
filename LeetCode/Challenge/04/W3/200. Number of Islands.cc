template <typename T>
using vec = vector<T>;

const char LAND = '1';
const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int M, N;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        N = grid.size();
        M = grid[0].size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] != LAND) continue;
                ++ret;
                dfs(i, j, grid);
            }
        }
        return ret;
    }

private:
    void dfs(int row, int col, vec<vec<char>>& G) {
        G[row][col] = 0;
        for (int k = 0; k < 4; ++k) {
            int nr = row + moves[k][0];
            int nc = col + moves[k][1];
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) continue;
            if (G[nr][nc] != LAND) continue;
            dfs(nr, nc, G);
        }
    }
};
