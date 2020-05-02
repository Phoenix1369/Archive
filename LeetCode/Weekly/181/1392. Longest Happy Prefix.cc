const int BASE = 10;
const int HASH = 131;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int A[MAXN];
int P[MAXN];

class Solution {
public:
    string longestPrefix(string s) {
        int N = s.size();
        A[0] = 0;
        P[0] = 1;
        for (int i = 1; i <= N; ++i) {
            A[i] = (1LL * HASH * A[i-1] % MOD + s[i-1]) % MOD;
            P[i] =  1LL * HASH * P[i-1] % MOD;
        }
        int best = 0;
        for (int i = 1; i < N; ++i) {
            int prev = 1LL * A[N-i] * P[i] % MOD;
            int suffix = (A[N] - prev + MOD) % MOD;
            if (A[i] == suffix) {
                best = i;
            }
        }
        return s.substr(N-best);
    }
};
