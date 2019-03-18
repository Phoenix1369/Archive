#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        multiset<int> B{ALL(A)};
        for (int k = 0; k < K; ++k) {
            int num = *B.begin();
            B.erase(B.begin());
            B.insert(-num);
        }
        return accumulate(ALL(B), 0);
    }
};
