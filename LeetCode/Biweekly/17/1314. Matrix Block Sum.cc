const int MAXN = 105;
int A[MAXN][MAXN];
int M, N;

template <typename T>
using vec = vector<T>;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        N = mat.size();
        M = mat[0].size();
        // Init
        for (int i = 0; i <= N; ++i) A[i][0] = 0;
        for (int j = 0; j <= M; ++j) A[0][j] = 0;
        // Copy
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i+1][j+1] = mat[i][j];
            }
        }
        // Prefix
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                A[i][j] += A[i-1][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] += A[i][j-1];
            }
        }
        // Solve
        vec<vec<int>> ret;
        for (int i = 1; i <= N; ++i) {
            ret.emplace_back();
            for (int j = 1; j <= M; ++j) {
                int ri = min(i + K, N);
                int rj = min(j + K, M);
                int li = max(i - K - 1, 0);
                int lj = max(j - K - 1, 0);
                int val = A[ri][rj] - A[li][rj] - A[ri][lj] + A[li][lj];
                ret.back().push_back(val);
            }
        }
        return ret;
    }
};
