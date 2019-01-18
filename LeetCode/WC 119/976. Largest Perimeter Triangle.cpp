#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(ALL(A));
        for (int i = (int)A.size()-1; i >= 2; --i) {
            if (A[i] < A[i-2] + A[i-1]) {
                return A[i-2] + A[i-1] + A[i];
            }
        }
        return 0;
    }
};
