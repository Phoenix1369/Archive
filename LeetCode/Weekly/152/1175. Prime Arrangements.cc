const int MAXN = 105;
const int MOD = 1e9+7;
int F[MAXN];

class Solution {
public:
    int numPrimeArrangements(int n) {
        init();
        int p = 0;
        for (int i = 2; i <= n; ++i) {
            if (is_prime(i)) ++p;
        }
        return 1LL * F[p] * F[n - p] % MOD;
    }

private:
    void init() {
        F[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            F[i] = 1LL * F[i-1] * i % MOD;
        }
    }
    
    bool is_prime(int k) {
        if (k <= 1) return false;
        if (k == 2) return true;
        if ((k & 1) == 0) return false;
        for (int i = 3; i*i <= k; i += 2) {
            if ((k % i) == 0) {
                return false;
            }
        }
        return true;
    }
};
