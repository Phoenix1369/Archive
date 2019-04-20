class Solution {
    vector<int> stk;

public:
    int maxScoreSightseeingPair(vector<int>& A) {
        stk.clear();
        int N = A.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            while ((stk.size() >= 2u) &&
                   (A[stk.end()[-2]] - (i - stk.end()[-2]) >=
                    A[stk.back()] - (i - stk.back()))) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                ret = max(A[stk.back()] + A[i] - (i - stk.back()), ret);
            }
            stk.push_back(i);
        }
        return ret;
    }
};
