class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
