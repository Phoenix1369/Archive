const int MAXN = 20;
const int EXPN = 1<<MAXN;
const int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}};
enum { BAD = -1, FREE, SRC, SNK };
int dp[EXPN][MAXN]{ };

class Solution {
    int D, G, M, N;
    int end_mask;
    int snk, src;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        reset();
        N = grid.size();
        M = grid[0].size();
        G = N*M;
        D = 1<<G;
        end_mask = D-1;
        find_ends(grid);
        dp[1<<src][src] = 1;
        for (int mask = 1; mask < D; ++mask) {
            for (int u = 0; u < G; ++u) if ((mask >> u) & 1) {
                if (!dp[mask][u]) {
                    continue;
                }
                int cx = u % M;
                int cy = u / M;
                if ((grid[cy][cx] == BAD) || (grid[cy][cx] == SNK)) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int nx = cx + moves[k][0];
                    int ny = cy + moves[k][1];
                    if ((nx < 0) || (nx >= M) ||
                        (ny < 0) || (ny >= N) || (grid[ny][nx] == BAD)) {
                        continue;
                    }
                    int v = ny * M + nx;
                    if ((mask >> v) & 1) {
                        continue;
                    }
                    dp[mask|(1<<v)][v] += dp[mask][u];
                }
            }
        }
        return dp[end_mask][snk];
    }

private:
    void find_ends(const vector<vector<int>>& grid) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == SRC) {
                    src = i * M + j;
                } else if (grid[i][j] == SNK) {
                    snk = i * M + j;
                } else if (grid[i][j] == BAD) {
                    end_mask &= ~(1 << (i * M + j));
                }
            }
        }
    }

    void reset() {
        for (int i = 0; i < EXPN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                dp[i][j] = 0;
            }
        }
    }
};
