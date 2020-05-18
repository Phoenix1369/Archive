class Solution {
public:
    int twoSumLessThanK(vector<int> A, int K) {
        int N = A.size();
        int S = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                int sum = A[i] + A[j];
                if (sum < K) {
                    S = max(sum, S);
                }
            }
        }
        return S;
    }
};
