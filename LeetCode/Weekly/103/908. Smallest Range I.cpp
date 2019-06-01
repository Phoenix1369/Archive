#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n = (int)A.size();
        std::sort(ALL(A));
        return std::max(A[n-1]-A[0]-K*2, 0);
    }
};
