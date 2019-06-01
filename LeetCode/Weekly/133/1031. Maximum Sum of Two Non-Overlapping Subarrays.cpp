class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> B = { 0 };
        for (auto& a: A) {
            B.push_back(a + B.back());
        }
        int ret = 0;
        int N = A.size();
        for (int i = 1; i <= N; ++i) {
            // Fix the beginning
            for (int j = 1; j < i; ++j) {
                if ((j+L-1 < i) && (i+M-1 <= N)) {
                    ret = std::max(B[j+L-1] - B[j-1] + B[i+M-1] - B[i-1], ret);
                }
                if ((j+M-1 < i) && (i+L-1 <= N)) {
                    ret = std::max(B[j+M-1] - B[j-1] + B[i+L-1] - B[i-1], ret);
                }
            }
        }
        return ret;
    }
};
