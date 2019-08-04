const int MAXN = 105;
int A[MAXN][MAXN];
int M, N;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        // Copy
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] = grid[i-1][j-1];
            }
        }

        // Prefix
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] += A[i-1][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 2; j <= M; ++j) {
                A[i][j] += A[i][j-1];
            }
        }

        // Search
        int K = min(M, N);
        for (int k = K; k >= 1; --k) {
            for (int i = k; i <= N; ++i) {
                for (int j = k; j <= M; ++j) {
                    int ca = A[i][j] - A[i][j-1];
                    int cb = A[i-k][j] - A[i-k][j-1];
                    
                    int ra = A[i][j] - A[i-1][j];
                    int rb = A[i][j-k] - A[i-1][j-k];
                    
                    int cc = A[i][j-k+1] - A[i][j-k];
                    int cd = A[i-k][j-k+1] - A[i-k][j-k];
                    
                    int rc = A[i-k+1][j] - A[i-k][j];
                    int rd = A[i-k+1][j-k] - A[i-k][j-k];
                    if ((ca - cb == k) && (ra - rb == k) &&
                        (cc - cd == k) && (rc - rd == k)) {
                        return k*k;
                    }
                }
            }
        }
        return 0;
    }
};
