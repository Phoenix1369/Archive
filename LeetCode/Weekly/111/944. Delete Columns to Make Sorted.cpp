class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N = A.size();
        int M = A[0].size();
        int D = 0;
        for (int j = 0; j < M; ++j) {
            bool sorted = true;
            for (int i = 1; i < N; ++i) {
                if (A[i-1][j] > A[i][j]) {
                    sorted = false;
                }
            }
            if (!sorted) ++D;
        }
        return D;
    }
};
