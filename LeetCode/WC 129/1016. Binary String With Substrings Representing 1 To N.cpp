const int LOGN = 12;
const int MAXN = 2048;
bitset<MAXN> seen;

class Solution {
public:
    bool queryString(string S, int N) {
        if (N >= MAXN) {
            return false;
        }
        seen.reset();
        const int L = S.size();
        for (int j = 1; j <= LOGN; ++j) {
            int sum = 0;
            int mod = (1<<j) - 1;
            for (int i = 0; i < L; ++i) {
                sum = sum * 2 + (S[i] - '0');
                if (i+1 >= j) {
                    sum &= mod;
                    if (sum <= N) {
                        seen.set(sum);
                    }
                }
            }
        }
        seen.reset(0);
        return (seen.count() == N);
    }
};
