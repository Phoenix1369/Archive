const int MAXN = 305;
int A[MAXN][MAXN];
int M, N;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        N = mat.size();
        M = mat[0].size();
        init();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i+1][j+1] = mat[i][j];
            }
        }
        prefix();
        return solve(threshold);
    }

private:
    void init() {
        for (int i = 0; i < N; ++i) A[i][0] = 0;
        for (int j = 0; j < M; ++j) A[0][j] = 0;
    }
    
    void prefix() {
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
    }
    
    int solve(int threshold) {
        int K = min(N, M);
        for (int k = K; k >= 1; --k) {
            for (int i = k; i <= N; ++i) {
                for (int j = k; j <= M; ++j) {
                    int sum = A[i][j] - A[i-k][j] - A[i][j-k] + A[i-k][j-k];
                    if (sum <= threshold) {
                        return k;
                    }
                }
            }
        }
        return 0;
    }
};

/*
[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]
4
[[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]
1
[[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]]
6
[[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]]
40184
>> 2
>> 0
>> 3
>> 2
*/
