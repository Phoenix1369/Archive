class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        if (N == 1) {
            return 1;
        }
        int best = 1;
        int cur = 1;
        int prev = -1;
        for (int i = 1; i < N; ++i) {
            if (A[i] < A[i-1]) {
                if (prev != 1) {
                    ++cur;
                } else {
                    cur = 2;
                }
                prev = 1;
            } else if (A[i] == A[i-1]) {
                cur = 1;
                prev = -1;
            } else {
                if (prev != 0) {
                    ++cur;
                } else {
                    cur = 2;
                }
                prev = 0;
            }
            best = max(cur, best);
        }
        return best;
    }
};
