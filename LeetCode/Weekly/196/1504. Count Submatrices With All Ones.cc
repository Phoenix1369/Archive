vector<int> col;
vector<int> row;
vector<int> sum;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        col.assign(M, 0);
        row.reserve(M);
        sum.reserve(M);
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            row.clear();
            sum.clear();
            for (int j = 0; j < M; ++j) {
                if (mat[i][j] == 0) {
                    col[j] = 0;
                } else {
                    ++col[j];
                }
                while (!row.empty() && (col[row.back()] >= col[j])) {
                    row.pop_back();
                }
                if (!row.empty()) {
                    sum.push_back(sum[row.back()] + col[j] * (j - row.back()));
                } else {
                    sum.push_back(col[j] * (j + 1));
                }
                ret += sum.back();
                row.push_back(j);
            }
        }
        return ret;
    }
};
