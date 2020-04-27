#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

const int MAXN = 105;
vec<vec<int>> A;
int B[MAXN];
int M, N;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        A = move(mat);
        N = A.size();
        M = A[0].size();
        for (int i = 0; i < N; ++i) {
            dsort(i, 0);
        }
        for (int j = 1; j < M; ++j) {
            dsort(0, j);
        }
        return A;
    }

private:
    void dsort(int row, int col) {
        int k = 0;
        for (k = 0; (row + k < N) && (col + k < M); ++k) {
            B[k] = A[row + k][col + k];
        }
        sort(B, B + k);
        for (k = 0; (row + k < N) && (col + k < M); ++k) {
            A[row + k][col + k] = B[k];
        }
    }
};
