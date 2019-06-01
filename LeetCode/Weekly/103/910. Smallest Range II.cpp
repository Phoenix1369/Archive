#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = (int)A.size();
        std::sort(ALL(A));
        if (A[0]+K >= A[n-1]) {
            return A[n-1]-A[0];
        }
        int ret = A[n-1]-A[0];
        for(int i = 0; i+1 < n; ++i) {
            ret = std::min(std::max(A[n-1]-K, A[i]+K) - std::min(A[0]+K, A[i+1]-K) , ret);
        }
        return ret;
    }
};
