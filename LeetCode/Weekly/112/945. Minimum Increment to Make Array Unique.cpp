#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(ALL(A));
        int N = A.size();
        int ret = 0;
        for (int i = 1; i < N; ++i) {
            if (A[i-1] >= A[i]) {
                ret += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return ret;
    }
};
