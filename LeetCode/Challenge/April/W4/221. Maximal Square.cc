template <typename T>
using vec = vector<T>;

vec<vec<int>> A;
int M, N;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        N = matrix.size();
        M = matrix[0].size();
        A.assign(N+1, vec<int>(M+1, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] = matrix[i-1][j-1] - '0';
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
        int edge = min(M, N);
        for (int k = edge; k >= 1; --k) {
            int area = k * k;
            for (int i = k; i <= N; ++i) {
                for (int j = k; j <= M; ++j) {
                    if (A[i][j] - A[i-k][j] - A[i][j-k] + A[i-k][j-k] == area) {
                        return area;
                    }
                }
            }
        }
        return 0;
    }
};
