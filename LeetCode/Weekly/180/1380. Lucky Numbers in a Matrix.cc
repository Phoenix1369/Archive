class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> mnr(N, 0);
        for (int i = 0; i < N; ++i) {
            mnr[i] = matrix[i][0];
            for (int j = 0; j < M; ++j) {
                mnr[i] = min(mnr[i], matrix[i][j]);
            }
        }
        vector<int> ret;
        for (int j = 0; j < M; ++j) {
            int mxc = matrix[0][j];
            for (int i = 0; i < N; ++i) {
                mxc = max(mxc, matrix[i][j]);
            }
            for (int i = 0; i < N; ++i) {
                if (mnr[i] == mxc) {
                    ret.push_back(mxc);
                }
            }
        }
        return ret;
    }
};
