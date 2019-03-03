typedef long long lld;
const int MAXN = 12;
const int TWON = 1<<MAXN;
lld dp[MAXN][TWON]{ };

class Solution {
    int M, N;
    vector<int> A;

public:
    int numSquarefulPerms(vector<int>& A) {
        N = A.size();
        M = 1<<N;
        this->A = A;
        reset();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) if ((i != j) && is_sqr(i, j)) {
                dp[i][1<<i] = dp[j][1<<j] = 1LL;
            }
        }
        for (int mask = 1; mask < M; ++mask) {
            for (int i = 0; i < N; ++i) if (mask & (1 << i)) {
                for (int j = 0; j < N; ++j) {
                    if (is_sqr(i, j) && !(mask & (1 << j))) {
                        dp[j][mask|(1<<j)] += dp[i][mask];
                    }
                }
            }
        }
        lld ret = 0LL;
        for (int i = 0; i < N; ++i) {
            ret += dp[i][M-1];
        }
        for (int i = 0; i < N; ++i) {
            int dup = 1;
            for (int j = i+1; j < N; ++j) if (A[i] == A[j]) {
                ++dup;
            }
            ret /= dup;
        }
        return ret;
    }

private:
    bool is_sqr(int i, int j) {
        int num = A[i] + A[j];
        int s = sqrt(num);
        return (1LL*s*s == num);
    }

    void reset() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = 0LL;
            }
        }
    }
};
