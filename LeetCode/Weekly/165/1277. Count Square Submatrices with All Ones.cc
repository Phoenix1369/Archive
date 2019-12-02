const int MAXN = 305;
int A[MAXN][MAXN]{ };
int M, N;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        init();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i+1][j+1] = matrix[i][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] += A[i-1][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] += A[i][j-1];
            }
        }
        int ret = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int beg = min(i, j);
                for (int k = beg; k >= 1; --k) {
                    int sum = A[i][j] - A[i-k][j] - A[i][j-k] + A[i-k][j-k];
                    if (sum == k*k) {
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }

private:
    void init() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                A[i][j] = 0;
            }
        }
    }
};

/*
[[0,1,1,1],[1,1,1,1],[0,1,1,1]]
[[1,0,1],[1,1,0],[1,1,0]]
>> 15
>> 7
*/
