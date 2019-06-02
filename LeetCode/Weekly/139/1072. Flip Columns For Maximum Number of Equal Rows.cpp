class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            // Fix [i] to be the solution.
            int cnt = 1;
            for (int k = 0; k < N; ++k) if (k != i) {
                int zero = 0;
                for (int j = 0; j < M; ++j) {
                    if (matrix[i][j] == matrix[k][j]) {
                        ++zero;
                    }
                }
                if (!zero || (zero == M)) {
                    ++cnt;
                }
            }
            ret = max(cnt, ret);
        }
        return ret;
    }
};

