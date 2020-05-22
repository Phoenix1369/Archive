const int MAXN = 305;
int dp[2][MAXN];
int M, N;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        init();
        int ret = 0;
        for (int h = 0; h < N; ++h) {
            int i = (h & 1);
            for (int j = 0; j < M; ++j) {
                if (h && j && matrix[h][j]) {
                    dp[i][j] = min(
                        min(dp[i^1][j], dp[i][j-1]),
                        dp[i^1][j-1]
                    ) + 1;
                } else {
                    dp[i][j] = matrix[h][j];
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }

private:
    void init() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = 0;
            }
        }
    }
};
