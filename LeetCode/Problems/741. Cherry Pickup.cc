const int MAXN = 55;
const int NOPE = -1;
int dp[2][MAXN][MAXN];
int N, N2;

class Solution {
    vector<vector<int>> grid;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = move(grid);
        N = this->grid.size();
        N2 = N + N;
        
        // Init
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dp[k][i][j] = NOPE;
                }
            }
        }
        dp[1][0][0] = 0; // before (0, 0)
        
        // Top half
        for (int h = 0; h < N; ++h) {
            solve(h, 0, h+1);
        }

        // Bottom half
        for (int h = N; h < N2; ++h) {
            solve(h, h - N + 1, N);
        }
        
        // 2N-1 rows -> (2N-2) = 0 mod 2
        int ret = dp[0][N-1][N-1];
        return max(ret, 0);
    }

private:
    void solve(int h, int beg, int end) {
        int b = (h & 1);
        
        for (int i = beg; i < end; ++i) {
            for (int j = i; j < end; ++j) {
                dp[b][i][j] = NOPE;

                if ((grid[h-i][i] == NOPE) || (grid[h-j][j] == NOPE)) {
                    continue;
                }

                int cherry = grid[h-i][i];
                if (i != j) cherry += grid[h-j][j];

                // Valid
                for (int di = -1; di <= 0; ++di) {
                    for (int dj = -1; dj <= 0; ++dj) {
                        int prei = i + di;
                        int prej = j + dj;
                        if ((0 <= prei) && (0 <= prej) &&
                           (dp[b^1][prei][prej] != NOPE)) {
                            dp[b][i][j] = max(dp[b^1][prei][prej] + cherry, dp[b][i][j]);
                        }
                    }
                }
            }
        }
    }
};
