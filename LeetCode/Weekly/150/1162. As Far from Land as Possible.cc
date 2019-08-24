#define ALL(x) (x).begin(), (x).end()
const int MAXK = 4;
const int MAXN = 105;
const int INFN = MAXN*2;
const int LAND = 1;
int memo[MAXN][MAXN][MAXK];

class Solution {
    vector<vector<int>> A;
    int M, N;

public:
    int maxDistance(vector<vector<int>>& grid) {
        A = move(grid);
        N = A.size();
        M = A[0].size();
        bool has[2]{ };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                has[ A[i][j] ] = true;
            }
        }
        if (!has[0] || !has[1]) return -1;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < MAXK; ++k) {
                    memo[i][j][k] = INFN;
                }
            }
        }
        
        top_left(0); // top-left
        
        reverse(ALL(A));
        top_left(1); // bottom-left
        
        for (auto& row: A) reverse(ALL(row));
        top_left(2); // bottom-right
        
        reverse(ALL(A));
        top_left(3); // top-right
        
        for (auto& row: A) reverse(ALL(row));
        // top-left

        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i][j] == LAND) continue;
                int D[MAXK] = {
                    memo[i][j][0],
                    memo[N-i-1][j][1],
                    memo[N-i-1][M-j-1][2],
                    memo[i][N-j-1][3]
                };
                ret = max(*min_element(D, D + MAXK), ret);
            }
        }
        return ret;
    }

private:
    void top_left(int k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i][j] == LAND) {
                    memo[i][j][k] = 0;
                    continue;
                }

                int d = INFN;
                if (i) d = min(memo[i-1][j][k] + 1, d);
                if (j) d = min(memo[i][j-1][k] + 1, d);
                memo[i][j][k] = d;
            }
        }
    }
};
