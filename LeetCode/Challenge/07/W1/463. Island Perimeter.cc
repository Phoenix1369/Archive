const int K = 4;
const int dir[K][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
const int LAND = 1;
int M, N;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] != LAND) {
                    continue;
                }
                for (int k = 0; k < K; ++k) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if (!in_range(ni, nj) || (grid[ni][nj] != LAND)) {
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }

private:
    bool in_range(int i, int j) {
        return (0 <= i) && (i < N) && (0 <= j) && (j < M);
    }
};
