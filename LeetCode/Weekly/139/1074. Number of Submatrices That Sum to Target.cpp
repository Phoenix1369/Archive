const int MAXN = 305;
int A[MAXN][MAXN];
unordered_map<int,int> cnt[MAXN];

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        for (int i = 0; i <= N; ++i) {
            A[i][0] = 0;
        }
        for (int j = 0; j <= M; ++j) {
            A[0][j] = 0;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] = matrix[i-1][j-1];
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
            for (int a = 0; a < i; ++a) {
                cnt[a].clear();
                cnt[a].reserve(M + 1);
            }
            for (int j = 0; j <= M; ++j) {
                if (j >= 1) {
                    for (int a = 0; a < i; ++a) {
                        int val = A[i][j] - target - A[a][j];
                        if (cnt[a].count(val)) {
                            ret += cnt[a].at(val);
                        }
                    }
                }
                for (int a = 0, b = j; a < i; ++a) {
                    ++cnt[a][A[i][b] - A[a][b]];
                }
            }
        }
        return ret;
    }
};

// target = A(a+1, b+1, i, j) = A(i, j) - A(i, b) - A(a, j) + A(a, b)
// A(i, j) - target - A(a, j) = A(i, b) - A(a, b)

