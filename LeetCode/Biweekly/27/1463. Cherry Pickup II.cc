#define CLR(x) memset((x), -1, sizeof(x))
const int MAXN = 75;
int dp[2][MAXN][MAXN];
int C, R;

template <typename T>
using vec = vector<T>;
vec<vec<int>> A;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        A = move(grid);
        R = A.size();
        C = A[0].size();
        CLR(dp);
        dp[0][0][C-1] = A[0][0] + A[0][C-1];
        int ret = 0;
        for (int h=1, i=1; h < R; ++h, i ^= 1) {
            for (int j = 0; j < C; ++j) {
                for (int k = 0; k < C; ++k) {
                    dp[i][j][k] = -1;
                    for (int dj = -1; dj <= 1; ++dj) {
                        int pj = j + dj;
                        if ((pj < 0) || (pj >= C)) {
                            continue;
                        }
                        for (int dk = -1; dk <= 1; ++dk) {
                            int pk = k + dk;
                            if ((pk < 0) || (pk >= C)) {
                                continue;
                            }
                            dp[i][j][k] = max(dp[i^1][pj][pk], dp[i][j][k]);
                        }
                    }
                    if (dp[i][j][k] < 0) {
                        continue;
                    }
                    dp[i][j][k] += A[h][j];
                    if (j != k) {
                        dp[i][j][k] += A[h][k];
                    }
                    if (h == R-1) {
                        ret = max(dp[i][j][k], ret);
                    }
                }
            }
        }
        return ret;
    }
};
