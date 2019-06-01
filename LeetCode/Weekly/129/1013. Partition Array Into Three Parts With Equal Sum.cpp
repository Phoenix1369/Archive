#define ALL(x) (x).begin(), (x).end()
const int MOD = 3;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(ALL(A), 0);
        if (sum % MOD) {
            return false;
        }
        sum /= MOD;
        int N = A.size();
        int zero = 0;
        int cur = 0;
        for (int i = 0; i < N; ++i) {
            cur += A[i];
            if (cur == sum) {
                cur = 0;
                ++zero;
            }
        }
        return (cur == 0) && (zero >= MOD);
    }
};
