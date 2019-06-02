class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        if (N < 3) {
            return false;
        }
        int pos = 1;
        while (pos < N) {
            if (A[pos-1] >= A[pos]) {
                break;
            }
            ++pos;
        }
        if (pos == 1 || pos == N) {
            return false;
        }
        while (pos < N) {
            if (A[pos-1] <= A[pos]) {
                return false;
            }
            ++pos;
        }
        return true;
    }
};
