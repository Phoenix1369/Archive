#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int> S;
        int n = A.size();

        int ret = 0;
        for (int i = n-1; i >= 0; --i) {
            auto j = lower_bound(ALL(S), A[i], [&A](const int& pos, const int& value) {
                return A[pos] < value;
            });
            if (j != S.end()) {
                ret = max(*j - i, ret);
            }
            if (S.empty() || (A[i] > A[S.back()])) {
                S.push_back(i);
            }
        }
        return ret;
    }
};
