const int MAXA = 1005;

class Solution {
    vector<int> A;
    int N;

public:
    int movesToMakeZigzag(vector<int>& nums) {
        A = move(nums);
        N = A.size();
        int res[2] = {0, 0};
        for (int i = 0; i < N; ++i) {
            int m = MAXA;
            if (i > 0) m = min(A[i-1], m);
            if (i+1 < N) m = min(A[i+1], m);
            if (A[i] >= m) {
                res[i & 1] += A[i] - m + 1;
            }
        }
        return *min_element(res, res+2);
    }
};
